//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
typedef struct {
    float data[SIZE][SIZE];
} matrix;
// Function to print matrix
void print_matrix(matrix m) {
    int i, j;
    printf("Matrix A:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2f ", m.data[i][j]);
            if (j < SIZE - 1)
                printf("  ");
        }
        printf("\n");
    }
}
// Function to multiply two matrices
matrix multiply(matrix a, matrix b) {
    int i, j, k;
    matrix c;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            c.data[i][j] = 0;
            for (k = 0; k < SIZE; k++)
                c.data[i][j] += a.data[i][k] * b.data[k][j];
        }
    }
    return c;
}
int main() {
    matrix a, b, result;
    int i, j;
    // Input matrix A
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%f", &a.data[i][j]);
        }
    }
    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%f", &b.data[i][j]);
        }
    }
    // Multiply matrices A and B
    result = multiply(a, b);
    // Print matrices A, B and result
    print_matrix(a);
    printf("Matrix B:\n");
    print_matrix(b);
    printf("Result of multiplication:\n");
    print_matrix(result);
    return 0;
}