//Falcon-180B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *create_array() {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    arr->data = (int *)malloc(MAX_SIZE * sizeof(int));
    if (arr->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = MAX_SIZE;
    return arr;
}

void destroy_array(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

void resize_array(DynamicArray *arr) {
    int *new_data = (int *)malloc(arr->capacity * 2 * sizeof(int));
    if (new_data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    memcpy(new_data, arr->data, arr->size * sizeof(int));
    free(arr->data);
    arr->data = new_data;
    arr->capacity *= 2;
}

void add_element(DynamicArray *arr, int element) {
    if (arr->size == arr->capacity) {
        resize_array(arr);
    }
    arr->data[arr->size++] = element;
}

int main() {
    DynamicArray *arr = create_array();
    int i;
    for (i = 0; i < 10; i++) {
        add_element(arr, i);
    }
    for (i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
    destroy_array(arr);
    return 0;
}