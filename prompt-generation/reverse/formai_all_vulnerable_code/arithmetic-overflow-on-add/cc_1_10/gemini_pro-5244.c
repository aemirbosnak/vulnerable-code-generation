//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void BucketSort(int* arr, int n) {
    int max = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int bucketSize = max / n;
    int** buckets = (int**)malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(sizeof(int) * bucketSize);
    }

    int* count = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex][count[bucketIndex]++] = arr[i];
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int j;
        for (j = 0; j < count[bucketIndex]; j++) {
            printf("%d ", buckets[bucketIndex][j]);
        }
    }

    for (i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(count);
}

int main() {
    int arr[] = {8, 13, 15, 10, 4, 2, 17, 6, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    BucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}