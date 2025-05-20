//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    bool found;
} search_result_t;

// Define a custom search function that takes a sorted array and a target value.
search_result_t search(int array[], int size, int target) {
    // Initialize the search result.
    search_result_t result = {0, false};

    // Perform binary search to find the target value.
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        // Calculate the midpoint of the current search range.
        int mid = (low + high) / 2;

        // Check if the target value is equal to the value at the midpoint.
        if (array[mid] == target) {
            // Set the found flag to true and update the result value.
            result.found = true;
            result.value = array[mid];
            break;
        } else if (array[mid] < target) {
            // If the target value is greater than the value at the midpoint,
            // update the low index to search the right half of the array.
            low = mid + 1;
        } else {
            // If the target value is less than the value at the midpoint,
            // update the high index to search the left half of the array.
            high = mid - 1;
        }
    }

    // Return the search result.
    return result;
}

int main() {
    // Create a sorted array of integers.
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(array) / sizeof(array[0]);

    // Get the target value from the user.
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Perform the search using the custom search function.
    search_result_t result = search(array, size, target);

    // Print the search result.
    if (result.found) {
        printf("Target value %d found at index %d.\n", result.value, result.value);
    } else {
        printf("Target value %d not found in the array.\n", target);
    }

    return 0;
}