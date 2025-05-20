//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100 // Maximum value in the array, which sets the range.

void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    // Create an array of buckets
    int bucketCount = MAX_VALUE / 10; // Setting 10 as bucket size for simplicity
    float** buckets = malloc(bucketCount * sizeof(float*));
    int* bucketSizes = calloc(bucketCount, sizeof(int));

    // Initialize buckets
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = malloc(n * sizeof(float));
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] / 10); // Determine bucket index
        if (bucketIndex >= bucketCount) {
            bucketIndex = bucketCount - 1; // Overflow case
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 1; j < bucketSizes[i]; j++) {
            float temp = buckets[i][j];
            int k = j - 1;

            // Insertion sort
            while (k >= 0 && buckets[i][k] > temp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }

    // Concatenate sorted buckets into output array
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free memory
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Random float generator
void generateRandomFloatArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (float)(rand() % MAX_VALUE);
    }
}

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    float* arr = malloc(n * sizeof(float));

    generateRandomFloatArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}