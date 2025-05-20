//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum element in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int bucketSize = max / n;
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(bucketSize * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] <= max / (i + 1) * (i + 1) && arr[j] >= max / (i + 1) * i) {
                int bucketIndex = arr[j] / bucketSize;
                int indexInBucket = 0;
                while (indexInBucket < bucketSize && buckets[bucketIndex][indexInBucket]!= -1) {
                    indexInBucket++;
                }
                buckets[bucketIndex][indexInBucket] = arr[j];
            }
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 10, 5, 7, 2, 8, 4, 6, 1, 3, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
    return 0;
}