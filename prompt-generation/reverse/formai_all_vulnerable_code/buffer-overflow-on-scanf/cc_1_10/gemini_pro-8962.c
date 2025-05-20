//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to search for an element in an array using linear search
int linear_search(int *arr, int size, int element) {
    // Iterate over the array and compare each element with the given element
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            // Element found, return the index
            return i;
        }
    }

    // Element not found, return -1
    return -1;
}

// Function to search for an element in an array using binary search
int binary_search(int *arr, int left, int right, int element) {
    // Base case: if the left pointer is greater than the right pointer, the element is not present
    if (left > right) {
        return -1;
    }

    // Calculate the middle index of the array
    int mid = (left + right) / 2;

    // Compare the element with the middle element
    if (arr[mid] == element) {
        // Element found, return the index
        return mid;
    } else if (arr[mid] < element) {
        // Element is in the right half of the array
        return binary_search(arr, mid + 1, right, element);
    } else {
        // Element is in the left half of the array
        return binary_search(arr, left, mid - 1, element);
    }
}

// Function to print the array
void print_array(int *arr, int size) {
    // Iterate over the array and print each element
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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

    // Search for the element using linear search
    int linear_search_index = linear_search(arr, size, element);

    // Search for the element using binary search
    int binary_search_index = binary_search(arr, 0, size - 1, element);

    // Print the results
    if (linear_search_index != -1) {
        printf("Element found at index %d using linear search\n", linear_search_index);
    } else {
        printf("Element not found using linear search\n");
    }

    if (binary_search_index != -1) {
        printf("Element found at index %d using binary search\n", binary_search_index);
    } else {
        printf("Element not found using binary search\n");
    }

    return 0;
}