//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Custom binary search algorithm
int custom_binary_search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    // Loop until the interval [left, right] is empty
    while (left <= right) {
        // Calculate the midpoint of the interval
        int mid = (left + right) / 2;

        // Check if the target is equal to the element at the midpoint
        if (arr[mid] == target) {
            return mid;  // Target found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1;  // Target is in the right half
        } else {
            right = mid - 1;  // Target is in the left half
        }
    }

    // Target not found
    return -1;
}

// Custom interpolation search algorithm
int custom_interpolation_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    // Loop until the interval [low, high] is empty
    while (low <= high) {
        // Calculate the interpolation point
        int pos = low + (((double)(target - arr[low]) / (arr[high] - arr[low])) * (high - low));

        // Check if the target is equal to the element at the interpolation point
        if (arr[pos] == target) {
            return pos;  // Target found, return its index
        } else if (arr[pos] < target) {
            low = pos + 1;  // Target is in the right half
        } else {
            high = pos - 1;  // Target is in the left half
        }
    }

    // Target not found
    return -1;
}

int main() {
    // Initialize an array of integers
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Get the target value from the user
    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Perform binary search
    int binary_result = custom_binary_search(arr, n, target);
    if (binary_result != -1) {
        printf("Target found using binary search at index %d\n", binary_result);
    } else {
        printf("Target not found using binary search\n");
    }

    // Perform interpolation search
    int interpolation_result = custom_interpolation_search(arr, n, target);
    if (interpolation_result != -1) {
        printf("Target found using interpolation search at index %d\n", interpolation_result);
    } else {
        printf("Target not found using interpolation search\n");
    }

    return 0;
}