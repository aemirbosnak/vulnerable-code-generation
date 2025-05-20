//Falcon-180B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int capacity;
    int size;
} IntArray;

void init(IntArray *array) {
    array->data = (int *) malloc(MAX_SIZE * sizeof(int));
    array->capacity = MAX_SIZE;
    array->size = 0;
}

void destroy(IntArray *array) {
    free(array->data);
}

void resize(IntArray *array) {
    int *new_data = (int *) realloc(array->data, array->capacity * 2 * sizeof(int));
    if (new_data == NULL) {
        printf("Failed to resize array.\n");
        exit(1);
    }
    array->data = new_data;
    array->capacity *= 2;
}

void push(IntArray *array, int value) {
    if (array->size == array->capacity) {
        resize(array);
    }
    array->data[array->size++] = value;
}

int pop(IntArray *array) {
    if (array->size == 0) {
        printf("Array is empty.\n");
        exit(1);
    }
    return array->data[--array->size];
}

int peek(IntArray *array) {
    if (array->size == 0) {
        printf("Array is empty.\n");
        exit(1);
    }
    return array->data[array->size - 1];
}

void print(IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray array;
    init(&array);

    push(&array, 1);
    push(&array, 2);
    push(&array, 3);
    push(&array, 4);
    push(&array, 5);

    print(&array);

    int value = pop(&array);
    printf("Popped value: %d\n", value);

    print(&array);

    destroy(&array);

    return 0;
}