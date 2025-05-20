//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000 // maximum size of input array

typedef struct {
    int *data; // pointer to input array
    int size; // size of input array
} Array;

void *malloc_wrapper(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void free_wrapper(void *ptr) {
    free(ptr);
}

void init_array(Array *array, int size) {
    array->data = (int *)malloc_wrapper(size * sizeof(int));
    array->size = size;
}

void destroy_array(Array *array) {
    free_wrapper(array->data);
}

void fill_array(Array *array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
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
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Error: Invalid array size!\n");
        return 1;
    }

    Array array;
    init_array(&array, size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array.data[i]);
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array.data[i];
    }

    printf("The sum of the array elements is: %d\n", sum);

    destroy_array(&array);
    return 0;
}