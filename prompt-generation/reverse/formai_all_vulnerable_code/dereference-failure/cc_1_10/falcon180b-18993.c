//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_SIZE 1000000
#define BLOCK_SIZE 100

typedef struct {
    int *data;
    uint32_t size;
    uint32_t capacity;
} DynamicArray;

DynamicArray *create_array(void) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(BLOCK_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = BLOCK_SIZE;
    return array;
}

void destroy_array(DynamicArray *array) {
    free(array->data);
    free(array);
}

void resize_array(DynamicArray *array) {
    array->capacity *= 2;
    array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
}

void push_array(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        resize_array(array);
    }
    array->data[array->size++] = value;
}

int pop_array(DynamicArray *array) {
    if (array->size == 0) {
        return -1;
    }
    return array->data[--array->size];
}

int main() {
    srand(time(NULL));

    DynamicArray *array = create_array();

    for (int i = 0; i < MAX_SIZE; ++i) {
        int value = rand() % 100;
        push_array(array, value);
    }

    for (int i = 0; i < MAX_SIZE; ++i) {
        int value = pop_array(array);
        printf("%d ", value);
    }

    destroy_array(array);

    return 0;
}