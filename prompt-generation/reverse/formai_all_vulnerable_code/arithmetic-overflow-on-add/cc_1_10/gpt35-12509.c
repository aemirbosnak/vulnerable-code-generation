//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUCKET_SIZE 100

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort elements using Bucket Sort
void bucketSort(int arr[], int n) {
    int i, j;
    int count[BUCKET_SIZE];
    memset(count, 0, sizeof(count)); // Initialize count array to 0

    // Count the number of elements in each bucket
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Traverse through all buckets and sort them
    for (i = 0, j = 0; i < BUCKET_SIZE; i++) {
        while (count[i] > 0) {
            arr[j++] = i;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {56, 34, 23, 65, 24, 56, 77, 88, 99, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}