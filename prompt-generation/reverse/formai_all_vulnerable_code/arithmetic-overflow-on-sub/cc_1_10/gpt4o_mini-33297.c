//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 1000

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform a linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Found the target, return index
        }
    }
    return -1; // Target not found
}

// Function to perform a binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Found the target, return index
        }
        if (arr[mid] < target) {
            left = mid + 1; // Target is on the right side
        } else {
            right = mid - 1; // Target is on the left side
        }
    }
    return -1; // Target not found
}

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size, int lower, int upper) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation

    int size, target, result;
    int arr[MAX_ELEMENTS];

    printf("Welcome to the Searching Algorithm Demonstration!\n");
    printf("Enter the number of elements (max %d): ", MAX_ELEMENTS);
    scanf("%d", &size);

    if (size > MAX_ELEMENTS) {
        printf("Size exceeds maximum limit. Setting size to %d.\n", MAX_ELEMENTS);
        size = MAX_ELEMENTS;
    }

    generateRandomNumbers(arr, size, 1, 100); // Generate random numbers between 1 and 100
    printf("Generated Array:\n");
    printArray(arr, size);

    // Perform linear search
    printf("Enter the target number to search (Linear Search): ");
    scanf("%d", &target);
    result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Linear Search: Target %d found at index %d.\n", target, result);
    } else {
        printf("Linear Search: Target %d not found.\n", target);
    }

    // Sort the array for binary search
    bubbleSort(arr, size);
    printf("Sorted Array for Binary Search:\n");
    printArray(arr, size);

    // Perform binary search
    printf("Enter the target number to search (Binary Search): ");
    scanf("%d", &target);
    result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Binary Search: Target %d found at index %d.\n", target, result);
    } else {
        printf("Binary Search: Target %d not found.\n", target);
    }

    return 0;
}