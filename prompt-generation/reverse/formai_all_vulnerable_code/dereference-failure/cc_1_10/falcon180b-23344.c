//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate random number between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array into buckets
void partition(int arr[], int n, int bucketSize, int* bucketCounts) {
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        bucketCounts[bucketIndex]++;
    }
}

// Function to sort the array using bucket sort
void bucketSort(int arr[], int n, int bucketSize) {
    int* bucketCounts = (int*)malloc(bucketSize * sizeof(int));
    partition(arr, n, bucketSize, bucketCounts);

    int* sortedArray = (int*)malloc(n * sizeof(int));
    int sortedIndex = 0;

    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            sortedArray[sortedIndex++] = i * bucketSize + j;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sortedArray[i];
    }

    free(bucketCounts);
    free(sortedArray);
}

// Function to generate an array of random integers
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = randInt(1, MAX_SIZE);
    }
}

int main() {
    int n = randInt(1, MAX_SIZE);
    int arr[n];

    generateArray(arr, n);

    int bucketSize = randInt(1, MAX_SIZE);
    printf("Bucket size: %d\n", bucketSize);

    bucketSort(arr, n, bucketSize);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}