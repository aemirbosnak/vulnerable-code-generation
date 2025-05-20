//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 100
#define BUCKET_COUNT 10

// Structure for a bucket
typedef struct Bucket {
    int *array;
    int size;
} Bucket;

// Function to initialize buckets
void initializeBuckets(Bucket buckets[], int count) {
    for (int i = 0; i < count; i++) {
        buckets[i].array = (int *)malloc(MAX_NUMBERS * sizeof(int));
        buckets[i].size = 0;
    }
}

// Function to free allocated memory for buckets
void freeBuckets(Bucket buckets[], int count) {
    for (int i = 0; i < count; i++) {
        free(buckets[i].array);
    }
}

// Function to perform the bucket sort
void bucketSort(int arr[], int n) {
    // Initialize buckets
    Bucket buckets[BUCKET_COUNT];
    initializeBuckets(buckets, BUCKET_COUNT);

    // Find the maximum value in array for range determination
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (arr[i] * BUCKET_COUNT) / (max + 1);
        buckets[index].array[buckets[index].size++] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Sorting the bucket
        for (int j = 1; j < buckets[i].size; j++) {
            int key = buckets[i].array[j];
            int k = j - 1;

            // Shift elements of bucket to the right to find the right position
            while (k >= 0 && buckets[i].array[k] > key) {
                buckets[i].array[k + 1] = buckets[i].array[k];
                k--;
            }
            buckets[i].array[k + 1] = key;
        }
    }

    // Merge sorted buckets back into original array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].array[j];
        }
    }

    // Free the allocated memory for buckets
    freeBuckets(buckets, BUCKET_COUNT);
}

// Function to print the array
void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Helper function to generate random numbers
void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Numbers between 0 and 99
    }
}

// Main function
int main() {
    int numbers[MAX_NUMBERS];
    int n;

    // Get the number of elements from the user
    printf("Enter the number of elements to sort (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_NUMBERS) {
        printf("Error: Number of elements must be between 1 and %d.\n", MAX_NUMBERS);
        return 1;
    }

    // Generate random numbers and store in the array
    generateRandomNumbers(numbers, n);
    
    printf("Original array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Perform bucket sort
    bucketSort(numbers, n);

    // Print the sorted array
    printArray(numbers, n);

    return 0;
}