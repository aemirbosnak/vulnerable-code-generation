//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int rows, cols;
    double **matrix1, **matrix2, **result;
    double sum = 0.0;

    // Prompt user for input
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for matrices
    matrix1 = (double **) malloc(rows * sizeof(double *));
    matrix2 = (double **) malloc(rows * sizeof(double *));
    result = (double **) malloc(rows * sizeof(double *));

    for (int i = 0; i < rows; i++) {
        matrix1[i] = (double *) malloc(cols * sizeof(double));
        matrix2[i] = (double *) malloc(cols * sizeof(double));
        result[i] = (double *) malloc(cols * sizeof(double));
    }

    // Prompt user for matrix elements
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print result
    printf("Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}