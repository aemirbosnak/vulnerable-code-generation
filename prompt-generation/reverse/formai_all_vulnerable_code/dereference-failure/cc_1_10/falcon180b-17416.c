//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// function to find the maximum element in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// function to perform the bucket sort
void bucketSort(int arr[], int size) {
    int max = findMax(arr, size);

    // create buckets
    int bucketSize = max / 10;
    int numBuckets = max / bucketSize + 1;
    int *buckets[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (int *)malloc(bucketSize * sizeof(int));
    }

    // put elements in buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex][arr[i] % bucketSize] = arr[i];
    }

    // sort each bucket
    for (int i = 0; i < numBuckets; i++) {
        int j = 0;
        while (j < bucketSize) {
            if (buckets[i][j]!= 0) {
                arr[j] = buckets[i][j];
                j++;
            } else {
                j++;
            }
        }
    }
}

// function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function
int main() {
    int arr[] = { 5, 3, 2, 8, 1, 6, 7, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // print the unsorted array
    printf("Unsorted Array:\n");
    printArray(arr, size);

    // perform the bucket sort
    bucketSort(arr, size);

    // print the sorted array
    printf("Sorted Array:\n");
    printArray(arr, size);

    return 0;
}