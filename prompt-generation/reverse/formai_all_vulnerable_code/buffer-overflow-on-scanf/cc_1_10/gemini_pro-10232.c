//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array to be searched
#define MAX_SIZE 100

// Declare the array to be searched
int arr[MAX_SIZE];

// Declare the function to perform the search
int search(int target);

// Main function
int main() {
    // Initialize the array with random values
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Print the array
    printf("Array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Get the target value from the user
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Perform the search
    int result = search(target);

    // Print the result
    if (result == -1) {
        printf("Target not found\n");
    } else {
        printf("Target found at index %d\n", result);
    }

    return 0;
}

// Function to perform the search
int search(int target) {
    // Iterate over the array
    for (int i = 0; i < MAX_SIZE; i++) {
        // Check if the current element is equal to the target
        if (arr[i] == target) {
            // Return the index of the target element
            return i;
        }
    }

    // Return -1 if the target element is not found
    return -1;
}