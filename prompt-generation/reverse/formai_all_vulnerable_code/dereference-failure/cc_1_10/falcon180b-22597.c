//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int *bucket = (int *)malloc(max * sizeof(int));
    int i, j;

    // Create empty buckets
    for (i = 0; i < max; i++) {
        bucket[i] = 0;
    }

    // Place elements in buckets
    for (i = 0; i < n; i++) {
        j = arr[i] * max / (max - 1);
        bucket[j]++;
    }

    // Combine the buckets
    int index = 0;
    for (i = 0; i < max; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[index++] = i;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}