//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, n, *arr;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    arr = (int*)malloc(n*sizeof(int));

    if (arr == NULL) {
        printf("Memory error!\n");
        exit(0);
    }

    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Sorting array...\n");
    start = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %lf seconds\n", cpu_time_used);

    free(arr);
    return 0;
}