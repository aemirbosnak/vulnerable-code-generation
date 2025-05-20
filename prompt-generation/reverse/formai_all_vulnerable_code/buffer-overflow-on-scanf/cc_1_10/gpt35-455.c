//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int i, j;
    int maxVal = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int bucketCount = maxVal / 5 + 1;
    int** buckets = (int**) calloc(bucketCount, sizeof(int*));
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (int*) calloc(5, sizeof(int));
    }

    int* bucketIndex = (int*) calloc(bucketCount, sizeof(int));
    for (i = 0; i < n; i++) {
        int bucket = arr[i] / 5;
        buckets[bucket][bucketIndex[bucket]] = arr[i];
        bucketIndex[bucket]++;
    }

    for (i = 0; i < bucketCount; i++) {
        int bucketSize = bucketIndex[i];
        for (j = 1; j < bucketSize; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        int bucketSize = bucketIndex[i];
        for (j = 0; j < bucketSize; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

    for (i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }

    free(buckets);
    free(bucketIndex);
}

int main() {
    int i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int* arr = (int*) calloc(n, sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}