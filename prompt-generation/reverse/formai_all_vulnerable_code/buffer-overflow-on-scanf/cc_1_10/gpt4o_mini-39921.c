//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100
#define RANGE 1000
#define BUCKET_COUNT 10

// Function to initialize buckets
void initializeBuckets(int **buckets) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (int *)malloc(MAX_NUMBERS * sizeof(int));
    }
}

// Function to free allocated buckets
void freeBuckets(int **buckets) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
}

// Function to perform the bucket sort
void bucketSort(int arr[], int size) {
    // Create an array of buckets
    int **buckets = (int **)malloc(BUCKET_COUNT * sizeof(int *));
    initializeBuckets(buckets);
    
    // Initialize counts of each bucket
    int bucketCount[BUCKET_COUNT] = {0};

    // Assign elements to their respective buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] * BUCKET_COUNT / RANGE;
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1; // Handle edge case
        }
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
    }

    // Sort each bucket and merge
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Sorting each bucket using insertion sort
        for (int j = 1; j < bucketCount[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
        
        // Copy sorted bucket to original array
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free the allocated buckets
    freeBuckets(buckets);
    free(buckets);
}

// Function to display array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE; // Generates number from 0 to RANGE-1
    }
}

// Main function
int main() {
    int arr[MAX_NUMBERS];
    int size;

    // Prompt user for the size of the array
    printf("Enter the number of elements to sort (max %d): ", MAX_NUMBERS);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_NUMBERS) {
        printf("Invalid size! Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return -1;
    }

    // Generate random numbers
    generateRandomNumbers(arr, size);

    printf("Original array:\n");
    displayArray(arr, size);

    // Perform bucket sort
    bucketSort(arr, size);

    printf("Sorted array:\n");
    displayArray(arr, size);

    return 0;
}