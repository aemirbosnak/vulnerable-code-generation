//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10000 // Maximum size of the array

// Function to perform binary search on the given array
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;

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

// Function to perform linear search on the given array
int linear_search(int arr[], int size, int target) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[MAX_SIZE], size, target, search_type, result;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    printf("Enter the search type (1 for binary search, 2 for linear search): ");
    scanf("%d", &search_type);

    if (search_type == 1) {
        result = binary_search(arr, size, target);
    } else if (search_type == 2) {
        result = linear_search(arr, size, target);
    } else {
        printf("Invalid search type.\n");
        return 0;
    }

    if (result == -1) {
        printf("Target not found in the array.\n");
    } else {
        printf("Target found at index %d.\n", result);
    }

    return 0;
}