//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the array

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

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

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[MAX_SIZE];
    int size, target, choice;

    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    printf("Choose the search algorithm:\n1. Binary search\n2. Linear search\n");
    scanf("%d", &choice);

    int result;

    switch (choice) {
        case 1:
            result = binarySearch(arr, size, target);
            break;
        case 2:
            result = linearSearch(arr, size, target);
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 0;
    }

    if (result == -1) {
        printf("Target not found in the array.\n");
    } else {
        printf("Target found at index %d.\n", result);
    }

    return 0;
}