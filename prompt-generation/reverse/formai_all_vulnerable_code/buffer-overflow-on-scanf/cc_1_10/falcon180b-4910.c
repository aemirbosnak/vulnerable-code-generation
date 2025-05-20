//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000 // Maximum number of elements in the array
#define MAX_BUCKET_SIZE 100 // Maximum number of elements in a bucket
#define RANGE 1000000 // Range of the random numbers

// Function to generate random numbers between 0 and RANGE-1
void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }
}

// Function to sort the array using bucket sort
void bucketSort(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int bucketSize = range / MAX_BUCKET_SIZE;
    int numBuckets = range / bucketSize + 1;
    int* buckets = (int*)malloc(numBuckets * sizeof(int));

    // Fill the buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        buckets[bucketIndex]++;
    }

    // Sort the buckets
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        while (buckets[i] > 0) {
            arr[index++] = min + i * bucketSize;
            buckets[i]--;
        }
    }
    free(buckets);
}

// Function to print the sorted array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(size * sizeof(int));

    // Generate random numbers between 0 and RANGE-1
    generateRandomArray(arr, size);

    // Sort the array using bucket sort
    bucketSort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    free(arr);
    return 0;
}