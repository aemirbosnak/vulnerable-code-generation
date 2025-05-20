//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Auxiliary function to swap two elements in the array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to sort the array using insertion sort
void insertion_sort(int arr[], int n) {
    int i, j, key;

    // Loop until the end of the array
    for (i = 1; i < n; i++) {
        // Find the right position for the current element
        for (j = i - 1; j >= 0 && arr[j] > arr[i]; j--) {
            // Swap the current element with its right position
            swap(arr, j, i);
        }
    }
}

int main() {
    int arr[MAX_LENGTH];
    int n;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Create the array with random elements
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using insertion sort
    insertion_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}