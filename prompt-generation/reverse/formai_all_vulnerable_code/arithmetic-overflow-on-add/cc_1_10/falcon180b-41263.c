//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int i, j, max, min, temp;
    int bucket[MAX_SIZE];

    // Find the maximum and minimum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the range and bucket size
    int range = max - min + 1;
    int bucketSize = range / n;

    // Initialize the buckets
    for (i = 0; i < n; i++)
        bucket[i] = 0;

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        bucket[j]++;
    }

    // Place the elements back in the array
    i = 0;
    for (j = 0; j < n; j++) {
        while (bucket[j] > 0) {
            arr[i++] = min + j * bucketSize;
            bucket[j]--;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = { 12, 34, 54, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}