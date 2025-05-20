//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10  // Number of buckets
#define ARRAY_SIZE 100  // Max size of the input array

// Structure to hold elements of each bucket
typedef struct Bucket {
    int *array;         // Array of elements in the bucket
    int count;         // Current count of elements in the bucket
} Bucket;

// Function to create and initialize buckets
void initializeBuckets(Bucket *buckets) {
    for(int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].array = (int*)malloc(ARRAY_SIZE * sizeof(int)); // Allocate memory for bucket's array
        buckets[i].count = 0; // Initialize count to zero
    }
}

// Function to free allocated memory for buckets
void freeBuckets(Bucket *buckets) {
    for(int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i].array); // Free memory for each bucket's array
    }
}

// Function to find the maximum value in the array
int findMax(int *array, int size) {
    int max = array[0];
    for(int i = 1; i < size; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max; // Return the maximum value found
}

// Function to perform bucket sort
void bucketSort(int *array, int size) {
    if(size <= 0) return; // Return early if size is 0 or less

    int maxValue = findMax(array, size); // Find the maximum value in the array
    float interval = (float)(maxValue + 1) / BUCKET_SIZE;  // Calculate the range for each bucket

    Bucket *buckets = (Bucket*)malloc(BUCKET_SIZE * sizeof(Bucket)); // Allocate memory for buckets
    initializeBuckets(buckets); // Initialize buckets

    // Distributing elements into buckets
    for(int i = 0; i < size; i++) {
        int bucketIndex = (int)(array[i] / interval); // Determine bucket index
        if (bucketIndex >= BUCKET_SIZE) bucketIndex = BUCKET_SIZE - 1; // Handle the max edge case
        buckets[bucketIndex].array[buckets[bucketIndex].count++] = array[i]; // Add element to bucket
    }

    // Sort each bucket and gather the results
    int index = 0;
    for(int i = 0; i < BUCKET_SIZE; i++) {
        if(buckets[i].count > 0) {
            // Simple insertion sort on each bucket
            for(int j = 1; j < buckets[i].count; j++) {
                int key = buckets[i].array[j];
                int k = j - 1;
                while(k >= 0 && buckets[i].array[k] > key) {
                    buckets[i].array[k + 1] = buckets[i].array[k]; // Shift larger elements to the right
                    k--;
                }
                buckets[i].array[k + 1] = key; // Place the element at the correct position
            }
            // Gather sorted elements back to the original array
            for(int j = 0; j < buckets[i].count; j++) {
                array[index++] = buckets[i].array[j]; // Copy sorted elements back
            }
        }
    }

    freeBuckets(buckets); // Free allocated bucket memory
    free(buckets); // Free the buckets array itself
}

// Function to display the array
void displayArray(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]); // Print each element
    }
    printf("\n"); // New line for better readability
}

// Main function to drive the program
int main() {
    int array[ARRAY_SIZE];
    int size;

    printf("Enter number of elements (max %d): ", ARRAY_SIZE);
    scanf("%d", &size); // Read number of elements from user

    if(size > ARRAY_SIZE || size <= 0) {
        printf("Invalid number of elements.\n");
        return -1; // Exit if the input size is not valid
    }

    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]); // Read elements into array
    }

    printf("Original array: ");
    displayArray(array, size); // Display original array

    bucketSort(array, size); // Call bucket sort function

    printf("Sorted array: ");
    displayArray(array, size); // Display sorted array

    return 0; // Successful execution
}