//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdlib.h>
#include <stdio.h>

// Constants
#define ARRAY_SIZE 10

// Function prototypes
int linear_search(int arr[], int size, int target);
int binary_search(int arr[], int size, int target);

// Main function
int main() {
    // Initialize an array of integers
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // Get the target value from the user
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Perform linear search and print the result
    int linear_result = linear_search(arr, ARRAY_SIZE, target);
    if (linear_result == -1) {
        printf("Linear search: Target not found.\n");
    } else {
        printf("Linear search: Target found at index %d.\n", linear_result);
    }

    // Perform binary search and print the result
    int binary_result = binary_search(arr, ARRAY_SIZE, target);
    if (binary_result == -1) {
        printf("Binary search: Target not found.\n");
    } else {
        printf("Binary search: Target found at index %d.\n", binary_result);
    }

    return EXIT_SUCCESS;
}

// Linear search function
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

// Binary search function
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}