//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100
#define BUCKET_COUNT 10

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int array[], int n) {
    // Create an array of buckets
    int **buckets = malloc(BUCKET_COUNT * sizeof(int*));
    int *bucketSizes = malloc(BUCKET_COUNT * sizeof(int));

    // Initialize buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = malloc(n * sizeof(int));
        bucketSizes[i] = 0;
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int index = (array[i] * BUCKET_COUNT) / (MAX_VALUE + 1);
        buckets[index][bucketSizes[index]] = array[i];
        bucketSizes[index]++;
    }

    // Sort individual buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Concatenate buckets into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Helper function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function to initiate the sorting process
int main() {
    int n;

    // Inquiry to user for the number of elements
    printf("How many numbers would you like to sort? ");
    scanf("%d", &n);

    // Dynamic allocation of array
    int *array = malloc(n * sizeof(int));

    printf("Please enter %d numbers (0 to %d):\n", n, MAX_VALUE);
    for (int i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Unsorted array: ");
    printArray(array, n);

    // Perform the bucket sort
    bucketSort(array, n);

    printf("Sorted array: ");
    printArray(array, n);

    // Free allocated memory
    free(array);
    return 0;
}