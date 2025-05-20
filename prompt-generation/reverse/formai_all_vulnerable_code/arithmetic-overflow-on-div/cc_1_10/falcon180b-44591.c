//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
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
    int max = findMax(arr, n);
    int bucketSize = max / n;
    int* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*) malloc(bucketSize * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] <= max - i * bucketSize && arr[j] >= i * bucketSize) {
                buckets[i] = (int*) realloc(buckets[i], (j + 1) * sizeof(int));
                buckets[i][j] = arr[j];
            }
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i][index]; j++) {
            arr[j] = buckets[i][j];
        }
        index++;
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
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
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}