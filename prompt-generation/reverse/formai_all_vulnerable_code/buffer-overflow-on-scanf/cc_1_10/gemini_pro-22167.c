//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the function to search for an element in the array
int linear_search(int arr[], int size, int element) {
    // Iterate over the array
    for (int i = 0; i < size; i++) {
        // Check if the current element is equal to the element we are searching for
        if (arr[i] == element) {
            // Return the index of the element
            return i;
        }
    }

    // If the element is not found, return -1
    return -1;
}

// Define the function to print the array
void print_array(int arr[], int size) {
    // Iterate over the array
    for (int i = 0; i < size; i++) {
        // Print the current element
        printf("%d ", arr[i]);
    }

    // Print a newline
    printf("\n");
}

// Define the main function
int main() {
    // Create an array of integers
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Get the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Original array: ");
    print_array(arr, size);

    // Get the element to search for
    int element;
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    // Search for the element in the array
    int index = linear_search(arr, size, element);

    // Check if the element was found
    if (index == -1) {
        // Print that the element was not found
        printf("Element not found.\n");
    } else {
        // Print the index of the element
        printf("Element found at index %d.\n", index);
    }

    return 0;
}