//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MIN_SIZE 10
#define INIT_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} IntArray;

IntArray createArray(int size) {
    IntArray array;
    array.data = (int *)malloc(size * sizeof(int));
    array.size = 0;
    array.capacity = size;
    return array;
}

void destroyArray(IntArray array) {
    free(array.data);
}

void resizeArray(IntArray *array, int newCapacity) {
    int *newData = (int *)malloc(newCapacity * sizeof(int));
    int oldCapacity = array->capacity;
    int oldSize = array->size;
    memcpy(newData, array->data, oldSize * sizeof(int));
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void push(IntArray *array, int value) {
    if (array->size == array->capacity) {
        resizeArray(array, array->capacity * 2);
    }
    array->data[array->size++] = value;
}

int pop(IntArray *array) {
    if (array->size == 0) {
        return -1;
    }
    return array->data[--array->size];
}

int peek(IntArray array, int index) {
    if (index < 0 || index >= array.size) {
        return -1;
    }
    return array.data[index];
}

int main() {
    srand(time(NULL));
    IntArray array = createArray(INIT_SIZE);
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        int value = rand() % 1000000;
        push(&array, value);
        int j;
        for (j = 0; j < i; j++) {
            if (peek(array, j)!= value) {
                printf("Error: Values do not match!\n");
                return 1;
            }
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        int value = pop(&array);
        if (value!= i + 1) {
            printf("Error: Values do not match!\n");
            return 1;
        }
    }
    destroyArray(array);
    return 0;
}