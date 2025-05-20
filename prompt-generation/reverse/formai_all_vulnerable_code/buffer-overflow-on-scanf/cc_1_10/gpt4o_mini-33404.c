//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function prototypes
void initializeArray(int arr[], int size);
void displayArray(const int arr[], int size);
int linearSearch(const int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size, choice, target, position;

    // Initialize random seed for array generation
    srand(time(NULL));

    printf("Welcome to the Searching Algorithm Demonstration!\n");
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Initialize the array with random numbers
    initializeArray(arr, size);
    printf("Generated Array:\n");
    displayArray(arr, size);

    do {
        printf("\nSelect a searching method:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search (requires sorted array)\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to search (Linear Search): ");
                scanf("%d", &target);
                position = linearSearch(arr, size, target);
                if (position != -1) {
                    printf("Element %d found at index: %d\n", target, position);
                } else {
                    printf("Element %d not found in the array.\n", target);
                }
                break;

            case 2:
                sortArray(arr, size);
                printf("Sorted Array:\n");
                displayArray(arr, size);
                printf("Enter the number to search (Binary Search): ");
                scanf("%d", &target);
                position = binarySearch(arr, size, target);
                if (position != -1) {
                    printf("Element %d found at index: %d\n", target, position);
                } else {
                    printf("Element %d not found in the array.\n", target);
                }
                break;

            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

// Function to initialize the array with random integers
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to display the contents of the array
void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform linear search
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found at index i
        }
    }
    return -1; // Target not found
}

// Function to sort the array for binary search
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found at index mid
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}