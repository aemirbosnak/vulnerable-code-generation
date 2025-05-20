//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
// Bucket sort implementation in a curious style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate a random array
int* generateRandomArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Function to bucket sort the array
void bucketSort(int arr[], int size) {
    int i, j;
    int min = arr[0], max = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int bucketCount = max - min + 1;
    int* buckets = (int*)malloc(bucketCount * sizeof(int));
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = 0;
    }

    for (i = 0; i < size; i++) {
        buckets[arr[i] - min]++;
    }

    int outIndex = 0;
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < buckets[i]; j++) {
            arr[outIndex++] = i + min;
        }
    }

    free(buckets);
}

// Driver code
int main() {
    int size = 10;
    int* arr = generateRandomArray(size);
    printf("Unsorted array: ");
    printArray(arr, size);
    bucketSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}