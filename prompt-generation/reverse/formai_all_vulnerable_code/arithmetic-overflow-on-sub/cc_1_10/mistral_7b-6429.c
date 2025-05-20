//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100
#define MIN_VALUE INT_MIN
#define MAX_VALUE INT_MAX

typedef struct {
    int array[MAX_SIZE];
    int size;
} MyArray;

void print_array(MyArray arr) {
    int i;
    printf("[");
    for (i = 0; i < arr.size; i++) {
        if (i != 0)
            printf(", ");
        printf("%d", arr.array[i]);
    }
    printf("]\n");
}

void initialize_array(MyArray *arr) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        arr->array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    arr->size = MAX_SIZE;
}

int sum_array(MyArray arr) {
    int i, sum = 0;
    for (i = 0; i < arr.size; i++) {
        sum += arr.array[i];
    }
    return sum;
}

int min_value(MyArray arr) {
    int min = MIN_VALUE;
    int i;
    for (i = 0; i < arr.size; i++) {
        if (arr.array[i] < min) {
            min = arr.array[i];
        }
    }
    return min;
}

int main() {
    MyArray arr;
    srand(time(NULL));

    printf("Initializing array with random values:\n");
    initialize_array(&arr);
    print_array(arr);

    printf("Sum of array elements: %d\n", sum_array(arr));

    printf("Minimum value in array: %d\n", min_value(arr));

    printf("Changing the array size\n");
    arr.size = 5;
    print_array(arr);

    return 0;
}