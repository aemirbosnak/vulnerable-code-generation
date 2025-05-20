//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_NUM];
    int n, i;
    double start_time, end_time;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_NUM;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    start_time = clock();
    bubble_sort(arr, n);
    end_time = clock();

    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %.6f seconds\n", (end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}