//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using selection sort
void sort(int arr[], int low, int high) {
    int i, j, min_idx;

    // Find the first unsorted element
    for (i = low; i < high; i++) {
        min_idx = i;
        for (j = i + 1; j < high; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the unsorted element with the smallest element after it
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int i, n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Initialize the array with random elements
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using selection sort
    sort(arr, 0, n - 1);

    // Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}