//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to perform linear search on the given array
int linearSearch(int arr[], int size, int target) {
    int i;

    // Iterate through the array and compare each element with the target
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            // Target found at index i, return the index
            return i;
        }
    }

    // Target not found in the array, return -1
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size, target, result;

    // Get the size of the array from the user
    printf("Enter the size of the array (maximum 100): ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target value from the user
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Perform linear search on the array
    result = linearSearch(arr, size, target);

    // Print the result of the search
    if (result == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index %d.\n", result);
    }

    return 0;
}