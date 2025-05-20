//Falcon-180B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int capacity;
    int size;
} IntArray;

IntArray *createIntArray() {
    IntArray *array = malloc(sizeof(IntArray));
    if (array == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }
    array->data = NULL;
    array->capacity = 0;
    array->size = 0;
    return array;
}

void destroyIntArray(IntArray *array) {
    if (array->data!= NULL) {
        free(array->data);
        array->data = NULL;
        array->capacity = 0;
        array->size = 0;
    }
}

void resizeIntArray(IntArray *array, int newCapacity) {
    if (newCapacity <= array->capacity) {
        return;
    }
    int *newData = malloc(sizeof(int) * newCapacity);
    if (newData == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void addIntToArray(IntArray *array, int value) {
    if (array->size == array->capacity) {
        resizeIntArray(array, array->capacity * 2);
    }
    array->data[array->size++] = value;
}

int removeIntFromArray(IntArray *array, int index) {
    if (index >= array->size) {
        return -1;
    }
    int value = array->data[index];
    int i;
    for (i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
    if (array->size < array->capacity / 4) {
        resizeIntArray(array, array->capacity / 2);
    }
    return value;
}

void printIntArray(IntArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray *array = createIntArray();
    addIntToArray(array, 1);
    addIntToArray(array, 2);
    addIntToArray(array, 3);
    addIntToArray(array, 4);
    addIntToArray(array, 5);
    addIntToArray(array, 6);
    addIntToArray(array, 7);
    addIntToArray(array, 8);
    addIntToArray(array, 9);
    addIntToArray(array, 10);
    printIntArray(array);
    int value = removeIntFromArray(array, 3);
    printf("Removed value: %d\n", value);
    printIntArray(array);
    destroyIntArray(array);
    return 0;
}