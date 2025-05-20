//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Step 1: Create buckets
    float **buckets = malloc(BUCKET_SIZE * sizeof(float*));
    int *bucketCount = malloc(BUCKET_SIZE * sizeof(int));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = malloc(n * sizeof(float));
        bucketCount[i] = 0;
    }

    // Step 2: Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(BUCKET_SIZE * arr[i]);
        if (index >= BUCKET_SIZE) {
            index = BUCKET_SIZE - 1; // Handle edge case
        }
        buckets[index][bucketCount[index]++] = arr[i];
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (bucketCount[i] > 0) {
            // Sort each bucket using simple insertion sort
            for (int j = 1; j < bucketCount[i]; j++) {
                float key = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
        }
    }

    // Step 4: Merge sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Clean up
    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCount);
}

// Function to generate random floats
void generateRandomFloats(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (float)rand() / RAND_MAX; // Generates float between 0.0 and 1.0
    }
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    int n;

    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    // Dynamically allocate an array to hold the random floats
    float *arr = malloc(n * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate random float values
    generateRandomFloats(arr, n);

    printf("Unsorted array:\n");
    printArray(arr, n);

    // Apply Bucket Sort
    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    // Clean up
    free(arr);

    return 0;
}