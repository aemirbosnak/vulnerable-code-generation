//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int capacity;
    int size;
} Vector;

void vector_init(Vector *v, int capacity) {
    v->data = (int *)malloc(capacity * sizeof(int));
    v->capacity = capacity;
    v->size = 0;
}

void vector_free(Vector *v) {
    free(v->data);
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int vector_get(Vector *v, int index) {
    if (index >= 0 && index < v->size) {
        return v->data[index];
    }
    return -1;
}

void vector_sort(Vector *v) {
    int i, j, temp;
    for (i = 0; i < v->size - 1; i++) {
        for (j = i + 1; j < v->size; j++) {
            if (v->data[j] < v->data[i]) {
                temp = v->data[i];
                v->data[i] = v->data[j];
                v->data[j] = temp;
            }
        }
    }
}

void vector_print(Vector *v) {
    int i;
    for (i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int main() {
    int i, j, n;
    Vector v;
    double start_time, end_time;

    printf("Enter the size of vector: ");
    scanf("%d", &n);

    vector_init(&v, n);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        v.data[i] = rand() % MAX_SIZE;
    }

    start_time = clock();
    vector_sort(&v);
    end_time = clock();

    printf("Sorted vector: ");
    vector_print(&v);

    printf("Time taken: %.6f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    vector_free(&v);

    return 0;
}