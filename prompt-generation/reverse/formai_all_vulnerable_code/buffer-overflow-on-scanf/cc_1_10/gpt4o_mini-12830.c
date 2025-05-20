//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function to perform a linear search in the array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target found
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to perform a binary search on a sorted array
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid point
        if (arr[mid] == target) {
            return mid; // Target found
        }
        if (arr[mid] < target) {
            left = mid + 1; // Target is on the right side
        } else {
            right = mid - 1; // Target is on the left side
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to validate the integer input from the user
int getValidInput() {
    int input;
    while (1) {
        printf("Please enter a number: ");
        if (scanf("%d", &input) == 1) {
            while (getchar() != '\n'); // Clear the input buffer
            break; // Valid input received
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
    return input;
}

// Function to dynamically create an array and populate it
int* createArray(int size) {
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        arr[i] = getValidInput();
    }
    return arr;
}

// Function to sort the array using the bubble sort algorithm
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

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    printf("Array elements: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    size = getValidInput();

    // Create and populate the array
    int* arr = createArray(size);

    // Display the unsorted array
    printf("Unsorted ");
    displayArray(arr, size);

    // Sort the array using bubble sort
    bubbleSort(arr, size);

    // Display the sorted array
    printf("Sorted ");
    displayArray(arr, size);

    // Get the target value to search for
    printf("Enter the number you want to search for: ");
    int target = getValidInput();

    // Perform linear search
    int linearResult = linearSearch(arr, size, target);
    if (linearResult != -1) {
        printf("Linear Search: Number %d found at index %d\n", target, linearResult);
    } else {
        printf("Linear Search: Number %d not found in the array\n", target);
    }

    // Perform binary search
    int binaryResult = binarySearch(arr, 0, size - 1, target);
    if (binaryResult != -1) {
        printf("Binary Search: Number %d found at index %d\n", target, binaryResult);
    } else {
        printf("Binary Search: Number %d not found in the array\n", target);
    }

    // Free allocated memory
    free(arr);
    return 0;
}