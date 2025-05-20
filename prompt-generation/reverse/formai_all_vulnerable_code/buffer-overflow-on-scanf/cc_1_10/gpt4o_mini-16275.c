//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateSortedArray(int *arr, int size);
void displayArray(int *arr, int size);
int binarySearch(int *arr, int size, int target);

int main() {
    int size;
    
    printf("Welcome to the Intelligent Binary Search Program!\n");
    printf("Enter the size of the sorted array you want to create: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size must be greater than zero.\n");
        return 1;
    }

    // Allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Generate and display sorted array
    generateSortedArray(arr, size);
    printf("Generated Sorted Array:\n");
    displayArray(arr, size);

    int target;
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Free allocated memory
    free(arr);
    printf("Exited program gracefully.\n");
    return 0;
}

// Function to generate a sorted array with random numbers
void generateSortedArray(int *arr, int size) {
    srand(time(NULL)); // Seed random number generator
    arr[0] = rand() % 10; // Start with a small random number

    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + (rand() % 10 + 1); // Ensure the array is sorted
    }
}

// Function to display the array
void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Binary search function
int binarySearch(int *arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Return the index of the target
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    // Target was not found
    return -1;
}