//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int arr[MAX];

void generateArray(int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int binarySearch(int arr[], int size, int target) {
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

    return -1;
}

int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    generateArray(size);
    printf("The generated array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter the target element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result == -1) {
        printf("\nElement not found in the array!");
    } else {
        printf("\nElement found at index %d", result);
    }

    return 0;
}