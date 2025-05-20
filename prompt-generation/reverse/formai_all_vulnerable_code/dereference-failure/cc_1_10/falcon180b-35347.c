//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find the minimum and maximum values in the array
void findMinMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        } else if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int min, max, range, i, j;
    int *buckets = (int *) malloc(size * sizeof(int));

    // Find the minimum and maximum values in the array
    findMinMax(arr, size, &min, &max);

    // Calculate the range of values
    range = max - min + 1;

    // Initialize the buckets
    for (i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    // Place the elements in the appropriate buckets
    for (i = 0; i < size; i++) {
        j = arr[i] - min;
        buckets[j]++;
    }

    // Modify the array to store the sorted elements
    for (i = 0, j = 0; i < range; i++) {
        for (int k = 0; k < buckets[i]; k++) {
            arr[j++] = i + min;
        }
    }
}

int main() {
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform bucket sort
    bucketSort(arr, size);

    // Print the sorted array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}