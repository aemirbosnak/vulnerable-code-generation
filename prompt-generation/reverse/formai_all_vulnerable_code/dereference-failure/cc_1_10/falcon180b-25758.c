//Falcon-180B DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MyVector;

MyVector *create_vector(int initial_size) {
    MyVector *vector = (MyVector *)malloc(sizeof(MyVector));
    vector->data = (int *)malloc(sizeof(int) * initial_size);
    vector->size = 0;
    vector->capacity = initial_size;
    return vector;
}

void destroy_vector(MyVector *vector) {
    free(vector->data);
    free(vector);
}

void vector_push_back(MyVector *vector, int value) {
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;
        vector->data = (int *)realloc(vector->data, sizeof(int) * vector->capacity);
    }
    vector->data[vector->size++] = value;
}

int vector_size(MyVector *vector) {
    return vector->size;
}

void vector_print(MyVector *vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}

int main() {
    MyVector *vector = create_vector(10);

    vector_push_back(vector, 1);
    vector_push_back(vector, 2);
    vector_push_back(vector, 3);
    vector_push_back(vector, 4);
    vector_push_back(vector, 5);
    vector_push_back(vector, 6);
    vector_push_back(vector, 7);
    vector_push_back(vector, 8);
    vector_push_back(vector, 9);
    vector_push_back(vector, 10);

    vector_print(vector);

    destroy_vector(vector);

    return 0;
}