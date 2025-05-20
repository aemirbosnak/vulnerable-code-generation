//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucketSize = max / n;
    int* buckets[MAX_SIZE];

    // Create empty buckets
    for(int i = 0; i < n; i++) {
        buckets[i] = malloc(bucketSize * sizeof(int));
        for(int j = 0; j < bucketSize; j++) {
            buckets[i][j] = -1;
        }
    }

    // Place elements in buckets
    for(int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex][arr[i] % bucketSize] = arr[i];
    }

    // Concatenate sorted buckets
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bucketSize; j++) {
            if(buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}