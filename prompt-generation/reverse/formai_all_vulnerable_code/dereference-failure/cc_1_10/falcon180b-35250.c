//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define INITIAL_CAPACITY 10

typedef struct {
    int* data;
    int capacity;
    int size;
} vector;

vector* create_vector() {
    vector* v = (vector*) malloc(sizeof(vector));
    v->data = (int*) malloc(sizeof(int) * INITIAL_CAPACITY);
    v->capacity = INITIAL_CAPACITY;
    v->size = 0;
    return v;
}

void destroy_vector(vector* v) {
    free(v->data);
    free(v);
}

int is_full(vector* v) {
    return v->size == v->capacity;
}

void resize(vector* v) {
    v->capacity *= 2;
    v->data = (int*) realloc(v->data, sizeof(int) * v->capacity);
}

void push_back(vector* v, int value) {
    if (is_full(v)) {
        resize(v);
    }
    v->data[v->size++] = value;
}

void pop_back(vector* v) {
    v->size--;
}

int get(vector* v, int index) {
    if (index >= v->size) {
        return -1;
    }
    return v->data[index];
}

int main() {
    vector* v = create_vector();

    for (int i = 0; i < MAX_SIZE; i++) {
        push_back(v, i);
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", get(v, i));
    }

    destroy_vector(v);

    return 0;
}