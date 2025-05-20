//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Helper function to find the median of two numbers
int findMedian(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int *bucket;
    int size = (n / 2) + 1;
    bucket = (int *) malloc(size * sizeof(int));

    // Create buckets
    for (int i = 0; i < size; i++) {
        bucket[i] = 0;
    }

    // Put each element in its respective bucket
    for (int i = 0; i < n; i++) {
        int bucketIdx = findMedian(arr[i], 0);
        bucket[bucketIdx]++;
    }

    // Sort each bucket
    for (int i = 0; i < size; i++) {
        int *sortedArr = (int *) malloc(bucket[i] * sizeof(int));
        int j = 0;
        for (int k = 0; k < bucket[i]; k++) {
            sortedArr[j++] = arr[k];
        }
        for (int k = 0; k < bucket[i]; k++) {
            arr[k] = sortedArr[k];
        }
        free(sortedArr);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to get user input
int getUserInput(int n) {
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Main function
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = getUserInput(n);
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    free(arr);
    return 0;
}