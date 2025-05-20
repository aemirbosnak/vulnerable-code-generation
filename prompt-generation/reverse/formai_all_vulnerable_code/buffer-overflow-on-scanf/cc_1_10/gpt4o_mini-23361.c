//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Function to perform insertion sort on an array
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

    // Create buckets
    int bucket_count = (int)(n / BUCKET_SIZE) + 1; // Number of buckets
    float **buckets = (float **)malloc(bucket_count * sizeof(float*));
    int *bucket_sizes = (int *)malloc(bucket_count * sizeof(int)); // To store sizes of each bucket

    // Initialize buckets
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = (float *)malloc(BUCKET_SIZE * sizeof(float));
        bucket_sizes[i] = 0; // Initialize the sizes to zero
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)(arr[i] * bucket_count);
        if (bucket_index >= bucket_count)
            bucket_index = bucket_count - 1; // Handle edge case
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i]; // Place element in the appropriate bucket
    }

    // Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        if (bucket_sizes[i] > 0) {
            insertionSort(buckets[i], bucket_sizes[i]); // Sort each bucket
            for (int j = 0; j < bucket_sizes[i]; j++) {
                arr[index++] = buckets[i][j]; // Concatenate sorted results
            }
        }
    }

    // Free memory
    for (int i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
}

// Function to read array from standard input
void readArray(float arr[], int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
  
    printf("Enter the elements (space separated): ");
    for (int i = 0; i < *size; i++) {
        scanf("%f", &arr[i]);
    }
}

// Main function
int main() {
    float *arr = (float *)malloc(100 * sizeof(float)); // Allocate memory for 100 elements
    int n;

    readArray(arr, &n); // Read array of numbers
    bucketSort(arr, n); // Sort the array using bucket sort

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]); // Print sorted numbers
    }
    printf("\n");

    free(arr); // Free the allocated memory
    return 0;
}