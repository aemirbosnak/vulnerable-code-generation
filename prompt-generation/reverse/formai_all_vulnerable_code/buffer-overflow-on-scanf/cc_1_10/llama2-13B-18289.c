//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100
#define SWAP_THRESHOLD 10

void swap_array(int *arr, int low, int high) {
    int i, j, temp;

    if (low < high) {
        for (i = low + 1; i <= high; i++) {
            temp = arr[i];
            for (j = low; j < i - 1; j++) {
                if (arr[j] > temp) {
                    arr[j] = temp;
                }
            }
        }
    }
}

int partition_array(int *arr, int low, int high) {
    int pivot = arr[low];
    int i, j;

    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            j = i;
            while (j > low && arr[j - 1] > pivot) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = pivot;
        }
    }

    swap_array(arr, low, high);
    return low;
}

int main() {
    int arr[MAX_ARRAY_SIZE], n, i, j;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The unsorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
    for (i = 0; i < n - 1; i++) {
        partition_array(arr, i, n - 1);
    }
    end = clock();

    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}