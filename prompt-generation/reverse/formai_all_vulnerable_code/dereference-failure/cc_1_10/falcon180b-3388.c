//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MIN_VALUE -1000000
#define MAX_VALUE 1000000

typedef struct {
    int *data;
    int size;
} Array;

void generate_random_array(Array *array) {
    srand(time(NULL));
    array->size = rand() % MAX_SIZE + 1;
    array->data = (int *)malloc(array->size * sizeof(int));

    for (int i = 0; i < array->size; i++) {
        array->data[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

void print_array(Array array) {
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

void merge_sort(Array *array) {
    if (array->size <= 1) {
        return;
    }

    int mid = array->size / 2;
    Array left, right;

    left.data = (int *)malloc(mid * sizeof(int));
    right.data = (int *)malloc((array->size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left.data[i] = array->data[i];
    }

    for (int i = mid; i < array->size; i++) {
        right.data[i - mid] = array->data[i];
    }

    merge_sort(&left);
    merge_sort(&right);

    int i = 0, j = 0, k = 0;

    while (i < mid && j < right.size) {
        if (left.data[i] <= right.data[j]) {
            array->data[k] = left.data[i];
            i++;
        } else {
            array->data[k] = right.data[j];
            j++;
        }
        k++;
    }

    while (i < mid) {
        array->data[k] = left.data[i];
        i++;
        k++;
    }

    while (j < right.size) {
        array->data[k] = right.data[j];
        j++;
        k++;
    }

    free(left.data);
    free(right.data);
}

int main() {
    Array array;
    generate_random_array(&array);
    print_array(array);
    merge_sort(&array);
    print_array(array);

    free(array.data);
    return 0;
}