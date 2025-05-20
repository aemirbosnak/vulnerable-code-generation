//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000000

// Function to find the minimum and maximum values in the array
void findMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int bucket[MAX];
    int min, max, range;
    findMinMax(arr, n, &min, &max);
    range = max - min + 1;
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    for (int i = 1; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        bucket[arr[i] - min]--;
        int pos = bucket[arr[i] - min];
        arr[pos] = arr[i];
    }
}

// Function to print the sorted array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = { 5, 3, 8, 1, 6, 2, 9, 4, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}