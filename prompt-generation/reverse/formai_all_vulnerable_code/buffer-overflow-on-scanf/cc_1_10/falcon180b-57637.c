//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000000

typedef struct {
    int *data;
    int size;
} Array;

void init_array(Array *array, int size) {
    array->data = (int *) malloc(size * sizeof(int));
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = i;
    }
}

void free_array(Array *array) {
    free(array->data);
}

void sort_array(Array *array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = i + 1; j < array->size; j++) {
            if (array->data[i] > array->data[j]) {
                int temp = array->data[i];
                array->data[i] = array->data[j];
                array->data[j] = temp;
            }
        }
    }
}

void print_array(Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    Array array;
    init_array(&array, size);

    printf("Unsorted array:\n");
    print_array(&array);

    clock_t start = clock();
    sort_array(&array);
    clock_t end = clock();

    printf("Sorted array:\n");
    print_array(&array);

    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    free_array(&array);
    return 0;
}