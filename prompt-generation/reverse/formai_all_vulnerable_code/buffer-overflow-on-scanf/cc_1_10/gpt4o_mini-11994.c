//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BUCKETS 10 // Number of buckets to use

// Function to create and initialize buckets
void initializeBuckets(int **buckets, int bucketSizes[], int n) {
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * MAX_BUCKETS);
        bucketSizes[i] = 0;
    }
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    int **buckets = (int **)malloc(sizeof(int *) * MAX_BUCKETS);
    int bucketSizes[MAX_BUCKETS] = {0};

    // Initialize buckets
    initializeBuckets(buckets, bucketSizes, MAX_BUCKETS);
    
    // Place each number in a corresponding bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * MAX_BUCKETS); // Determining the bucket index
        if (bucketIndex >= MAX_BUCKETS) {
            bucketIndex = MAX_BUCKETS - 1; // Edge case for max value
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i]; // Fill the bucket
    }

    // Sort individual buckets using a simple sort method (Insertion Sort)
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (int j = 1; j < bucketSizes[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k]; // Shift element
                k--;
            }
            buckets[i][k + 1] = key; // Place the key in its sorted position
        }
    }

    // Gather sorted elements back into original array
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j]; // Copy from bucket back to array
        }
    }

    // Free allocated memory
    for (int i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Main function to execute the program
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    float *arr = (float *)malloc(sizeof(float) * n);
    printf("Enter the elements (in the range [0, 1]):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    // Perform bucket sort
    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    // Free the allocated memory for arr
    free(arr);

    return 0;
}