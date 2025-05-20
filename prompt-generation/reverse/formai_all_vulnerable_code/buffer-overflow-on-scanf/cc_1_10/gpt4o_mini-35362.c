//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform a linear search on an array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}

// Function to perform a binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }
        // If target is greater, ignore left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

// Function to print array
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Initialize and define the peaceful array
    int peacefulArray[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(peacefulArray) / sizeof(peacefulArray[0]);
    
    // Display the array
    printArray(peacefulArray, size);

    // Prompt for user input
    int target;
    printf("Enter a number to search: ");
    scanf("%d", &target);

    // Perform linear search
    int linearResult = linearSearch(peacefulArray, size, target);
    if (linearResult != -1) {
        printf("Linear Search: Found %d at index %d.\n", target, linearResult);
    } else {
        printf("Linear Search: %d not found in the array.\n", target);
    }

    // Perform binary search
    int binaryResult = binarySearch(peacefulArray, size, target);
    if (binaryResult != -1) {
        printf("Binary Search: Found %d at index %d.\n", target, binaryResult);
    } else {
        printf("Binary Search: %d not found in the array.\n", target);
    }

    // Create a more peaceful conclusion
    printf("Thank you for using the peaceful searching program. May your inquiries always yield fruitful results!\n");

    return 0;
}