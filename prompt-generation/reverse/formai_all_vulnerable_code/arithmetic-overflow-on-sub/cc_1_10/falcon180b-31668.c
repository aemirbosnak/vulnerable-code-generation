//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
// This program implements a binary search algorithm to find a target value in a sorted array of integers.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int binarySearch(int arr[], int target, int size);

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements in sorted order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, target, size);

    if (result == -1) {
        printf("Target value not found!\n");
    } else {
        printf("Target value found at index %d!\n", result);
    }

    return 0;
}

int binarySearch(int arr[], int target, int size) {
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

    return -1;
}