//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
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
    return -1; // target not found
}

// Function to perform binary search on the array
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
    return -1; // target not found
}

int main() {
    int arr[MAX_SIZE];
    int size, target;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target value from the user
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Perform linear search
    int result1 = linearSearch(arr, size, target);
    if (result1!= -1) {
        printf("Target found at index %d\n", result1);
    } else {
        printf("Target not found\n");
    }

    // Perform binary search
    int result2 = binarySearch(arr, size, target);
    if (result2!= -1) {
        printf("Target found at index %d\n", result2);
    } else {
        printf("Target not found\n");
    }

    return 0;
}