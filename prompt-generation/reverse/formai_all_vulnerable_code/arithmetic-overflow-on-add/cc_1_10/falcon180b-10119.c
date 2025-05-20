//Falcon-180B DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int *data;
    int size;
} Array;

void init_array(Array *arr, int size) {
    arr->data = (int *)malloc(size * sizeof(int));
    arr->size = size;
    for (int i = 0; i < size; i++) {
        arr->data[i] = rand() % MAX_SIZE;
    }
}

void print_array(Array arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(Array arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot_index = rand() % (end - start + 1) + start;
    swap(arr.data[pivot_index], arr.data[end]);

    int pivot_value = arr.data[end];

    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr.data[j] <= pivot_value) {
            i++;
            swap(arr.data[i], arr.data[j]);
        }
    }

    swap(arr.data[i + 1], arr.data[end]);

    quick_sort(arr, start, i);
    quick_sort(arr, i + 2, end);
}

int main() {
    Array arr;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    init_array(&arr, size);
    print_array(arr);

    srand(time(NULL));
    quick_sort(arr, 0, size - 1);

    printf("Sorted array:\n");
    print_array(arr);

    free(arr.data);
    return 0;
}