//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int linear_search(int arr[], int size, int target);

int main() {
    int size, i, target, *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size is too large.\n");
        return 1;
    }

    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = linear_search(arr, size, target);

    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    free(arr);

    return 0;
}

int linear_search(int arr[], int size, int target) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}