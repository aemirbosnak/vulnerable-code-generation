//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, k, max, min;
    int bucket[MAX_SIZE];

    // Find minimum and maximum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of the array
    int range = max - min + 1;

    // Create buckets and distribute elements
    for (i = 0; i < n; i++) {
        k = arr[i] - min;
        bucket[k] += 1;
    }

    for (i = 0; i < n; i++) {
        j = bucket[arr[i] - min] - 1;
        bucket[arr[i] - min] -= 1;
        arr[i] = min + j * range;
    }
}

int main() {
    int arr[] = { 5, 3, 8, 4, 6, 9, 2, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}