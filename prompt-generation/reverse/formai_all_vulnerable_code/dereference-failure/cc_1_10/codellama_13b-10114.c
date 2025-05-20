//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector {
    int* arr;
    int size;
    int capacity;
};

void vector_init(struct Vector* v, int capacity) {
    v->arr = malloc(sizeof(int) * capacity);
    v->size = 0;
    v->capacity = capacity;
}

void vector_push_back(struct Vector* v, int value) {
    if (v->size == v->capacity) {
        int* temp = realloc(v->arr, sizeof(int) * (v->capacity * 2));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        v->arr = temp;
        v->capacity *= 2;
    }
    v->arr[v->size] = value;
    v->size++;
}

void vector_print(struct Vector* v) {
    printf("[");
    for (int i = 0; i < v->size; i++) {
        printf("%d", v->arr[i]);
        if (i < v->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    struct Vector v;
    vector_init(&v, 10);
    vector_push_back(&v, 1);
    vector_push_back(&v, 2);
    vector_push_back(&v, 3);
    vector_push_back(&v, 4);
    vector_print(&v);
    return 0;
}