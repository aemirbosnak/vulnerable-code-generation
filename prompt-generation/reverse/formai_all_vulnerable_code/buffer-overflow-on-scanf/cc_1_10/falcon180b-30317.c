//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
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
    int max = findMax(arr, n);
    int numBuckets = max / 10 + 1;
    int *buckets[numBuckets];

    // Initialize buckets
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (int *)malloc(sizeof(int));
        *(buckets[i]) = 0;
    }

    // Put elements in respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / 10;
        *(buckets[bucketIndex]) = *(buckets[bucketIndex]) + 1;
    }

    // Concatenate buckets
    int j = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int k = 0; k < *(buckets[i]); k++) {
            arr[j++] = i * 10 + k;
        }
    }
}

// Function to generate random array
void generateArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    generateArray(arr, n);

    printf("Unsorted array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}