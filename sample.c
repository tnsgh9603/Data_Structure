#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

typedef struct {
	int key;
	char value[10000];
}data_node; //레코드

//합병정렬

void merge(data_node list[], int left, int mid, int right, data_node sorted[]) //기존 합병 정렬 
{
	//함수 구현
}
void merge_sort(int list[], int left, int right, int sorted[]) //기존 합병 정렬 
{
	//함수 구현
}

void merge_addr(data_node* list[], int left, int mid, int right, data_node* sorted[]) //변경 합병 정렬 
{
	//함수 구현
}
void merge_sort_addr(data_node list[], int left, int right, data_node sorted[]) //변경 합병 정렬 
{
	//함수 구현
}

void main()
{
	int i, n, size, sel_data, digit = 0;
	double  merge_result, merge_result2;

	printf("배열의 크기를 입력하세요 : ");  //정렬 크기 선택
	scanf_s("%d", &size);
	srand(time(NULL));

	data_node* origin_list = (data_node*)malloc(sizeof(data_node) * size);//원본 데이터
	data_node* merge_list = (data_node*)malloc(sizeof(data_node) * size);//합병정렬(기존)
	data_node* sorted_list = (data_node*)malloc(sizeof(data_node) * size);//정렬될 배열(기존)
	data_node** merge_list_addr = (data_node**)malloc(sizeof(data_node*) * size);//합병정렬(주소값)
	data_node** sorted_list_addr = (data_node**)malloc(sizeof(data_node*) * size);//정렬될 배열(주소값)

	n = size;

	printf("데이터 선택 (1.랜덤 2.정렬된 상태 3.역순으로 정렬된 상태) : ");
	scanf_s("%d", &sel_data);
	for (i = 0; i < n; i++)
	{
		if (sel_data == 1) {
			origin_list[i].key = n * rand() / (double)RAND_MAX; //랜덤

		}
		else if (sel_data == 2) {
			origin_list[i].key = i; //정렬된 상태
		}
		else if (sel_data == 3) {
			origin_list[i].key = n - i; //역순
		}
		else break;
		merge_list[i].key = origin_list[i].key; //선택된 데이터 복사
		for (int j = 0; j < 10000; j++) {
			merge_list[i].value[j] = (char)(i % 10);  // value값에 0~9사이의 값 10000개를 배열에 추가
		}
		data_node* value = creat_node(merge_list[i]); // key와 value를 저장할 data_node를 생성하고 주소 값 반환
		merge_list_addr[i] = value; // 주소값을 리스트에 저장
	}

	clock_t start, finish;

	start = clock();
	merge_sort(merge_list, 0, n - 1, sorted_list); // 합병정렬(기존) 호출 
	finish = clock();
	merge_result = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	merge_sort_addr(merge_list_addr, 0, n - 1, sorted_list_addr); //합병정렬(주소값) 호출
	finish = clock();
	merge_result2 = (double)(finish - start) / CLOCKS_PER_SEC;


	for (i = 0; i < n; i++) {
		printf("%d,\t\t%d\t%d%,\t\t%d\t%d\t\n", origin_list[i].key, merge_list[i].key, merge_list[i].value[0], merge_list_addr[i]->key, merge_list_addr[i]->value[0]);
		// value값은 첫번째 데이터만 출력(10000개를 출력하면 볼 수가 없어요..)
	}
	printf("\n key \t\tkey  value\t\tkey  value\n\n");
	printf("원본\t\t합병정렬(기존)\t\t합병정렬(주소값)\n");
	printf("\n합병정렬(기존) 시간 : %f 초\t", merge_result);
	printf("\t합병정렬(주소값) 시간 : %f 초\n", merge_result2);
	getch();
}
