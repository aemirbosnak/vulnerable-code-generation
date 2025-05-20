//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int size;
    int *arr;
} array;

void init_array(array *a, int size) {
    a->size = size;
    a->arr = (int *)malloc(size * sizeof(int));
}

void free_array(array *a) {
    free(a->arr);
}

void fill_array(array *a, int value) {
    for (int i = 0; i < a->size; i++) {
        a->arr[i] = value;
    }
}

void print_array(array *a) {
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_SIZE + 1;
    array a1, a2;
    init_array(&a1, n);
    init_array(&a2, n);
    fill_array(&a1, 1);
    fill_array(&a2, 2);
    printf("a1: ");
    print_array(&a1);
    printf("a2: ");
    print_array(&a2);
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int sum = a1.arr[i] + a2.arr[i] + carry;
        a1.arr[i] = sum % 10;
        carry = sum / 10;
    }
    while (carry > 0) {
        a1.arr[n - 1] += carry;
        carry /= 10;
    }
    printf("a1 + a2: ");
    print_array(&a1);
    free_array(&a1);
    free_array(&a2);
    return 0;
}