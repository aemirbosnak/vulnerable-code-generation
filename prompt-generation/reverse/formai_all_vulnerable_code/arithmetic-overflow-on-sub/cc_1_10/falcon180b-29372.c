//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 1000000

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
    int i, n, *arr;
    double start_time, end_time, elapsed_time;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start_time = clock();
    bubble_sort(arr, n);
    end_time = clock();

    elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    free(arr);
    return 0;
}