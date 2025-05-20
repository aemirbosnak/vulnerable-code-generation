//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to perform linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

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
    int size, target;

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt the user to enter the target value to search for
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Perform linear search and print the result
    int index = linear_search(arr, size, target);
    if (index!= -1) {
        printf("The target value %d was found at index %d.\n", target, index);
    } else {
        printf("The target value %d was not found in the array.\n", target);
    }

    // Perform binary search and print the result
    index = binary_search(arr, size, target);
    if (index!= -1) {
        printf("The target value %d was found at index %d using binary search.\n", target, index);
    } else {
        printf("The target value %d was not found in the array using binary search.\n", target);
    }

    return 0;
}