//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Function to print an array of integers
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    // Initialize buckets
    int buckets[size];
    
    // Populate buckets with values from original array
    for (int i = 0; i < size; i++) {
        buckets[arr[i]] = 1;
    }
    
    // Sort each bucket in ascending order
    for (int i = 1; i < size; i++) {
        buckets[i] += buckets[i - 1];
    }
    
    // Combine sorted buckets back into original array
    for (int i = 0; i < size; i++) {
        arr[i] = buckets[i];
    }
    
    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, size);
}

int main() {
    // Test case
    int arr[] = {5, 2, 9, 3, 7, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, size);
    
    bucketSort(arr, size);
    
    printf("\nSorted array: ");
    printArray(arr, size);
    
    return 0;
}