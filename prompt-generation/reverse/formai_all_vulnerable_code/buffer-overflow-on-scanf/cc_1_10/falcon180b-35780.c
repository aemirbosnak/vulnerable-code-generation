//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Maximum size of array

int arr[MAX_SIZE]; // Declare array
int n; // Declare size of array

void createArray(int size);
void displayArray();
int binarySearch(int target);

int main() {
    printf("Enter size of array: ");
    scanf("%d", &n);

    createArray(n);

    int target;
    printf("Enter target value: ");
    scanf("%d", &target);

    int result = binarySearch(target);

    if (result == -1) {
        printf("Target value not found in array.\n");
    } else {
        printf("Target value found at index %d.\n", result);
    }

    return 0;
}

void createArray(int size) {
    printf("Enter %d integers:\n", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray() {
    printf("Array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
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

    return -1;
}