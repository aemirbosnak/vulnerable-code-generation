//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void create(int **array, int size);
int binarySearch(int *array, int size, int target);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    create(array, size);
    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = binarySearch(array, size, target);

    if (index == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", index);

    free(array);
    return 0;
}

void create(int **array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        (*array)[i] = rand() % 100;
    }
}

int binarySearch(int *array, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target)
            return mid;

        if (array[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}