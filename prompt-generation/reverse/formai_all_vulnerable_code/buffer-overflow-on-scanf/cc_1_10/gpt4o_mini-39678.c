//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
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
    return -1; // Target not found
}

// Function to print the array for debugging purposes
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to demonstrate binary search
void demoBinarySearch() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    printArray(arr, size);

    int target;
    printf("Enter a number to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
}

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}

// Function to demonstrate linear search
void demoLinearSearch() {
    int arr[] = {15, 22, 34, 54, 2, 98, 23, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray for Linear Search: ");
    printArray(arr, size);

    int target;
    printf("Enter a number to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
}

// Main function
int main() {
    printf("Welcome to the Searching Algorithm Demo!\n");
    printf("1. Binary Search\n");
    printf("2. Linear Search\n");
    printf("Please select an option (1 or 2): ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            demoBinarySearch();
            break;
        case 2:
            demoLinearSearch();
            break;
        default:
            printf("Invalid choice. Please choose 1 or 2.\n");
    }

    return 0;
}