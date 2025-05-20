//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int low, int high) {
    int i, j, pivot;

    if (low < high) {
        pivot = (low + high) / 2;
        i = low;
        j = high;

        while (i < j) {
            while (arr[i] < arr[pivot]) i++;
            while (arr[j] > arr[pivot]) j--;

            if (i < j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }

        sort(arr, low, i - 1);
        sort(arr, j + 1, high);
    }
}

int main() {
    int arr[MAX_LENGTH] = {5, 2, 8, 3, 1, 6, 4};
    int i, n = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;
    double time_taken;

    printf("Before Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
    sort(arr, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("After Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time Taken: %f seconds\n", time_taken);

    return 0;
}