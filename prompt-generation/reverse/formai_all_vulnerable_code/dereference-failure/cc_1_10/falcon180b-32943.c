//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_ITERATIONS 100000

typedef struct {
    int size;
    int *array;
} Array;

void generate_array(Array *arr) {
    srand(time(NULL));
    arr->size = rand() % MAX_SIZE + 1;
    arr->array = (int*)malloc(arr->size * sizeof(int));
    for (int i = 0; i < arr->size; i++) {
        arr->array[i] = rand() % MAX_SIZE + 1;
    }
}

void print_array(const Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

void merge_sort(Array *arr) {
    if (arr->size <= 1) {
        return;
    }

    int mid = arr->size / 2;
    Array left, right;
    left.size = mid;
    right.size = arr->size - mid;
    left.array = (int*)malloc(left.size * sizeof(int));
    right.array = (int*)malloc(right.size * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left.array[i] = arr->array[i];
    }
    for (int i = mid; i < arr->size; i++) {
        right.array[i - mid] = arr->array[i];
    }

    merge_sort(&left);
    merge_sort(&right);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < right.size) {
        if (left.array[i] <= right.array[j]) {
            arr->array[k++] = left.array[i++];
        } else {
            arr->array[k++] = right.array[j++];
        }
    }

    while (i < mid) {
        arr->array[k++] = left.array[i++];
    }

    while (j < right.size) {
        arr->array[k++] = right.array[j++];
    }

    free(left.array);
    free(right.array);
}

int main() {
    Array arr;
    generate_array(&arr);
    printf("Original array:\n");
    print_array(&arr);

    merge_sort(&arr);

    printf("Sorted array:\n");
    print_array(&arr);

    free(arr.array);
    return 0;
}