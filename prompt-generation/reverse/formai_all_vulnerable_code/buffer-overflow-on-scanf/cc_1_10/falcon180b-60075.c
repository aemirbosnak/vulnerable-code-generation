//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to search for a value in a sorted array
int search(int arr[], int n, int value) {
    // Initialize the left and right pointers
    int left = 0;
    int right = n - 1;

    // Loop until the left and right pointers cross each other
    while (left <= right) {
        // Calculate the middle index
        int mid = (left + right) / 2;

        // If the middle element is the value we're searching for, return its index
        if (arr[mid] == value) {
            return mid;
        }

        // If the middle element is greater than the value we're searching for, move the right pointer to the left of the middle index
        if (arr[mid] > value) {
            right = mid - 1;
        }

        // If the middle element is less than the value we're searching for, move the left pointer to the right of the middle index
        else {
            left = mid + 1;
        }
    }

    // If the value is not found in the array, return -1
    return -1;
}

int main() {
    // Initialize an array of integers
    int arr[] = { 2, 4, 7, 9, 11, 13, 15 };

    // Initialize the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Prompt the user to enter a value to search for
    printf("Enter a value to search for: ");
    int value;
    scanf("%d", &value);

    // Call the search function and store the result
    int result = search(arr, n, value);

    // Print the result
    if (result == -1) {
        printf("Value not found\n");
    }
    else {
        printf("Value found at index %d\n", result);
    }

    // Exit the program
    return 0;
}