//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the index of the bucket for a given element
int getBucketIndex(int arr[], int n, int element) {
    return element % n;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum elements in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Create the buckets
    int bucketSize = (max - min) / n;
    int* buckets = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Place the elements in the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = getBucketIndex(arr, n, arr[i]);
        buckets[bucketIndex]++;
    }

    // Sort the buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * bucketSize + min;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}