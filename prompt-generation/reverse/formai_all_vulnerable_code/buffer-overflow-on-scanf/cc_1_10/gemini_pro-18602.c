//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to search for an element in an array using binary search
int binary_search(int arr[], int size, int target) {
    // Set the initial indices for the binary search
    int low = 0;
    int high = size - 1;

    // Perform binary search until the low index is less than or equal to the high index
    while (low <= high) {
        // Calculate the midpoint of the array
        int mid = low + (high - low) / 2;

        // Check if the target element is equal to the element at the midpoint
        if (arr[mid] == target) {
            // Return the index of the target element
            return mid;
        } else if (arr[mid] < target) {
            // If the target element is greater than the element at the midpoint, update the low index
            low = mid + 1;
        } else {
            // If the target element is less than the element at the midpoint, update the high index
            high = mid - 1;
        }
    }

    // If the target element is not found, return -1
    return -1;
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Create an array of integers
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Original array: ");
    print_array(arr, size);

    // Get the target element from the user
    int target;
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Search for the target element using binary search
    int result = binary_search(arr, size, target);

    // Print the result of the search
    if (result == -1) {
        printf("Target element not found.\n");
    } else {
        printf("Target element found at index %d.\n", result);
    }

    return 0;
}