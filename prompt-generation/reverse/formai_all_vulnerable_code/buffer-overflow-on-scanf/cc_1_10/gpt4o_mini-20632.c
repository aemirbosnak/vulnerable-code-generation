//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10 // Number of buckets

// Function to perform Insertion Sort on a bucket
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

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    // Step 1: Creating buckets
    float **buckets = (float **)malloc(BUCKET_COUNT * sizeof(float *));
    int *bucketCount = (int *)malloc(BUCKET_COUNT * sizeof(int));
    
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketCount[i] = 0; // Initialize bucket counts
    }
    
    // Step 2: Distributing input array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(BUCKET_COUNT * arr[i]); // Calculate bucket index
        if (index >= BUCKET_COUNT) index = BUCKET_COUNT - 1; // Handle edge case
        buckets[index][bucketCount[index]++] = arr[i]; // Add value to bucket
    }

    // Step 3: Sorting each bucket and concatenating results
    int idx = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketCount[i] > 0) {
            insertionSort(buckets[i], bucketCount[i]); // Sort bucket
            for (int j = 0; j < bucketCount[i]; j++) {
                arr[idx++] = buckets[i][j]; // Concatenate sorted buckets
            }
        }
    }

    // Free allocated memory for buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCount);
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Example usage of Bucket Sort
    int n;
    
    printf("How many elements do you want to sort? ");
    scanf("%d", &n);

    float *arr = (float *)malloc(n * sizeof(float));
    
    printf("Enter %d floating-point numbers (0 to 1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        // Ensuring the input values are in the range [0, 1)
        if (arr[i] < 0.0 || arr[i] >= 1.0) {
            printf("Number out of range. Please enter numbers in [0, 1).\n");
            i--; // decrement i to repeat the input for this index
        }
    }

    printf("Unsorted Array:\n");
    printArray(arr, n);

    // Performing Bucket Sort
    bucketSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    // Free the allocated memory for the float array
    free(arr);
    return 0;
}