//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1

typedef struct {
    int *arr;
    int size;
    int capacity;
} Array;

void initialize(Array *arr, int size) {
    arr->arr = (int *)calloc(size, sizeof(int));
    if (arr->arr == NULL) {
        printf("Error: Failed to allocate memory for array.\n");
        exit(EXIT_FAILURE);
    }
    arr->size = size;
    arr->capacity = size;
}

void resize(Array *arr, int new_capacity) {
    int *new_arr = (int *)realloc(arr->arr, new_capacity * sizeof(int));
    if (new_arr == NULL) {
        printf("Error: Failed to allocate memory for new array.\n");
        exit(EXIT_FAILURE);
    }
    arr->arr = new_arr;
    arr->capacity = new_capacity;
}

int binary_search(int *arr, int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    Array arr;
    int size, new_size, element, search_element;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    initialize(&arr, size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &element);
        arr.arr[i] = element;
    }

    printf("Enter the element to search: ");
    scanf("%d", &search_element);

    int index = binary_search(arr.arr, size, search_element);

    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    printf("Enter the new size of the array: ");
    scanf("%d", &new_size);

    resize(&arr, new_size);

    printf("Enter %d new elements:\n", new_size - size);
    for (int i = size; i < size + new_size; ++i) {
        scanf("%d", &element);
        arr.arr[i] = element;
    }

    printf("Updated array: ");
    for (int i = 0; i < arr.size; ++i) {
        printf("%d ", arr.arr[i]);
    }
    printf("\n");

    free(arr.arr);

    return 0;
}