//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 10000
#define MIN_VALUE -100
#define MAX_VALUE 100

typedef struct {
    int size;
    int *array;
} int_array;

int_array *create_array(int size) {
    int_array *array = (int_array *) malloc(sizeof(int_array));
    array->size = size;
    array->array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array->array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    return array;
}

void print_array(int_array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->array[i]);
    }
    printf("\n");
}

void sort_array(int_array *array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = 0; j < array->size - i - 1; j++) {
            if (array->array[j] > array->array[j + 1]) {
                int temp = array->array[j];
                array->array[j] = array->array[j + 1];
                array->array[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int_array *array = create_array(MAX_SIZE);
    printf("Unsorted array:\n");
    print_array(array);
    sort_array(array);
    printf("Sorted array:\n");
    print_array(array);
    free(array->array);
    free(array);
    return 0;
}