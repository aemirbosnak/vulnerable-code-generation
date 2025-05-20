//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the elements in the bucket
void sortBucket(int bucket[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bucket[j] > bucket[j + 1]) {
                swap(&bucket[j], &bucket[j + 1]);
            }
        }
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and bucket size
    int range = max - min + 1;
    int bucketSize = range / n;

    // Create the buckets
    int bucket[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // Place the elements in the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        bucket[bucketIndex]++;
    }

    // Sort the elements in the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        for (int j = 0; j < bucket[bucketIndex]; j++) {
            arr[i] = min + j * bucketSize;
            i++;
        }
    }
}

// Function to print the elements in the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 5, 2, 9, 3, 7, 10, 12, 1, 6, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}