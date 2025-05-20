//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Function to perform insertion sort on a bucket
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(float array[], int n) {
    // Create buckets
    int i, j;
    int bucketCount = BUCKET_SIZE;  
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));

    // Initialize each bucket
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucketSizes[i] = 0;  // Initialize size of each bucket to zero
    }

    // Distribute the array elements into buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = (int)(array[i] * bucketCount);
        if (bucketIndex >= bucketCount) {
            bucketIndex = bucketCount - 1; // Clamping to avoid overflow
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = array[i] * 100; // Scale for integers
    }

    // Sort each bucket and then concatenate
    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (j = 0; j < bucketSizes[i]; j++) {
                array[index++] = buckets[i][j] / 100.0; // Convert back to float
            }
        }
    }

    // Free memory
    for (i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

int main() {
    printf("Welcome to the Energetic Bucket Sort Demonstration!\n");
    
    // Sample size of array
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    // Dynamic array creation
    float *array = (float *)malloc(n * sizeof(float));
    printf("Let's fill the array with some energetic random values between 0 and 1!\n");
    
    // Fill the array with random float values
    for (int i = 0; i < n; i++) {
        array[i] = (float)rand() / RAND_MAX;
        printf("[Element %d]: %f\n", i, array[i]);
    }

    // Perform bucket sort
    printf("\nTime to Sort! Hang tight...\n");
    bucketSort(array, n);

    // Output the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");

    // Clean up
    free(array);
    printf("Thank you for using the Bucket Sort Program! Have a great day!\n");
    
    return 0;
}