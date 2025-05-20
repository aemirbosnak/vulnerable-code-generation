//FormAI DATASET v1.0 Category: Matrix operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to my curious Matrix operations program!\n");

    int rows, cols;

    printf("Please enter the number of rows of the matrix: ");
    scanf("%d", &rows);

    printf("Please enter the number of columns of the matrix: ");
    scanf("%d", &cols);

    int **matrix, **transpose;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    transpose = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }

    printf("Please enter the elements of the matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Printing the original matrix
    printf("\nThe original matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transposing the matrix
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Printing the transposed matrix
    printf("\nThe transposed matrix is:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Multiplying the matrix with its transpose
    int **result, sum;
    result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(rows * sizeof(int));
        for (int j = 0; j < rows; j++) {
            sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += matrix[i][k] * transpose[k][j];
            }
            result[i][j] = sum;
        }
    }

    // Printing the result of multiplying the matrix with its transpose
    printf("\nThe result of multiplying the matrix with its transpose is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\nThank you for using my curious Matrix operations program! Goodbye!\n");

    // Freeing the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++) {
        free(transpose[i]);
    }
    free(transpose);

    for (int i = 0; i < rows; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}