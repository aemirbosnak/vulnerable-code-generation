//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
/*
 * Bucket Sort Implementation in C
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void bucketSort(int arr[], int n) {
    int i, j, k;
    int min = arr[0];
    int max = arr[0];
    int range;
    int count[SIZE];
    int *output;

    // Find the max and min values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate the range of the array
    range = max - min + 1;

    // Initialize the count array
    for (i = 0; i < SIZE; i++) {
        count[i] = 0;
    }

    // Calculate the frequency of each element in the array
    for (i = 0; i < n; i++) {
        count[(arr[i] - min) / range]++;
    }

    // Calculate the cumulative sum of the count array
    for (i = 1; i < SIZE; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array
    output = (int *)malloc(n * sizeof(int));

    // Sort the array using the count array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] - min) / range] - 1] = arr[i];
        count[(arr[i] - min) / range]--;
    }

    // Copy the sorted array to the original array
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free the output array
    free(output);
}

int main() {
    int arr[] = {5, 2, 1, 3, 4, 7, 6, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}