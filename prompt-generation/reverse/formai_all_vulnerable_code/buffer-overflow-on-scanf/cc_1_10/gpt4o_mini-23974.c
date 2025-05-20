//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform linear search in an array
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if element is not found
}

// Function to perform binary search in a sorted array
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid index

        if (arr[mid] == target) {
            return mid; // Return the index of the found element
        }
        if (arr[mid] < target) {
            left = mid + 1; // Move the left index to mid + 1
        } else {
            right = mid - 1; // Move the right index to mid - 1
        }
    }
    return -1; // Return -1 if element is not found
}

// Function to display the array
void display_array(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to fill the array with random numbers
void fill_array(int arr[], int size, int upper_bound) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % upper_bound; // Generate random number between 0 and upper_bound
    }
}

// Function to sort the array using bubble sort algorithm
void bubble_sort(int arr[], int size) {
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

// Main function to demonstrate searching algorithms
int main() {
    int size = 10; // Set size of the array
    int upper_bound = 100; // Set upper bound for random numbers
    int arr[size];
    int target;

    // Fill the array with random numbers
    fill_array(arr, size, upper_bound);

    // Display the unsorted array
    printf("Unsorted ");
    display_array(arr, size);

    // Sort the array using bubble sort
    bubble_sort(arr, size);

    // Display the sorted array
    printf("Sorted ");
    display_array(arr, size);

    // Ask user for a target number to search
    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Perform linear search
    int linear_result = linear_search(arr, size, target);
    if (linear_result != -1) {
        printf("Linear Search: %d found at index %d\n", target, linear_result);
    } else {
        printf("Linear Search: %d not found\n", target);
    }

    // Perform binary search
    int binary_result = binary_search(arr, size, target);
    if (binary_result != -1) {
        printf("Binary Search: %d found at index %d\n", target, binary_result);
    } else {
        printf("Binary Search: %d not found\n", target);
    }

    return 0;
}