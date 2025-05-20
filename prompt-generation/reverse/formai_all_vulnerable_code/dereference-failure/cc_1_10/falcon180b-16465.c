//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define N 1000000

#define BIT_SET(bit, byte) (byte |= (1 << bit))
#define BIT_CLEAR(bit, byte) (byte &= ~(1 << bit))
#define BIT_TOGGLE(bit, byte) (byte ^= (1 << bit))
#define BIT_TEST(bit, byte) (byte & (1 << bit))

void bitwise_operations(int *array) {
    int i, j, k;

    // set the first bit of each element to 1
    for (i = 0; i < N; i++) {
        BIT_SET(0, array[i]);
    }

    // clear the second bit of every fourth element
    for (i = 0; i < N; i++) {
        if (i % 4 == 0) {
            BIT_CLEAR(1, array[i]);
        }
    }

    // toggle the third bit of every eighth element
    for (i = 0; i < N; i++) {
        if (i % 8 == 0) {
            BIT_TOGGLE(2, array[i]);
        }
    }

    // test the fourth bit of each element
    for (i = 0; i < N; i++) {
        if (BIT_TEST(3, array[i])) {
            printf("Element %d has the fourth bit set.\n", i);
        }
    }
}

int main() {
    int *array;
    array = (int *) malloc(N * sizeof(int));

    // initialize the array with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 256;
    }

    // perform bitwise operations on the array
    bitwise_operations(array);

    // free the allocated memory
    free(array);

    return 0;
}