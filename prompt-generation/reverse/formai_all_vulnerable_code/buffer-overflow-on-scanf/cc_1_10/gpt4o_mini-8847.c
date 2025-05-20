//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define ARRAY_SIZE 10

// Function prototypes
void fillArray(int arr[], int size);
void displayArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);

int main() {
    int arr[ARRAY_SIZE];
    int target, index, choice;

    // Fill the array with random integers
    fillArray(arr, ARRAY_SIZE);

    // Display the original array
    printf("Original Array:\n");
    displayArray(arr, ARRAY_SIZE);

    // Ask user for the search method
    printf("Choose search method:\n1. Linear Search\n2. Binary Search\nEnter your choice: ");
    scanf("%d", &choice);

    // Prompt the user to input the target value to search for
    printf("Enter the number to search: ");
    scanf("%d", &target);

    if (choice == 2) {
        // Sort the array for binary search
        sortArray(arr, ARRAY_SIZE);
        printf("Sorted Array for Binary Search:\n");
        displayArray(arr, ARRAY_SIZE);
    }

    // Perform search based on the user's choice
    if (choice == 1) {
        index = linearSearch(arr, ARRAY_SIZE, target);
    } else if (choice == 2) {
        index = binarySearch(arr, ARRAY_SIZE, target);
    } else {
        printf("Invalid choice, please select 1 or 2.\n");
        return 1;
    }

    // Output the result
    if (index != -1) {
        printf("Number %d found at index %d.\n", target, index);
    } else {
        printf("Number %d not found in the array.\n", target);
    }
    
    return 0;
}

// Function to fill the array with random integers
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to display the array elements
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Linear search implementation
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Binary search implementation
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index if found
        }

        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if not found
}

// Function to sort the array using simple bubble sort
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}