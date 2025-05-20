//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} IntArray;

void init_array(IntArray *array, int size) {
    array->data = malloc(sizeof(int) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = rand() % 100;
    }
}

void destroy_array(IntArray *array) {
    free(array->data);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(IntArray *array) {
    int n = array->size;
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array->data[j] > array->data[j + 1]) {
                swap(&array->data[j], &array->data[j + 1]);
            }
        }
    }
}

int main() {
    int size;
    IntArray array;

    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    init_array(&array, size);

    printf("Unsorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");

    bubble_sort(&array);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");

    destroy_array(&array);

    return 0;
}