//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_DIM 10
#define MAX_ELEMENT 10000

typedef struct {
    int dim;
    int *array;
} matrix;

void sieve_2d(matrix *result, int base, int dim) {
    int i, j;
    if (dim < 1 || dim > MAX_DIM || base < 1 || base > MAX_ELEMENT) {
        printf("Invalid input\n");
        return;
    }

    result->dim = dim;
    result->array = calloc(dim * dim, sizeof(int));

    for (i = 0; i < dim * dim; i++) {
        result->array[i] = 1;
    }

    for (i = base; i * i <= dim * dim; i++) {
        if (result->array[i * i - 1] == 1) {
            for (j = i * i; j <= dim * dim; j += i) {
                result->array[j - 1] = 0;
            }
        }
    }
}

void print_matrix(const matrix *matrix) {
    int i, j;

    for (i = 0; i < matrix->dim; i++) {
        for (j = 0; j < matrix->dim; j++) {
            printf("%d ", matrix->array[i * matrix->dim + j]);
        }
        printf("\n");
    }
}

int main() {
    int base, dim;
    matrix prime_numbers;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter dimensions: ");
    scanf("%d", &dim);

    sieve_2d(&prime_numbers, base, dim);

    printf("Prime numbers in %dx%d matrix:\n", dim, dim);
    print_matrix(&prime_numbers);

    free(prime_numbers.array);

    return 0;
}