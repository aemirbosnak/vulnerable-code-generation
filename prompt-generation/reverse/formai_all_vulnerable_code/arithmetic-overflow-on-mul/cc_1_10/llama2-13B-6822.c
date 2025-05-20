//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ARRAY_SIZE 1000
#define SWAP_THRESHOLD 50

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int low, int high) {
    int i, j, pivot;

    if (low < high) {
        pivot = partition(arr, low, high);
        sort(arr, low, pivot - 1);
        sort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] >= pivot) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return i;
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int n = 100;
    int i;

    // Generate random array
    for (i = 0; i < n; i++) {
        arr[i] = (int) (1000 * rand() / RAND_MAX);
    }

    // Check for swap threshold
    if (n < SWAP_THRESHOLD) {
        printf("Array is already sorted\n");
        return 0;
    }

    sort(arr, 0, n - 1);

    // Print sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}