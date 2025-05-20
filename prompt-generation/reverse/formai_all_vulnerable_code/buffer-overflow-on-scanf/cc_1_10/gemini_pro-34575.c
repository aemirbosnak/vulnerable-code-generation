//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to search for an element in the array using linear search
int linear_search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }

    return -1;
}

// Function to search for an element in the array using binary search
int binary_search(int arr[], int size, int element) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == element) {
            return mid;
        } else if (arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// Function to search for an element in the array using interpolation search
int interpolation_search(int arr[], int size, int element) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int position = low + (((high - low) / (arr[high] - arr[low])) * (element - arr[low]));

        if (arr[position] == element) {
            return position;
        } else if (arr[position] < element) {
            low = position + 1;
        } else {
            high = position - 1;
        }
    }

    return -1;
}

// Driver code to test the search algorithms
int main() {
    // Create an array of integers
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Get the element to search for from the user
    int element;
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    // Search for the element using linear search
    int linear_search_result = linear_search(arr, size, element);

    // Search for the element using binary search
    int binary_search_result = binary_search(arr, size, element);

    // Search for the element using interpolation search
    int interpolation_search_result = interpolation_search(arr, size, element);

    // Print the results of the search
    if (linear_search_result != -1) {
        printf("Linear search: Element found at index %d\n", linear_search_result);
    } else {
        printf("Linear search: Element not found\n");
    }

    if (binary_search_result != -1) {
        printf("Binary search: Element found at index %d\n", binary_search_result);
    } else {
        printf("Binary search: Element not found\n");
    }

    if (interpolation_search_result != -1) {
        printf("Interpolation search: Element found at index %d\n", interpolation_search_result);
    } else {
        printf("Interpolation search: Element not found\n");
    }

    return 0;
}