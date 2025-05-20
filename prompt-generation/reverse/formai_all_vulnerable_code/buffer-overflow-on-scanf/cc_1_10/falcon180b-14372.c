//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE 1000

void bucketSort(int* arr, int size) {
    int i, j, k, max, min, range, bucketSize;
    int* buckets[MAX_SIZE];

    max = arr[0];
    min = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;
    bucketSize = range / size;

    for (i = 0; i < size; i++) {
        buckets[i] = (int*) malloc(sizeof(int) * bucketSize);
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < bucketSize; j++) {
            buckets[i][j] = 0;
        }
    }

    for (i = 0; i < size; i++) {
        k = (arr[i] - min) / bucketSize;
        buckets[k][(arr[i] - min) % bucketSize]++;
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < bucketSize; j++) {
            arr[i * bucketSize + j] = buckets[i][j];
        }
    }

    for (i = 0; i < size; i++) {
        free(buckets[i]);
    }
}

int main() {
    int i, n;
    int* arr;
    clock_t start, end;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int*) malloc(sizeof(int) * n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    bucketSort(arr, n);
    end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    return 0;
}