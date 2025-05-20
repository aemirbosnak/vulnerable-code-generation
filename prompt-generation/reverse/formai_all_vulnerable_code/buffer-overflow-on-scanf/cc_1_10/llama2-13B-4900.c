//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 1000

// A simple swap function that swaps two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// A function to sort an array using quicksort
void quicksort(int arr[], int low, int high) {
    // Base case: If the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two halves
    int pivot = partition(arr, low, high);

    // Recursively sort the left and right halves
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
}

// A partition function that partitions the array into two halves based on a given element
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high - 1;

    // Move elements less than the pivot to the left
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] >= pivot) {
            j--;
        }

        // Swap the elements
        if (i <= j) {
            swap(arr, i, j);
            i++;
            j--;
        }
    }

    // Move the pivot element to the right position
    swap(arr, low, j + 1);

    return j + 1;
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int i, j, n;

    // Read the array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read the array elements from the user
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sort the array using quicksort
    quicksort(arr, 0, n - 1);

    // Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}