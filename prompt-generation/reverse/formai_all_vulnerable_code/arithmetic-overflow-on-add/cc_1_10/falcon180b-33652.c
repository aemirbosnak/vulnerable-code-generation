//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
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
        if (arr[j] <= pivot) {
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
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int* bucket = (int*)malloc(range * sizeof(int));

    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[arr[i] - min]; j++) {
            printf("%d ", arr[i]);
        }
    }

    free(bucket);
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}