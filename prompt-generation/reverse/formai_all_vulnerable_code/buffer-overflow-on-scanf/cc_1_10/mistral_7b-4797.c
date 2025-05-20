//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 10

typedef struct {
    int* arr;
    int size;
} DynamicArray;

DynamicArray create_array(int size) {
    DynamicArray array;

    if (size <= 0 || size > MAX_INPUT) {
        fprintf(stderr, "Invalid input size. Size must be between 1 and %d\n", MAX_INPUT);
        array.arr = NULL;
        array.size = 0;
        return array;
    }

    array.arr = (int*) malloc(sizeof(int) * size);

    if (array.arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        array.size = 0;
    } else {
        array.size = size;
    }

    return array;
}

void destroy_array(DynamicArray array) {
    if (array.arr != NULL) {
        free(array.arr);
    }
}

void print_array(DynamicArray array) {
    int i;

    if (array.size == 0) {
        printf("Empty array\n");
        return;
    }

    printf("[");
    for (i = 0; i < array.size; i++) {
        printf("%d", array.arr[i]);
        if (i < array.size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    DynamicArray arr;
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = create_array(size);

    if (arr.size == 0) {
        return 1;
    }

    for (i = 0; i < arr.size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr.arr[i]);
    }

    print_array(arr);

    destroy_array(arr);

    return 0;
}