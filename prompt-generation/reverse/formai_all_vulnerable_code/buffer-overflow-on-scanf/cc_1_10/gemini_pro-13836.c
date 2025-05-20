//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the possible search methods
#define LINEAR_SEARCH 1
#define BINARY_SEARCH 2

// Function to linearly search for an element in an array
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to binary search for an element in a sorted array
int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Main function
int main() {
    // Create an array of integers
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Get the target element from the user
    int target;
    printf("Enter the element you want to search for: ");
    scanf("%d", &target);

    // Select the search method
    int search_method;
    printf("Select the search method (1 for linear search, 2 for binary search): ");
    scanf("%d", &search_method);

    // Perform the search and print the result
    int result;
    switch (search_method) {
        case LINEAR_SEARCH:
            result = linear_search(arr, size, target);
            break;
        case BINARY_SEARCH:
            result = binary_search(arr, size, target);
            break;
        default:
            printf("Invalid search method selected.\n");
            return 1;
    }

    if (result == -1) {
        printf("The element %d was not found in the array.\n", target);
    } else {
        printf("The element %d was found at index %d.\n", target, result);
    }

    return 0;
}