//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 1000000

typedef struct {
    int *arr;
    size_t size;
} array;

void print_array(const array arr) {
    for (size_t i = 0; i < arr.size; ++i) {
        printf("%d ", arr.arr[i]);
    }
    printf("\n");
}

int recursive_search(const array arr, int target, size_t low, size_t high) {
    if (low > high)
        return -1;

    size_t mid = (low + high) / 2;

    if (arr.arr[mid] == target) {
        if (mid == low)
            return mid;

        int left = recursive_search(arr, target, low, mid - 1);
        if (left >= 0)
            return left;

        return mid + 1;
    } else if (arr.arr[mid] < target) {
        return recursive_search(arr, target, mid + 1, high);
    } else {
        return recursive_search(arr, target, low, mid - 1);
    }
}

void create_array(array *arr, size_t size) {
    arr->arr = malloc(size * sizeof(int));

    if (arr->arr == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    arr->size = size;
}

int main() {
    array arr;
    create_array(&arr, MAX_SIZE);

    for (size_t i = 0; i < MIN_SIZE; ++i) {
        scanf("%d", &arr.arr[i]);
    }

    arr.size = MIN_SIZE;
    print_array(arr);

    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    int index = recursive_search(arr, target, 0, arr.size - 1);

    if (index >= 0) {
        printf("Target '%d' found at index %ld.\n", target, index);
    } else {
        printf("Target '%d' not found.\n", target);
    }

    free(arr.arr);

    return EXIT_SUCCESS;
}