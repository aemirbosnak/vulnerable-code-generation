//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define BUCKET_SIZE 10

// Function to get the index of the bucket
int getBucketIndex(int value) {
    return value / BUCKET_SIZE;
}

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
void bucketSort(int array[], int size) {
    // Create buckets
    int bucketCount = MAX / BUCKET_SIZE;
    int** buckets = (int**)malloc(bucketCount * sizeof(int*));
    int* bucketSizes = (int*)malloc(bucketCount * sizeof(int));
    
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int*)malloc(MAX * sizeof(int));
        bucketSizes[i] = 0;
    }

    // Distribute the elements into buckets
    for (int i = 0; i < size; i++) {
        int index = getBucketIndex(array[i]);
        buckets[index][bucketSizes[index]++] = array[i];
    }

    // Sort each bucket and concatenate
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                array[index++] = buckets[i][j];
            }
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
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to drive the bucket sort
int main() {
    int array[MAX], n;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);
    
    if (n > MAX || n <= 0) {
        fprintf(stderr, "Invalid size!\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Original array: ");
    printArray(array, n);
    
    bucketSort(array, n);

    printf("Sorted array: ");
    printArray(array, n);

    return EXIT_SUCCESS;
}