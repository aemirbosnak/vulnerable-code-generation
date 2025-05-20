//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucketSize = range / n;

    int* bucket = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        bucket[bucketIndex]++;
    }

    for (int i = 1; i < n; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[bucket[i] - 1] = i;
        bucket[i]--;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 5, 2, 9, 3, 7, 10, 12, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}