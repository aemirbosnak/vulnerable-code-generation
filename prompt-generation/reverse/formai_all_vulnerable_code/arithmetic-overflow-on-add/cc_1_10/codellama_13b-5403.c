//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
// Bucket Sort Implementation in C

#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    // Initialize buckets
    int bucketCount = 10;
    int buckets[bucketCount][n];
    int bucketSizes[bucketCount];

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * bucketCount) / (arr[n - 1] + 1);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort buckets
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            for (int k = j + 1; k < bucketSizes[i]; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }

    // Merge buckets
    int arrIndex = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[arrIndex++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}