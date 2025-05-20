//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

void array_init(Array *array) {
    array->data = (int *) malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
}

void array_append(Array *array, int value) {
    if (array->size >= MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }
    array->data[array->size++] = value;
}

int array_get(Array *array, int index) {
    if (index < 0 || index >= array->size) {
        printf("Error: Index out of bounds.\n");
        return -1;
    }
    return array->data[index];
}

void array_free(Array *array) {
    free(array->data);
}

int main() {
    Array arr;
    array_init(&arr);
    for (int i = 0; i < 10; i++) {
        array_append(&arr, i * i);
    }
    int sum = 0;
    for (int i = 0; i < arr.size; i++) {
        sum += arr.data[i];
    }
    printf("Sum of elements: %d\n", sum);
    array_free(&arr);
    return 0;
}