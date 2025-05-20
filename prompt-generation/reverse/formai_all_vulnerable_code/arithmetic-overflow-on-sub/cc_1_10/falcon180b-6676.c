//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of array

void binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            return;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Element not found\n");
}

int main() {
    int arr[MAX_SIZE];
    int size, target;

    // Get size of array from user
    printf("Enter size of array (max %d): ", MAX_SIZE);
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
    binarySearch(arr, size, target);

    return 0;
}