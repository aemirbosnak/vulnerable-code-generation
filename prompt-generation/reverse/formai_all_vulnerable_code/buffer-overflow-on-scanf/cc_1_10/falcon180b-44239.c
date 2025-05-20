//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0]; // Initialize max with first element
    int min = arr[0]; // Initialize min with first element

    // Find max and min values in array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate range and bucket size
    int range = max - min + 1;
    int bucketSize = range / n;

    // Create buckets
    int buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Place elements in buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        buckets[bucketIndex]++;
    }

    // Place elements in sorted array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * bucketSize + j * bucketSize + min;
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int n;

    // Get array size from user
    printf("Enter array size: ");
    scanf("%d", &n);

    // Get array elements from user
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}