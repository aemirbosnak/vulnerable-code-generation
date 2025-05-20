//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum number of elements
#define BUCKET_SIZE 10 // Range of numbers for each bucket

// Function to create buckets
void bucketSort(int array[], int n) {
    // Create buckets
    int i, j;
    int bucketCount = (n + BUCKET_SIZE - 1) / BUCKET_SIZE; // Calculate required buckets
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));

    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(MAX * sizeof(int)); // Allocate memory for each bucket
        bucketSizes[i] = 0; // Initialize bucket size
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = array[i] / BUCKET_SIZE; // Find appropriate bucket index
        if (bucketIndex >= bucketCount) {
            bucketIndex = bucketCount - 1; // Ensure index is within bounds
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = array[i]; // Add to bucket
    }

    // Sort individual buckets and concatenate results
    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        // If the bucket has elements, sort them
        if (bucketSizes[i] > 0) {
            // Sort using insertion sort (as buckets are small, this is efficient)
            for (j = 1; j < bucketSizes[i]; j++) {
                int key = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
            // Copy sorted bucket to main array
            for (j = 0; j < bucketSizes[i]; j++) {
                array[index++] = buckets[i][j];
            }
        }
        free(buckets[i]); // Free individual buckets
    }

    free(buckets); // Free the array of buckets
    free(bucketSizes); // Free the bucket size array
}

// Function to perform bucket sort demonstration
void demoBucketSort() {
    int array[MAX];
    int n, i;

    // Get number of elements
    printf("Enter number of elements to sort (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("Exceeded maximum number of elements. Exiting...\n");
        return;
    }

    // Get the elements from the user
    printf("Enter %d numbers (range 0 - %d):\n", n, BUCKET_SIZE * (n / BUCKET_SIZE + 1));
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Perform bucket sort
    bucketSort(array, n);

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    demoBucketSort();
    return 0;
}