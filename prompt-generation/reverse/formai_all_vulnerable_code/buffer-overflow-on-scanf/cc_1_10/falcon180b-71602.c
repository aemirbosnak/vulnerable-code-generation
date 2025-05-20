//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

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

    return -1; // Target not found
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target value from the user
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Perform linear search
    int result1 = linearSearch(arr, size, target);

    // Perform binary search
    int result2 = binarySearch(arr, size, target);

    // Print the results
    if (result1!= -1) {
        printf("Linear search found the target at position %d.\n", result1);
    } else {
        printf("Linear search did not find the target.\n");
    }

    if (result2!= -1) {
        printf("Binary search found the target at position %d.\n", result2);
    } else {
        printf("Binary search did not find the target.\n");
    }

    return 0;
}