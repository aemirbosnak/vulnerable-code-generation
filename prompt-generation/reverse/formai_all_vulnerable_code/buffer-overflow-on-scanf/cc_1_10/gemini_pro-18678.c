//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the data type of the elements in the array
typedef int element_type;

// Function to swap two elements in the array
void swap(element_type *a, element_type *b) {
    element_type temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array using the bubble sort algorithm
void bubble_sort(element_type arr[], int size) {
    // Iterate over the array, comparing each element to its neighbor
    for (int i = 0; i < size - 1; i++) {
        // Iterate over the remaining elements in the array
        for (int j = 0; j < size - i - 1; j++) {
            // Compare the current element to its neighbor
            if (arr[j] > arr[j + 1]) {
                // If the current element is greater than its neighbor, swap them
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to print the array
void print_array(element_type arr[], int size) {
    // Iterate over the array and print each element
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Declare the array
    element_type arr[MAX_SIZE];

    // Get the size of the array from the user
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using the bubble sort algorithm
    bubble_sort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}