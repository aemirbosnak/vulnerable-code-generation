//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int max_val = arr[0];
    int min_val = arr[0];
    int range;
    int i, j;

    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    range = max_val - min_val + 1;

    int *buckets = (int *)malloc(range * sizeof(int));

    for (i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val) / (MAX_SIZE / range);
        buckets[j]++;
    }

    for (i = 0; i < range; i++) {
        for (j = 0; j < buckets[i]; j++) {
            printf("%d ", i * MAX_SIZE / range + j * MAX_SIZE / buckets[i]);
        }
    }
}

int main() {
    int arr[] = { 5, 3, 8, 4, 2, 7, 1, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}