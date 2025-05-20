//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform binary search
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

int main() {
    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value: ");
    int target;
    scanf("%d", &target);

    if (target < 0 || target > size || size <= 0) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    int index = binarySearch(arr, size, target);
    if (index == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index %d.\n", index);
    }

    return 0;
}