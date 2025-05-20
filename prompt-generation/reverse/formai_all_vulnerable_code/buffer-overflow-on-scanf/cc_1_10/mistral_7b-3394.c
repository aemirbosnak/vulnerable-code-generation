//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

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
    int arr[MAX_SIZE];

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }
    }

    printf("Array: ");
    print_array(arr, size);

    printf("Enter the target integer: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    int index = binary_search(arr, size, target);

    if (index == -1) {
        printf("Target integer not found.\n");
    } else {
        printf("Target integer found at index %d.\n", index);
    }

    return 0;
}