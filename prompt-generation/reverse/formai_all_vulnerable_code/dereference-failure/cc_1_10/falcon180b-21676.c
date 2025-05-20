//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} Array;

void init(Array *array, int size) {
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
}

void destroy(Array *array) {
    free(array->data);
}

void fill(Array *array, int value) {
    int i;
    for (i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

void print(Array *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    int i;
    Array arr1, arr2, arr3;
    double start_time, end_time;

    // Initialize arrays
    init(&arr1, MAX_SIZE);
    init(&arr2, MAX_SIZE);
    init(&arr3, MAX_SIZE);

    // Fill arrays with random values
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr1.data[i] = rand() % 100;
        arr2.data[i] = rand() % 100;
    }

    // Measure time for addition
    start_time = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        arr3.data[i] = arr1.data[i] + arr2.data[i];
    }
    end_time = clock();
    printf("Time for addition: %.6f seconds\n", ((double)end_time - start_time) / CLOCKS_PER_SEC);

    // Measure time for multiplication
    start_time = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        arr3.data[i] = arr1.data[i] * arr2.data[i];
    }
    end_time = clock();
    printf("Time for multiplication: %.6f seconds\n", ((double)end_time - start_time) / CLOCKS_PER_SEC);

    // Print results
    printf("Result of addition:\n");
    print(&arr3);

    printf("Result of multiplication:\n");
    print(&arr3);

    // Clean up
    destroy(&arr1);
    destroy(&arr2);
    destroy(&arr3);

    return 0;
}