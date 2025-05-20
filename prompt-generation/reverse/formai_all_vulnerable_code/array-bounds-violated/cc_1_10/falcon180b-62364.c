//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the position of an element in the array
int findPosition(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Function to perform the bucket sort
void bucketSort(int arr[], int n) {
    int i, j, k;
    int buckets[MAX];

    // Initialize the buckets with 0
    for (i = 0; i < MAX; i++) {
        buckets[i] = 0;
    }

    // Put the elements in the buckets
    for (i = 0; i < n; i++) {
        j = findPosition(buckets, MAX, arr[i]);
        buckets[j]++;
    }

    // Modify the buckets to store the position of each element
    for (i = 0; i < MAX; i++) {
        buckets[i] += buckets[i - 1];
    }

    // Place the elements in the original array
    for (i = n - 1; i >= 0; i--) {
        j = findPosition(buckets, MAX, arr[i]);
        k = buckets[j] - 1;
        buckets[j]--;
        arr[k] = arr[i];
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = { 5, 2, 8, 1, 7, 6, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}