//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
#define MAX_NUMBERS 100

// The character who'll help us sort our numbers
void printBucket(int *bucket, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", bucket[i]);
    }
    printf("\n");
}

// The wise wizard who'll help us sort numbers using bucket sort
void bucketSort(int arr[], int n) {
    // Step 1: Create the buckets
    int buckets[BUCKET_SIZE][MAX_NUMBERS];
    int bucketCount[BUCKET_SIZE] = {0};

    // Step 2: Distribute the numbers into the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;  // Determine which bucket the number belongs to
        if (bucketIndex >= BUCKET_SIZE) {
            bucketIndex = BUCKET_SIZE - 1;  // Make sure we don't exceed the number of buckets
        }
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];  // Place number in the appropriate bucket
    }

    // Step 3: Sort each bucket and collect the sorted numbers
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        // For each bucket, we have to sort the contents
        if (bucketCount[i] > 0) {
            printf("Sorting bucket %d: ", i);
            printBucket(buckets[i], bucketCount[i]);  // Print bucket contents

            // Simple insertion sort within each bucket 
            for (int j = 1; j < bucketCount[i]; j++) {
                int key = buckets[i][j];
                int k = j - 1;

                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k = k - 1;
                }
                buckets[i][k + 1] = key;
            }
            // Collecting sorted numbers from the current bucket
            for (int j = 0; j < bucketCount[i]; j++) {
                arr[index++] = buckets[i][j];  
            }
        }
    }
}

// Helper function to print the final sorted array
void printArray(int arr[], int n) {
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// The main hero of our story
int main() {
    int arr[MAX_NUMBERS];
    int n;

    printf("Welcome to the Magical Bucket Sort!\n");
    printf("Enter the number of elements (up to %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    
    if (n > MAX_NUMBERS) {
        printf("That's too many numbers! Please try again with fewer than %d.\n", MAX_NUMBERS);
        return 1;
    }

    printf("Now, let's gather our numbers (between 0 and %d):\n", BUCKET_SIZE * BUCKET_SIZE);
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The unorganized numbers are:\n");
    printArray(arr, n);

    // Call the wise wizard to sort the numbers
    bucketSort(arr, n);

    // Show the sorted numbers
    printArray(arr, n);

    printf("Magic complete! The numbers are all neatly sorted!\n");
    return 0;
}