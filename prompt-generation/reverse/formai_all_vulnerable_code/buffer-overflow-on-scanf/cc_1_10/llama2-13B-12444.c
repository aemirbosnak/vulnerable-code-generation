//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configuration parameters
#define MAX_ARRAY_SIZE 100
#define SORT_DIRECTION 1 // 1 for ascending, -1 for descending

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array using quicksort
void quicksort(int arr[], int low, int high) {
    int i, j, pivot;

    // Choose the pivot element
    pivot = arr[low];

    // Partition the array into two parts
    for (i = low + 1; i <= high; i++) {
        if (arr[i] <= pivot) {
            j = i;
            while (j <= high && arr[j] <= pivot) {
                j++;
            }
            swap(arr[i], arr[j]);
        }
    }

    // Recursively sort the two partitions
    if (low < j) {
        quicksort(arr, low, j);
    }
    if (j < high) {
        quicksort(arr, j, high);
    }
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int i, n;

    // Read the array elements from the user
    printf("Enter %d integer elements, separated by a newline:\n", MAX_ARRAY_SIZE);
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array elements before sorting
    printf("Before sorting:\n");
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using quicksort
    quicksort(arr, 0, MAX_ARRAY_SIZE - 1);

    // Print the array elements after sorting
    printf("After sorting:\n");
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}