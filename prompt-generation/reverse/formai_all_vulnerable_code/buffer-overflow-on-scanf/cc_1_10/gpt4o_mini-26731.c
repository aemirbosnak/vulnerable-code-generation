//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100
#define BUCKET_COUNT 10

// Function to initialize the buckets
void initializeBuckets(int buckets[BUCKET_COUNT][MAX_NUMBERS], int bucketSize[BUCKET_COUNT]) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        bucketSize[i] = 0; // Start with empty buckets
    }
}

// Function to perform the bucket sort
void bucketSort(int* array, int size) {
    if (size <= 0) return; // No need to sort if size is 0 or less

    // Create array of buckets
    int buckets[BUCKET_COUNT][MAX_NUMBERS];
    int bucketSize[BUCKET_COUNT];
    initializeBuckets(buckets, bucketSize);

    // Determine the range of values
    int maxElement = array[0];
    int minElement = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > maxElement) maxElement = array[i];
        if (array[i] < minElement) minElement = array[i];
    }

    float range = (float)(maxElement - minElement) / BUCKET_COUNT;

    // Distributing the elements into buckets
    for (int i = 0; i < size; i++) {
        int idx = (int)((array[i] - minElement) / range);
        if (idx >= BUCKET_COUNT) {
            idx = BUCKET_COUNT - 1; // Place them in the last bucket
        }
        buckets[idx][bucketSize[idx]++] = array[i]; // Insert into the appropriate bucket
    }

    // Sort individual buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Simple insertion sort for each bucket
        for (int j = 1; j < bucketSize[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Collecting the sorted elements
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            array[index++] = buckets[i][j]; // Put back the sorted elements into the original array
        }
    }
}

// Function to display the array
void displayArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// The main function where it all starts
int main() {
    int numbers[MAX_NUMBERS];
    int count;

    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &count);
    
    if (count > MAX_NUMBERS) {
        fprintf(stderr, "Error: Maximum limit exceeded!\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d integers:\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Before sorting:\n");
    displayArray(numbers, count);

    bucketSort(numbers, count);

    printf("After sorting:\n");
    displayArray(numbers, count);

    return EXIT_SUCCESS;
}