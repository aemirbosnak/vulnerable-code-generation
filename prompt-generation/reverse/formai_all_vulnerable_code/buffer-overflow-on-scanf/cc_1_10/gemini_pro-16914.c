//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Custom binary search function
int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    // Loop until the search space is exhausted
    while (low <= high) {
        // Calculate the midpoint of the search space
        int mid = (low + high) / 2;

        // Check if the target is at the midpoint
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is less than the midpoint, search the left half
        else if (arr[mid] > target) {
            high = mid - 1;
        }

        // If the target is greater than the midpoint, search the right half
        else {
            low = mid + 1;
        }
    }

    // If the target was not found, return -1
    return -1;
}

// Custom interpolation search function
int interpolation_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    // Loop until the search space is exhausted
    while (low <= high) {
        // Calculate the interpolation position using the value of the target
        int pos = low + (((double) (target - arr[low]) / (arr[high] - arr[low])) * (high - low));

        // Check if the target is at the interpolation position
        if (arr[pos] == target) {
            return pos;
        }

        // If the target is less than the interpolation position, search the left half
        else if (arr[pos] > target) {
            high = pos - 1;
        }

        // If the target is greater than the interpolation position, search the right half
        else {
            low = pos + 1;
        }
    }

    // If the target was not found, return -1
    return -1;
}

// Custom exponential search function
int exponential_search(int arr[], int n, int target) {
    // Check if the target is at the first index
    if (arr[0] == target) {
        return 0;
    }

    // Calculate the initial search bound
    int bound = 1;
    while (bound < n && arr[bound] <= target) {
        bound *= 2;
    }

    // Binary search within the calculated bound
    int low = bound / 2, high = bound;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
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
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Search for the target using binary search
    int binary_result = binary_search(arr, n, target);

    // Search for the target using interpolation search
    int interpolation_result = interpolation_search(arr, n, target);

    // Search for the target using exponential search
    int exponential_result = exponential_search(arr, n, target);

    // Print the search results
    if (binary_result != -1) {
        printf("Binary search found the target at index %d\n", binary_result);
    } else {
        printf("Binary search did not find the target\n");
    }

    if (interpolation_result != -1) {
        printf("Interpolation search found the target at index %d\n", interpolation_result);
    } else {
        printf("Interpolation search did not find the target\n");
    }

    if (exponential_result != -1) {
        printf("Exponential search found the target at index %d\n", exponential_result);
    } else {
        printf("Exponential search did not find the target\n");
    }

    return 0;
}