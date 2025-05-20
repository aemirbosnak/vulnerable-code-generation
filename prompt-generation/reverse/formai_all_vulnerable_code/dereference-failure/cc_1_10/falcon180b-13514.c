//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to perform linear search on the array
int linearSearch(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search on the array
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size, target, choice, result;

    // Prompt user to enter the size of the array
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt user to choose the search algorithm
    printf("Choose the search algorithm:\n1. Linear search\n2. Binary search\n");
    scanf("%d", &choice);

    // Perform the search based on the user's choice
    if (choice == 1) {
        printf("Enter the target element: ");
        scanf("%d", &target);
        result = linearSearch(arr, size, target);
    } else if (choice == 2) {
        printf("Enter the target element: ");
        scanf("%d", &target);
        result = binarySearch(arr, size, target);
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    // Print the result of the search
    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at position %d.\n", result);
    }

    return 0;
}