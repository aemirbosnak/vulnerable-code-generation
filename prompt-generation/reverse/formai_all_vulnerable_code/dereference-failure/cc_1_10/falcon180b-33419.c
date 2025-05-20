//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int size;
    int capacity;
    int *data;
} IntArray;

void init(IntArray *array) {
    array->size = 0;
    array->capacity = 0;
    array->data = NULL;
}

void resize(IntArray *array, int new_capacity) {
    int *new_data = malloc(new_capacity * sizeof(int));
    memcpy(new_data, array->data, array->capacity * sizeof(int));
    free(array->data);
    array->data = new_data;
    array->capacity = new_capacity;
}

void push(IntArray *array, int value) {
    if (array->size >= array->capacity) {
        resize(array, array->capacity * 2);
    }
    array->data[array->size++] = value;
}

int pop(IntArray *array) {
    if (array->size == 0) {
        return INT_MIN;
    }
    return array->data[--array->size];
}

int main() {
    IntArray stack;
    init(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 7);
    push(&stack, 8);
    push(&stack, 9);
    push(&stack, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", pop(&stack));
    }
    return 0;
}