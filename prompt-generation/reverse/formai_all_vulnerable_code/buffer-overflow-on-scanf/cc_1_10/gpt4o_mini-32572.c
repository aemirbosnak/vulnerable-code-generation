//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Helper function to sort a bucket using insertion sort
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create buckets
    float **buckets = malloc(BUCKET_COUNT * sizeof(float*));
    int *bucketSizes = calloc(BUCKET_COUNT, sizeof(int)); // To keep track of sizes

    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = malloc(n * sizeof(float)); // Allocating max possible size
    }

    // Distributing elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_COUNT * arr[i]);
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1; // Push to the last bucket
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort each bucket and concatenate results
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Freeing allocated memory
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float *arr = malloc(n * sizeof(float));
    printf("Enter %d floating point numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    // Free allocated array
    free(arr);
    return 0;
}