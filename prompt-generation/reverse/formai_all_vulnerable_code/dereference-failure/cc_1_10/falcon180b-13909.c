//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j, k;
    int max = arr[0], min = arr[0];

    // Find the maximum and minimum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of values in the array
    int range = max - min;

    // Allocate memory for the buckets
    int *buckets = (int *) malloc(n * sizeof(int));

    // Initialize the buckets to zero
    for (i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        k = (arr[i] - min) / range;
        buckets[k]++;
    }

    // Modify the array to store the sorted values
    for (i = 0; i < n; i++) {
        for (j = 0; j < buckets[i]; j++) {
            arr[i * n + j] = i * range + j * range / (MAX_SIZE - 1) + min;
        }
    }
}

int main() {
    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}