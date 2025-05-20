//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

double a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
int n;

void generate_random_matrix(int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 10;
        b[i] = rand() % 10;
    }
}

void print_matrix(int size, double *matrix) {
    for (int i = 0; i < size; i++) {
        printf("%lf ", matrix[i]);
    }
    printf("\n");
}

void matrix_multiplication(int size, double *a, double *b, double *c) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i * size + j] = a[i * size + j] * b[j];
        }
    }
}

int main() {
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: size too large.\n");
        return 1;
    }

    generate_random_matrix(n);
    print_matrix(n, a);
    printf("Enter the second matrix:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    matrix_multiplication(n, a, b, c);
    printf("Result:\n");
    print_matrix(n, c);

    return 0;
}