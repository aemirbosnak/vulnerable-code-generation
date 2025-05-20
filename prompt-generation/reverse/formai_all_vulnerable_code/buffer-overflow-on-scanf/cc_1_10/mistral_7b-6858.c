//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int g_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int arr[SIZE];

    printf("Enter %d integers:\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the value to search for: ");
    scanf("%d", &target);

    int index = g_search(arr, SIZE, target);

    if (index == -1) {
        printf("Value %d not found in the array.\n", target);
    } else {
        printf("Value %d found at index %d.\n", target, index);
    }

    return 0;
}

// Function to print the array
void print_array(int arr[], int size) {
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b]\n");
}