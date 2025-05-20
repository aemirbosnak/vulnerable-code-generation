//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void print_array(int arr[]) {
    int i;
    printf("Array elements are:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binary_search(int arr[], int target, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return binary_search(arr, target, mid + 1, high);
    } else {
        return binary_search(arr, target, low, mid - 1);
    }
}

int main() {
    int arr[SIZE], target, index;

    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    print_array(arr);

    printf("Enter the target integer to search:\n");
    scanf("%d", &target);

    index = binary_search(arr, target, 0, SIZE - 1);

    if (index == -1) {
        printf("Target integer %d not found in the array.\n", target);
    } else {
        printf("Target integer %d found at index %d.\n", target, index);
    }

    return 0;
}