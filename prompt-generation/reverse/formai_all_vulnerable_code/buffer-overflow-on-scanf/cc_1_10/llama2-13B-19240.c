//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 10000
#define MIN_ARRAY_SIZE 10

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to sort the array using quicksort
void quicksort(int arr[], int low, int high) {
    int i, j, pivot, temp;

    // Base case: If the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two subarrays
    pivot = arr[low];
    i = low + 1;
    j = high;

    // Find the first element greater than the pivot
    while (i <= j) {
        if (arr[i] > pivot) {
            j--;
            swap(arr, i, j);
        } else {
            i++;
        }
    }

    // Recursively sort the two subarrays
    quicksort(arr, low, i - 1);
    quicksort(arr, j + 1, high);
}

// Main function to sort the array using quicksort
int main() {
    int arr[MAX_ARRAY_SIZE], n, i, j, pivot;
    clock_t start, end;

    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Initialize the array with random elements
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Start the clock
    start = clock();

    // Sort the array using quicksort
    quicksort(arr, 0, n - 1);

    // End the clock
    end = clock();

    // Print the time taken to sort the array
    printf("Time taken to sort the array: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}