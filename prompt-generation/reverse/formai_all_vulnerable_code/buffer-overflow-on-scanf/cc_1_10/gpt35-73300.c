//FormAI DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

/* function prototypes */
void init_matrix(int matrix[ROWS][COLS]);
void print_matrix(int matrix[ROWS][COLS]);
void scalar_multiply(int matrix[ROWS][COLS], int scalar);
void matrix_multiply(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);

int main() {
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];
    int scalar;
    
    /* initialize random seed */
    srand(time(NULL));
    
    /* initialize matrices with random values */
    printf("Initializing matrices with random values...\n");
    init_matrix(matrix1);
    init_matrix(matrix2);
    
    /* print matrices to display initial values */
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    
    /* get scalar from user */
    printf("Enter a scalar value: ");
    scanf("%d", &scalar);
    
    /* perform scalar multiplication */
    printf("Performing scalar multiplication...\n");
    scalar_multiply(matrix1, scalar);
    scalar_multiply(matrix2, scalar);
    
    /* print matrices again to show results of scalar multiplication */
    printf("Matrix 1 after scalar multiplication:\n");
    print_matrix(matrix1);
    printf("Matrix 2 after scalar multiplication:\n");
    print_matrix(matrix2);
    
    /* perform matrix multiplication */
    printf("Performing matrix multiplication...\n");
    matrix_multiply(matrix1, matrix2, result);
    
    /* print result matrix */
    printf("Result of matrix multiplication:\n");
    print_matrix(result);
    
    return 0;
}

/* function to initialize matrix with random values */
void init_matrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

/* function to print matrix */
void print_matrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

/* function to perform scalar multiplication */
void scalar_multiply(int matrix[ROWS][COLS], int scalar) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

/* function to perform matrix multiplication */
void matrix_multiply(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j, k;
    // initialize result matrix to all zeros
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = 0;
        }
    }
    // multiply matrices and store result in result matrix
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            for (k = 0; k < ROWS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}