//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *array) {
    array->data = (int *) malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
}

void add_element(IntArray *array, int element) {
    if (array->size >= MAX_SIZE) {
        printf("Error: Array is full.\n");
        exit(1);
    }
    array->data[array->size++] = element;
}

void remove_element(IntArray *array, int index) {
    if (index < 0 || index >= array->size) {
        printf("Error: Invalid index.\n");
        exit(1);
    }
    for (int i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}

void print_array(IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void free_array(IntArray *array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
}

int main() {
    srand(time(NULL));

    IntArray array;
    init_array(&array);

    for (int i = 0; i < 10; i++) {
        int element = rand() % 100;
        add_element(&array, element);
        printf("Added element %d\n", element);
    }

    print_array(&array);

    for (int i = 0; i < 5; i++) {
        int index = rand() % array.size;
        remove_element(&array, index);
        printf("Removed element at index %d\n", index);
    }

    print_array(&array);

    free_array(&array);

    return 0;
}