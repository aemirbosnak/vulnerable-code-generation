//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the array

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[MAX_SIZE];
    int size, target;

    // Get size of array from user
    printf("Enter size of array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Get elements of array from user
    printf("Enter elements of array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get target element from user
    printf("Enter target element: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Print result
    if (result == -1) {
        printf("Target element not found!\n");
    } else {
        printf("Target element found at index %d!\n", result);
    }

    return 0;
}