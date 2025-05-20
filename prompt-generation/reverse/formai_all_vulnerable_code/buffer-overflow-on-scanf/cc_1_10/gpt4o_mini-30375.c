//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void fillFibonacciMatrix(int **matrix, int n);
void printMatrix(int **matrix, int n);
int **allocateMatrix(int n);
void deallocateMatrix(int **matrix, int n);

int main() {
    int n;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int **matrix = allocateMatrix(n);
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return -1;
    }

    fillFibonacciMatrix(matrix, n);
    printf("Fibonacci Spiral Pattern:\n");
    printMatrix(matrix, n);

    deallocateMatrix(matrix, n);
    return 0;
}

void fillFibonacciMatrix(int **matrix, int n) {
    int fib[2] = {0, 1}; // Fibonacci sequence start
    int i, j, row_start = 0, row_end = n - 1, col_start = 0, col_end = n - 1;

    while (row_start <= row_end && col_start <= col_end) {
        // Fill top row
        for (j = col_start; j <= col_end; j++) {
            matrix[row_start][j] = fib[0];
            int nextFib = fib[0] + fib[1];
            fib[0] = fib[1];
            fib[1] = nextFib;
        }
        row_start++;
        
        // Fill right column
        for (i = row_start; i <= row_end; i++) {
            matrix[i][col_end] = fib[0];
            int nextFib = fib[0] + fib[1];
            fib[0] = fib[1];
            fib[1] = nextFib;
        }
        col_end--;
        
        // Fill bottom row
        if (row_start <= row_end) {
            for (j = col_end; j >= col_start; j--) {
                matrix[row_end][j] = fib[0];
                int nextFib = fib[0] + fib[1];
                fib[0] = fib[1];
                fib[1] = nextFib;
            }
            row_end--;
        }
        
        // Fill left column
        if (col_start <= col_end) {
            for (i = row_end; i >= row_start; i--) {
                matrix[i][col_start] = fib[0];
                int nextFib = fib[0] + fib[1];
                fib[0] = fib[1];
                fib[1] = nextFib;
            }
            col_start++;
        }
    }
}

void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **allocateMatrix(int n) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            matrix[i] = (int *)malloc(n * sizeof(int));
            if (matrix[i] == NULL) {
                deallocateMatrix(matrix, i);
                return NULL;
            }
        }
    }
    return matrix;
}

void deallocateMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}