//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 100
#define MAX_ELEMENTS 1000

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j, max = 0;
    int buckets[MAX_BUCKETS] = { 0 };

    // Find the maximum element in the array
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create buckets and place elements in them
    for (i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * MAX_BUCKETS) / max;
        buckets[bucketIndex]++;
    }

    int k = 0;
    for (i = 0; i < MAX_BUCKETS; i++) {
        for (j = 0; j < buckets[i]; j++) {
            arr[k++] = i * MAX_ELEMENTS / MAX_BUCKETS;
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
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}