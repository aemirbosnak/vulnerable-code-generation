//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Continue in the right half
        } else {
            right = mid - 1; // Continue in the left half
        }
    }
    return -1; // Target not found
}

// Function to display an array
void displayArray(int arr[], int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function that drives the program
int main() {
    printf("Welcome to the Exciting Searching Algorithm Program!\n");
    
    // Allocate memory for an array
    int size = 10;
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Fill the array with random numbers
    printf("Generating a random array of integers...\n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0-99
    }

    // Sort the array for binary search
    printf("Sorting the array...\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display the sorted array
    displayArray(arr, size);

    // Prompt user for a number to search
    int target;
    printf("Enter a number to search in the array: ");
    scanf("%d", &target);

    // Execute linear search
    printf("Performing a linear search for %d...\n", target);
    int linearResult = linearSearch(arr, size, target);
    if (linearResult != -1) {
        printf("Linear Search: Number %d found at index %d!\n", target, linearResult);
    } else {
        printf("Linear Search: Number %d not found in the array!\n", target);
    }

    // Execute binary search
    printf("Performing a binary search for %d...\n", target);
    int binaryResult = binarySearch(arr, size, target);
    if (binaryResult != -1) {
        printf("Binary Search: Number %d found at index %d!\n", target, binaryResult);
    } else {
        printf("Binary Search: Number %d not found in the array!\n", target);
    }

    // Clean up memory
    free(arr);
    printf("Thank you for using the Exciting Searching Algorithm Program! Goodbye!\n");
    
    return EXIT_SUCCESS;
}