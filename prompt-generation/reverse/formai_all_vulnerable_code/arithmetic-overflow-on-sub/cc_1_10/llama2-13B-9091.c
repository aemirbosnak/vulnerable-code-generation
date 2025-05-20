//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to sort an array using quicksort
void quicksort(int arr[], int low, int high) {
    int i, j, pivot, temp;

    // Base case: If the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two parts: less than pivot and greater than pivot
    pivot = arr[low];
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            swap(arr, i, low);
            low++;
        }
    }

    // Recursively sort the left and right parts
    quicksort(arr, low, i - 1);
    quicksort(arr, i + 1, high);
}

int main() {
    int arr[MAX_LENGTH];
    int i, j, n;

    // Get the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate a random array of integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using quicksort
    quicksort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}