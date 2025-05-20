//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int n;

void createArray(int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    n = size;
}

int binarySearch(int target) {
    int left = 0;
    int right = n - 1;

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

    return -1; // target not found
}

int main() {
    int size;
    printf("Enter the size of the array (<= %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    createArray(size);
    printf("Enter the target integer to search for:\n");
    int target = scanf("%d", &target);

    int result = binarySearch(target);

    if (result == -1) {
        printf("Target not found in the array.\n");
    } else {
        printf("Target found at index %d.\n", result);
    }

    return 0;
}