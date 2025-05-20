//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int arr[], int n) {
    int i, j, max, min;
    int *bucket[10];

    for (i = 0; i < 10; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

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

    int range = max - min + 1;
    int bucketSize = range / 10;

    for (i = 0; i < n; i++) {
        j = arr[i] / bucketSize;
        bucket[j] = (int *)realloc(bucket[j], (j + 1) * sizeof(int));
        bucket[j][j] = arr[i];
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[arr[i] / bucketSize][arr[i] % bucketSize];
    }

    for (i = 0; i < 10; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}