//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void bucketSort(int arr[], int n) {
    int i, j, k;
    int count[MAX_VALUE];

    for (i = 0; i < MAX_VALUE; ++i) {
        count[i] = 0;
    }

    for (i = 0; i < n; ++i) {
        ++count[arr[i]];
    }

    for (i = 0, j = 0; j < MAX_VALUE; ++j) {
        for (k = count[j]; k > 0; --k) {
            arr[i++] = j;
        }
    }
}

int main() {
    int i, n, arr[MAX_VALUE];

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Array after bucket sort: ");
    printArray(arr, n);

    return 0;
}