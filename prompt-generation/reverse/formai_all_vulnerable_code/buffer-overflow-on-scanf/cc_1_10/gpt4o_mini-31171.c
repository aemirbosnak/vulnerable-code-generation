//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    
    return -1; // Target not found
}

// Function to take user input for an array
void inputArray(int arr[], int size) {
    printf("Enter %d sorted integers:\n", size);
    for (int i = 0; i < size; i++) {
        while (1) {
            printf("Element %d: ", i + 1);
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. Please enter an integer.\n");
                while(getchar() != '\n'); // Clear invalid input
            } else {
                break; // Valid input, break the loop
            }
        }
    }
}

// Function to search for a target value in the array
void searchValue(int arr[], int size) {
    int target;
    
    // Get the target to search for
    printf("Enter the integer value to search for: ");
    while (1) {
        if (scanf("%d", &target) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while(getchar() != '\n'); // Clear invalid input
        } else {
            break; // Valid input, break the loop
        }
    }

    // Perform binary search
    int index = binarySearch(arr, size, target);
    
    // Output the result
    if (index != -1) {
        printf("Value %d found at index %d.\n", target, index);
    } else {
        printf("Value %d not found in the array.\n", target);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get size of the array ensuring it is within the limits
    printf("Enter the size of the array (1 - %d): ", MAX_SIZE);
    while (1) {
        if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_SIZE);
            while (getchar() != '\n'); // Clear invalid input
        } else {
            break; // Valid input, break the loop
        }
    }

    // Input the array elements
    inputArray(arr, size);
    
    // Perform the search operation
    searchValue(arr, size);
    
    return 0;
}