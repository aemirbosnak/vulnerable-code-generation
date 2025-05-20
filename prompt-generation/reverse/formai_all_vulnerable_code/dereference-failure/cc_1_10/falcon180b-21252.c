//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

typedef struct {
    Element *elements;
    int size;
    int capacity;
} Array;

void initArray(Array *array) {
    array->elements = (Element *)malloc(MAX_SIZE * sizeof(Element));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void resizeArray(Array *array) {
    array->capacity *= 2;
    Element *newElements = (Element *)malloc(array->capacity * sizeof(Element));
    for (int i = 0; i < array->size; i++) {
        newElements[i].data = array->elements[i].data;
        newElements[i].index = array->elements[i].index;
    }
    free(array->elements);
    array->elements = newElements;
}

void addElement(Array *array, int data) {
    if (array->size == array->capacity) {
        resizeArray(array);
    }
    array->elements[array->size].data = data;
    array->elements[array->size].index = array->size;
    array->size++;
}

void removeElement(Array *array, int index) {
    if (index >= array->size) {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < array->size - 1; i++) {
        array->elements[i].data = array->elements[i + 1].data;
        array->elements[i].index = array->elements[i + 1].index;
    }
    array->size--;
    if (array->size < array->capacity / 4) {
        resizeArray(array);
    }
}

void printArray(Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->elements[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Array array;
    initArray(&array);
    for (int i = 0; i < 100; i++) {
        int data = rand() % 100;
        addElement(&array, data);
    }
    printArray(&array);
    for (int i = 0; i < 50; i++) {
        int index = rand() % array.size;
        removeElement(&array, index);
    }
    printArray(&array);
    return 0;
}