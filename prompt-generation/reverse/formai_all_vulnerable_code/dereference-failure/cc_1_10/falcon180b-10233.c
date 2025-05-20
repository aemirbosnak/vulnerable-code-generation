//Falcon-180B DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

Vector* create_vector(int capacity) {
    Vector *v = (Vector*)malloc(sizeof(Vector));
    v->data = (int*)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
    return v;
}

void free_vector(Vector *v) {
    free(v->data);
    free(v);
}

void push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int pop_back(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->data[--v->size];
}

void bubble_sort(Vector *v) {
    int n = v->size;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v->data[j] > v->data[j + 1]) {
                int temp = v->data[j];
                v->data[j] = v->data[j + 1];
                v->data[j + 1] = temp;
            }
        }
    }
}

int main() {
    Vector *v = create_vector(10);
    push_back(v, 5);
    push_back(v, 2);
    push_back(v, 8);
    push_back(v, 1);
    push_back(v, 6);

    bubble_sort(v);

    int n = v->size;
    for (int i = 0; i < n; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");

    free_vector(v);
    return 0;
}