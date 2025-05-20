//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// A custom searching algorithm that combines binary search with linear interpolation
int search(int *arr, int n, int target) {
    // Check if the array is empty or the target is out of range
    if (n <= 0 || target < arr[0] || target > arr[n-1]) {
        return -1;
    }

    // Perform binary search to quickly narrow down the search range
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // If the exact target value was not found using binary search, perform linear interpolation to estimate its position
    if (arr[low] < target && target < arr[low + 1]) {
        double fraction = (double)(target - arr[low]) / (arr[low + 1] - arr[low]);
        int interpolated_index = low + (int)(fraction * (low + 1 - low));
        return interpolated_index;
    }

    // If the target was not found, return -1
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

    // Perform the search using the custom algorithm
    int index = search(arr, n, target);

    // Print the result
    if (index != -1) {
        printf("The target value %d was found at index %d.\n", target, index);
    } else {
        printf("The target value %d was not found in the array.\n", target);
    }

    return 0;
}