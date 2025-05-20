//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

int main() {
    int *arr;
    int num;
    int i, j;
    int sum = 0;
    clock_t start, end;
    double cpu_time_used;

    srand(time(0));
    arr = (int*)malloc(MAX_NUM * sizeof(int));

    for (i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted array:\n");
    for (i = 0; i < MAX_NUM; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
    for (i = 0; i < MAX_NUM - 1; i++) {
        for (j = 0; j < MAX_NUM - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                num = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = num;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < MAX_NUM; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %lf seconds\n", cpu_time_used);

    free(arr);
    return 0;
}