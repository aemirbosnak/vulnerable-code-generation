//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 1000
#define BUCKET_SIZE 10

// Function to get the maximum value from the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int bucketCount = (max / BUCKET_SIZE) + 1; // create the number of buckets
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));
    
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucketSizes[i] = 0; // initialize bucket sizes
    }

    // Distributing elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / BUCKET_SIZE; // find the index for the bucket
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // Sorting each bucket and concatenating them
    int sortedIndex = 0;
    for (int i = 0; i < bucketCount; i++) {
        // Sort the individual bucket using a simple insertion sort
        for (int j = 1; j < bucketSizes[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k = k - 1;
            }
            buckets[i][k + 1] = key;
        }

        // Adding sorted bucket elements to the main array
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[sortedIndex++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate bucket sort
int main() {
    int arr[MAX_NUMBERS], n;

    printf("Enter the number of elements (up to %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    
    if (n > MAX_NUMBERS || n <= 0) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return -1;
    }
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0;
}