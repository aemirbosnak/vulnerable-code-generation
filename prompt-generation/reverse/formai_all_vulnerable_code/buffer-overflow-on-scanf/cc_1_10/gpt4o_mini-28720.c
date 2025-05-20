//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000  // Define a constant for maximum value of input

// Function to create and initialize the buckets
void createBuckets(int **buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * MAX);
    }
}

// Function to get the bucket index for the value
int getBucketIndex(int value, int numBuckets, int maxValue) {
    return (int)((double)value / maxValue * numBuckets);
}

// Function for sorting individual buckets
void insertionSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Function to merge sorted buckets into the original array
void mergeBuckets(int **buckets, int *bucketSizes, int numBuckets, int *arr, int *size) {
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
    *size = index; // Update the size to the number of elements sorted
}

// The main bucket sort function
void bucketSort(int *arr, int size, int numBuckets) {
    // Step 1: Create buckets
    int **buckets = (int **)malloc(sizeof(int *) * numBuckets);
    createBuckets(buckets, numBuckets);
    
    int *bucketSizes = (int *)malloc(sizeof(int) * numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        bucketSizes[i] = 0;
    }
    
    // Step 2: Distribute input array elements into buckets
    int maxValue = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        int index = getBucketIndex(arr[i], numBuckets, maxValue);
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // Step 3: Sort each bucket and merge back to the original array
    for (int i = 0; i < numBuckets; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Step 4: Flatten the buckets back into arr
    mergeBuckets(buckets, bucketSizes, numBuckets, arr, &size);

    // Freeing the allocated memory
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Helper function to print the array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to execute the bucket sort
int main() {
    int numElements;
    
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &numElements);
    
    if (numElements <= 0 || numElements > MAX) {
        printf("Please enter a valid number of elements (1 to %d).\n", MAX);
        return 1;
    }

    int *arr = (int *)malloc(sizeof(int) * numElements);

    printf("Enter the elements:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &arr[i]);
    }
    
    int numBuckets = (int)sqrt(numElements);  // Logical choice for number of buckets

    printf("Original array:\n");
    printArray(arr, numElements);

    bucketSort(arr, numElements, numBuckets);
    
    printf("Sorted array:\n");
    printArray(arr, numElements);

    free(arr);
    return 0;
}