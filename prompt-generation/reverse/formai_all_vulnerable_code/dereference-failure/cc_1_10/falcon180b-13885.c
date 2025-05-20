//Falcon-180B DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
    int capacity;
} Array;

void init_array(Array *a, int capacity) {
    a->data = (int *)malloc(capacity * sizeof(int));
    a->size = 0;
    a->capacity = capacity;
}

void free_array(Array *a) {
    free(a->data);
}

void push_back(Array *a, int value) {
    if (a->size == a->capacity) {
        a->capacity *= 2;
        a->data = (int *)realloc(a->data, a->capacity * sizeof(int));
    }
    a->data[a->size++] = value;
}

void sort_array(Array *a, int (*compare)(int, int)) {
    int i, j, tmp;
    for (i = 0; i < a->size - 1; i++) {
        for (j = i + 1; j < a->size; j++) {
            if ((*compare)(a->data[j], a->data[i]) < 0) {
                tmp = a->data[i];
                a->data[i] = a->data[j];
                a->data[j] = tmp;
            }
        }
    }
}

int compare_int(int a, int b) {
    return a - b;
}

int main() {
    srand(time(NULL));
    Array a;
    init_array(&a, MAX_SIZE);
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        push_back(&a, rand() % MAX_SIZE);
    }
    printf("Before sorting:\n");
    for (i = 0; i < a.size; i++) {
        printf("%d ", a.data[i]);
    }
    printf("\n");
    sort_array(&a, compare_int);
    printf("After sorting:\n");
    for (i = 0; i < a.size; i++) {
        printf("%d ", a.data[i]);
    }
    printf("\n");
    free_array(&a);
    return 0;
}