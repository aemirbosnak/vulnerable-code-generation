//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int size;
    int capacity;
    int *array;
} DynamicArray;

DynamicArray *createArray(int size) {
    DynamicArray *newArray = (DynamicArray *)malloc(sizeof(DynamicArray));
    newArray->data = 0;
    newArray->size = size;
    newArray->capacity = size;
    newArray->array = (int *)malloc(sizeof(int) * size);
    return newArray;
}

void destroyArray(DynamicArray *array) {
    free(array->array);
    free(array);
}

void addElement(DynamicArray *array, int element) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->array = (int *)realloc(array->array, sizeof(int) * array->capacity);
    }
    array->array[array->size++] = element;
}

bool searchElement(DynamicArray *array, int element) {
    for (int i = 0; i < array->size; i++) {
        if (array->array[i] == element) {
            return true;
        }
    }
    return false;
}

int main() {
    int size, element;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    DynamicArray *array = createArray(size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array->array[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    if (searchElement(array, element)) {
        printf("Element found!\n");
    } else {
        printf("Element not found.\n");
    }

    destroyArray(array);

    return 0;
}