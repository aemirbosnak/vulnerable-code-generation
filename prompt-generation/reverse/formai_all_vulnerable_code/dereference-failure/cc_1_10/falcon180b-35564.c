//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    int size;
    int capacity;
} Array;

void init(Array *array) {
    array->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
}

void resize(Array *array) {
    array->capacity *= 2;
    array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
}

void push(Array *array, int value) {
    if (array->size == array->capacity) {
        resize(array);
    }
    array->data[array->size++] = value;
}

int pop(Array *array) {
    if (array->size == 0) {
        return -1;
    }
    return array->data[--array->size];
}

void printArray(Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    Array stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printArray(&stack);

    int poppedValue = pop(&stack);
    printf("Popped value: %d\n", poppedValue);

    printArray(&stack);

    return 0;
}