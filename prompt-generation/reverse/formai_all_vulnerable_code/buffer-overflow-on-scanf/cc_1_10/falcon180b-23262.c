//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NOT_FOUND -1

int search(int arr[], int size, int target);

int main() {
    int arr[MAX_SIZE], size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int result = search(arr, size, target);

    if (result == NOT_FOUND) {
        printf("The target element was not found in the array.\n");
    } else {
        printf("The target element was found at index %d.\n", result);
    }

    return 0;
}

int search(int arr[], int size, int target) {
    int left = 0, right = size - 1;

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

    return NOT_FOUND;
}