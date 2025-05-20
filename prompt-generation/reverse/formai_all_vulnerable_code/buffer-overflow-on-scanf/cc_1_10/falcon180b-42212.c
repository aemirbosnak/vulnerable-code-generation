//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to search for an element in the array
int search(int arr[], int size, int target) {
    int i;

    // Traverse through the array
    for (i = 0; i < size; i++) {
        // If the element is found, return its index
        if (arr[i] == target) {
            return i;
        }
    }

    // If the element is not found, return -1
    return -1;
}

int main() {
    int arr[MAX_SIZE], size, target;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the element to search for from the user
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Search for the element in the array
    int result = search(arr, size, target);

    // Print the result
    if (result == -1) {
        printf("Element not found in the array.\n");
    }
    else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}