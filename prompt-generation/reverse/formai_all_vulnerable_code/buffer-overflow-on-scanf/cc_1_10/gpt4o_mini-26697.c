//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Define maximum size of the array

// Function prototypes
void inputArray(int arr[], int size);
void displayArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);

// Main function
int main() {
    int arr[MAX_SIZE];
    int size, choice, target, result;

    printf("Welcome to the Searching Algorithm Program\n");
    printf("Please enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size! Please run the program again.\n");
        return 1;
    }

    // Input array elements
    inputArray(arr, size);

    // Display the array
    printf("\nThe input array is:\n");
    displayArray(arr, size);

    // Ask user for the search option
    printf("\nChoose a search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Requires sorted array)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Process according to user choice
    if (choice == 1 || choice == 2) {
        printf("Enter the target value to search for: ");
        scanf("%d", &target);
    } else {
        printf("Invalid choice! Please run the program again.\n");
        return 1;
    }

    // Handling the search based on user choice
    if (choice == 1) {
        result = linearSearch(arr, size, target);
        if (result != -1) {
            printf("Linear Search: Element %d found at index %d.\n", target, result);
        } else {
            printf("Linear Search: Element %d not found in the array.\n", target);
        }
    } else if (choice == 2) {
        sortArray(arr, size); // Sort the array before binary search
        printf("\nThe sorted array is:\n");
        displayArray(arr, size);

        result = binarySearch(arr, size, target);
        if (result != -1) {
            printf("Binary Search: Element %d found at index %d.\n", target, result);
        } else {
            printf("Binary Search: Element %d not found in the array.\n", target);
        }
    }

    return 0;
}

// Function to input array elements from the user
void inputArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function for Binary Search (requires sorted array)
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target)
            return mid; // Return index if found

        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }
    return -1; // Return -1 if not found
}

// Function to sort the array using Bubble Sort
void sortArray(int arr[], int size) {
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