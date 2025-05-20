//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to search for an element in an array using binary search
int binary_search(int arr[], int size, int element) {
    int low = 0;
    int high = size - 1;

    // Continue searching while the low index is less than or equal to the high index
    while (low <= high) {
        // Calculate the midpoint of the array
        int mid = (low + high) / 2;
        
        // Check if the element is found at the midpoint
        if (arr[mid] == element) {
            return mid;
        }
        // If the element is less than the midpoint, search the left half of the array
        else if (arr[mid] > element) {
            high = mid - 1;
        }
        // If the element is greater than the midpoint, search the right half of the array
        else {
            low = mid + 1;
        }
    }

    // If the element is not found, return -1
    return -1;
}

// Main function
int main() {
    // Initialize an array of integers
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(int);
    
    // Get the element to be searched from the user
    int element;
    printf("Enter the element to be searched: ");
    scanf("%d", &element);
    
    // Search for the element using binary search
    int result = binary_search(arr, size, element);
    
    // Print the result
    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }
    
    return 0;
}