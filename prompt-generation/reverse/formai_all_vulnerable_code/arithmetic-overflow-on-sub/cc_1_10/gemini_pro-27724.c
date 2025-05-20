//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers in ascending order using the selection sort algorithm
void selection_sort(int arr[], int size) {
    int i, j, min_index;

    // Iterate over the array
    for (i = 0; i < size - 1; i++) {
        // Find the minimum element in the unsorted portion of the array
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the minimum element with the first element of the unsorted portion
        swap(&arr[min_index], &arr[i]);
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using the selection sort algorithm
    selection_sort(arr, size);

    // Print the sorted array
    printf("The sorted array is: ");
    print_array(arr, size);

    return 0;
}