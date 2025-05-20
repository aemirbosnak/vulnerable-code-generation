//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 1000
#define BUCKET_COUNT 10

// Function to create an array of buckets
void initializeBuckets(int buckets[BUCKET_COUNT][MAX_VALUE], int sizes[BUCKET_COUNT]) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        sizes[i] = 0;
    }
}

// Function to find the correct bucket for a given value
int getBucketIndex(int value) {
    return value * BUCKET_COUNT / (MAX_VALUE + 1);
}

// Function to sort individual buckets using insertion sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create buckets
    int buckets[BUCKET_COUNT][MAX_VALUE];
    int sizes[BUCKET_COUNT];
    initializeBuckets(buckets, sizes);

    // Distribute the input values into buckets
    for (int i = 0; i < n; i++) {
        int index = getBucketIndex(arr[i]);
        buckets[index][sizes[index]] = arr[i];
        sizes[index]++;
    }

    // Sort individual buckets and gather results
    int sortedIndex = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (sizes[i] > 0) {
            insertionSort(buckets[i], sizes[i]);
            for (int j = 0; j < sizes[i]; j++) {
                arr[sortedIndex++] = buckets[i][j];
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate random numbers
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (MAX_VALUE + 1);
    }
}

// Main function to execute the program
int main() {
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of elements must be greater than 0. Exiting...\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    
    generateRandomArray(arr, n);
    
    printf("Unsorted array:\n");
    printArray(arr, n);
    
    // Start the bucket sort
    bucketSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    // Clean up
    free(arr);
    
    return 0;
}