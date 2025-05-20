//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5

// Bucket Sort Implementation
void bucketSort(int arr[], int n) {
    // Create n empty buckets
    int buckets[n][BUCKET_SIZE];

    // Initialize all buckets to empty
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < BUCKET_SIZE; j++) {
            buckets[i][j] = 0;
        }
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        int slotIndex = arr[i] % BUCKET_SIZE;

        buckets[bucketIndex][slotIndex]++;
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < BUCKET_SIZE; j++) {
            while (buckets[i][j] > 0) {
                arr[index++] = i * BUCKET_SIZE + j;
                buckets[i][j]--;
            }
        }
    }
}

// Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    // Get the size of the array
    int n = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}