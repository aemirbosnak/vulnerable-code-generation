//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the element is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        } else { // If target is smaller, ignore the right half
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

// Function to handle user input and initiate the search
void searchElement(int arr[], int size) {
    int target;
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to initialize and fill the array with random numbers
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Fill with random numbers between 0 to 99
    }
}

// Function to sort the array using bubble sort (simple sorting method)
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

// Entry point of the program
int main() {
    int size;

    // Seed the random number generator
    srand(time(NULL));

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Validate input for size
    if (size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int)); // Allocate memory for array

    // Initialize the array
    initializeArray(arr, size);

    // Print the original array
    printArray(arr, size);

    // Sort the array
    bubbleSort(arr, size);

    // Print the sorted array
    printf("Sorted ");
    printArray(arr, size);

    // Perform the search
    searchElement(arr, size);

    // Free the allocated memory
    free(arr);

    return 0;
}