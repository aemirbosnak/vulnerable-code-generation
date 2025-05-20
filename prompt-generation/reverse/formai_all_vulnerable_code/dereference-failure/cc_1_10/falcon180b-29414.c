//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *array, int size) {
    array->size = size;
    array->data = (int *) malloc(size * sizeof(int));
}

void free_array(IntArray *array) {
    free(array->data);
}

void fill_array(IntArray *array, int value) {
    int i;
    for (i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

void print_array(IntArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray array1, array2;
    int i, j, n;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;

    init_array(&array1, n);
    init_array(&array2, n);

    fill_array(&array1, 1);
    fill_array(&array2, 2);

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            array1.data[i] += array2.data[i];
        } else {
            array1.data[i] -= array2.data[i];
        }
    }

    printf("Result:\n");
    print_array(&array1);

    free_array(&array1);
    free_array(&array2);

    return 0;
}