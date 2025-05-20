//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Target found
        }
    }
    return -1;  // Target not found
}

// Function to perform Binary Search (requires sorted array)
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == target) {
            return middle;  // Target found
        }
        if (arr[middle] < target) {
            left = middle + 1;  // Adjust the search space right
        } else {
            right = middle - 1; // Adjust the search space left
        }
    }
    return -1;  // Target not found
}

// Function to display the current shape of the array
void displayArray(int arr[], int size) {
    printf("Current array: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Function to create and shuffle an array
void createArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers in the range of 0-99
    }
}

// Shape shifting main function to select the search method
int main() {
    srand(time(0)); // Seed for random number generation

    int size = 10; // Size of the array
    int arr[size]; // Declaration of the array
    createArray(arr, size); // Fill the array with random numbers

    printf("Welcome to the Shape Shifting Search Program!\n");
    displayArray(arr, size);

    int choice;
    printf("Choose your search shape (1 - Linear, 2 - Binary): ");
    scanf("%d", &choice);

    // Linear search path
    if (choice == 1) {
        int target;
        printf("You have chosen to search in a linear shape!\n");
        printf("Enter the number to search: ");
        scanf("%d", &target);
        
        int result = linearSearch(arr, size, target);
        if (result != -1) {
            printf("Found %d in linear search at index %d!\n", target, result);
        } else {
            printf("%d not found in the linear search!\n", target);
        }
    }
    // Binary search path
    else if (choice == 2) {
        // First we need to sort the array to apply binary search
        printf("You've chosen the sharp-edged binary shape!\n");
        // Simple bubble sort to sort the array before binary search
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        displayArray(arr, size); // Show the sorted array

        int target;
        printf("Enter the number to search: ");
        scanf("%d", &target);

        int result = binarySearch(arr, 0, size - 1, target);
        if (result != -1) {
            printf("Found %d in binary search at index %d!\n", target, result);
        } else {
            printf("%d not found in the binary search!\n", target);
        }
    } else {
        printf("Invalid choice, please restart and choose either 1 or 2.\n");
    }

    return 0; // End of program
}