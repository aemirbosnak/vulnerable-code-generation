//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Function to perform insertion sort on each bucket
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
    if (n <= 0) return;

    // Step 1: Create buckets
    int bucketCount = (int)(n / BUCKET_SIZE) + 1;
    float **buckets = malloc(bucketCount * sizeof(float *));
    int *bucketSizes = calloc(bucketCount, sizeof(int));
    
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = malloc(BUCKET_SIZE * sizeof(float));
    }

    // Step 2: Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * bucketCount);
        if (bucketIndex >= bucketCount) bucketIndex = bucketCount - 1; // Handle edge case
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Step 4: Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Step 5: Free allocated memory
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print an array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function for testing the bucket sort
int main() {
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    
    float *arr = malloc(n * sizeof(float));
    printf("Enter the elements (0.0 to 1.0):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}