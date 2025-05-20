//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1.0 // Define the maximum value in the range for the input

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    int bucketCount = n; 
    float** buckets = (float**)malloc(bucketCount * sizeof(float*));
    int* bucketSizes = (int*)malloc(bucketCount * sizeof(int));
    
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Place each number in its respective bucket
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * bucketCount); // Determine the bucket index
        if (index >= bucketCount) {
            index = bucketCount - 1; // Handle edge case
        }
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < bucketCount; i++) {
        // Simple insertion sort for individual buckets
        for (int j = 1; j < bucketSizes[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate all buckets into arr
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print an array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%0.2f ", arr[i]);
    }
    printf("\n");
}

// Main function where all begins
int main() {
    int n;

    // Peaceful gathering of input from the user
    printf("Welcome to the peaceful world of Bucket Sort!\n");
    printf("Please enter the number of elements you wish to sort: ");
    scanf("%d", &n);

    float* arr = (float*)malloc(n * sizeof(float));

    // Input elements for sorting
    printf("Please enter %d floating-point numbers between 0.0 and %0.2f:\n", n, MAX_VALUE);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        // Ensure that the number is within the expected range
        if (arr[i] < 0.0 || arr[i] > MAX_VALUE) {
            printf("Please enter a valid number in the range [0.0, %0.2f].\n", MAX_VALUE);
            i--; // Decrement i to allow correct input
        }
    }

    // Displaying the array before sorting
    printf("Array before sorting:\n");
    printArray(arr, n);

    // Sorting the array
    bucketSort(arr, n);

    // Displaying the sorted array
    printf("Array after sorting:\n");
    printArray(arr, n);

    // Free memory allocated for the array
    free(arr);
    return 0;
}