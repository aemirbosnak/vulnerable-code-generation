//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Declare the binary search function
int binary_search(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    // While the low index is less than or equal to the high index
    while (low <= high) {
        // Calculate the mid index
        int mid = (low + high) / 2;

        // Check if the element at the mid index is equal to the target value
        if (arr[mid] == x) {
            // Return the mid index
            return mid;
        }
        // If the element at the mid index is less than the target value, update the low index
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        // If the element at the mid index is greater than the target value, update the high index
        else {
            high = mid - 1;
        }
    }

    // If the target value is not found, return -1
    return -1;
}

int main() {
    // Declare an array of integers
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Get the target value from the user
    int x;
    printf("Enter the target value: ");
    scanf("%d", &x);

    // Call the binary search function
    int result = binary_search(arr, n, x);

    // Print the result
    if (result == -1) {
        printf("The target value is not found.\n");
    } else {
        printf("The target value is found at index %d.\n", result);
    }

    return 0;
}