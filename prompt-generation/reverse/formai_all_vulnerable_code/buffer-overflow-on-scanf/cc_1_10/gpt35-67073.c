//FormAI DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define matrix size*/
#define MATRIX_SIZE 3

/* Define matrix operations */
void add_matrices(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE]);
void subtract_matrices(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE]);
void multiply_matrices(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE]);
int get_determinant(int matrix[MATRIX_SIZE][MATRIX_SIZE], int size);

/* Define main function */
int main() {
    int matrix1[MATRIX_SIZE][MATRIX_SIZE];
    int matrix2[MATRIX_SIZE][MATRIX_SIZE];
    int i, j, choice;
    srand(time(NULL));

    /* Get matrix values from user or by random */
    printf("Choose an option:\n 1. Enter Matrix values manually\n 2. Generate Matrix values randomly\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter values for Matrix 1: \n");
            for (i = 0; i < MATRIX_SIZE; i++) {
                for (j = 0; j < MATRIX_SIZE; j++) {
                    scanf("%d", &matrix1[i][j]);
                }
            }
            printf("Enter values for Matrix 2: \n");
            for (i = 0; i < MATRIX_SIZE; i++) {
                for (j = 0; j < MATRIX_SIZE; j++) {
                    scanf("%d", &matrix2[i][j]);
                }
            }
            break;
        case 2:
            printf("Matrix 1:\n");
            for (i = 0; i < MATRIX_SIZE; i++) {
                for (j = 0; j < MATRIX_SIZE; j++) {
                    matrix1[i][j] = rand() % 10;
                    printf("%d ", matrix1[i][j]);
                }
                printf("\n");
            }
            printf("Matrix 2:\n");
            for (i = 0; i < MATRIX_SIZE; i++) {
                for (j = 0; j < MATRIX_SIZE; j++) {
                    matrix2[i][j] = rand() % 10;
                    printf("%d ", matrix2[i][j]);
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    /* Perform matrix operations */
    add_matrices(matrix1, matrix2);
    subtract_matrices(matrix1, matrix2);
    multiply_matrices(matrix1, matrix2);

    /* Get the determinant of matrix 1 */
    int determinant = get_determinant(matrix1, MATRIX_SIZE);
    printf("The determinant of matrix 1 is: %d\n", determinant);

    return 0;
}

/* Function to add two matrices*/
void add_matrices(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, sum_matrix[MATRIX_SIZE][MATRIX_SIZE];
    printf("Addition of Matrices:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", sum_matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to subtract two matrices*/
void subtract_matrices(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, diff_matrix[MATRIX_SIZE][MATRIX_SIZE];
    printf("Subtraction of Matrices:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            diff_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", diff_matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to multiply two matrices*/
void multiply_matrices(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, k, prod_matrix[MATRIX_SIZE][MATRIX_SIZE];
    printf("Multiplication of Matrices:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            prod_matrix[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++) {
                prod_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", prod_matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to get the determinant of a matrix */
int get_determinant(int matrix[MATRIX_SIZE][MATRIX_SIZE], int size) {
    int determinant = 0;
    int submatrix[MATRIX_SIZE][MATRIX_SIZE];
    if (size == 2) {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    } else {
        int sign = 1;
        for (int i = 0; i < size; i++) {
            int subi = 0;
            for (int j = 1; j < size; j++) {
                int subj = 0;
                for (int k = 0; k < size; k++) {
                    if (k == i) {
                        continue;
                    }
                    submatrix[subi][subj] = matrix[j][k];
                    subj++;
                }
                subi++;
            }
            determinant = determinant + (sign * matrix[0][i] * get_determinant(submatrix, size - 1));
            sign = sign * -1;
        }
    }
    return determinant;
}