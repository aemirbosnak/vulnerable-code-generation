//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
// Happy Bucket Sort Implementation
#include <stdio.h>
#include <stdlib.h>

// Function to sort the given array using bucket sort
void bucketSort(int arr[], int n) {
    // Create an array of buckets to store the elements
    int bucketCount = 10;
    int buckets[bucketCount];

    // Initialize the buckets
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = 0;
    }

    // Put each element into its corresponding bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketCount;
        buckets[bucketIndex]++;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < bucketCount; i++) {
        int sortedBucket[buckets[i]];
        int j = 0;
        for (int k = 0; k < buckets[i]; k++) {
            sortedBucket[k] = arr[j];
            j++;
        }
        for (int k = 0; k < buckets[i]; k++) {
            arr[j] = sortedBucket[k];
            j++;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the code
int main() {
    int arr[] = {3, 7, 8, 4, 1, 2, 9, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}