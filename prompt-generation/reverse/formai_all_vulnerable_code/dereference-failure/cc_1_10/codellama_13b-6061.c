//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
// Bucket Sort in C
#include <stdio.h>
#include <stdlib.h>

// Function to sort the array using bucket sort
void bucketSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create an array of buckets
    int* buckets = (int*)malloc(sizeof(int) * (max + 1));

    // Initialize all buckets with 0
    for (int i = 0; i < max + 1; i++) {
        buckets[i] = 0;
    }

    // Put each element in its respective bucket
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // Sort the elements in each bucket
    int index = 0;
    for (int i = 0; i < max + 1; i++) {
        while (buckets[i] > 0) {
            arr[index++] = i;
            buckets[i]--;
        }
    }

    // Free the memory allocated for buckets
    free(buckets);
}

int main() {
    int arr[] = {34, 2, 10, 3, 23, 12, 45, 6, 23, 10, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}