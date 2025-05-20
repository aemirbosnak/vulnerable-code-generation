//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get maximum element in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int bucketSize = max / n;
    int* buckets[MAX];
    for (int i = 0; i < MAX; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int j = 0;
        while (j < i && arr[j] / bucketSize == bucketIndex) {
            swap(&arr[j], &arr[i]);
            j++;
        }
        buckets[bucketIndex][i] = arr[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = buckets[k][i];
        k++;
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
    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}