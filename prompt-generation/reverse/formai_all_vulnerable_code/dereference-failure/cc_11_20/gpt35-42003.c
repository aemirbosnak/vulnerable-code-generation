//FormAI DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    int row_1, col_1, row_2, col_2;
    printf("Enter the number of rows and columns for the first matrix: \n");
    scanf("%d %d", &row_1, &col_1);
    printf("Enter the number of rows and columns for the second matrix: \n");
    scanf("%d %d", &row_2, &col_2);

    // Validity Check
    if (col_1 != row_2) {
        printf("Invalid matrix dimensions. Column of first matrix should equal the row of second matrix.\n");
        return 0;
    }

    // Initializing matrix 1
    int **matrix_1;
    matrix_1 = (int **)malloc(row_1 * sizeof(int *));

    for (int i = 0; i < row_1; i++) {
        matrix_1[i] = (int *)malloc(col_1 * sizeof(int));
        for (int j = 0; j < col_1; j++) {
            printf("Enter element [%d][%d] in matrix 1: ", i, j);
            scanf("%d", &matrix_1[i][j]);
        }
    }

    // Initializing matrix 2
    int **matrix_2;
    matrix_2 = (int **)malloc(row_2 * sizeof(int *));

    for (int i = 0; i < row_2; i++) {
        matrix_2[i] = (int *)malloc(col_2 * sizeof(int));
        for (int j = 0; j < col_2; j++) {
            printf("Enter element [%d][%d] in matrix 2: ", i, j);
            scanf("%d", &matrix_2[i][j]);
        }
    }

    // Multiplying the matrices
    int **result_matrix;
    result_matrix = (int **)malloc(row_1 * sizeof(int *));

    for (int i = 0; i < row_1; i++) {
        result_matrix[i] = (int *)malloc(col_2 * sizeof(int));
        for (int j = 0; j < col_2; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < col_1; k++) {
                result_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }

    // Displaying the resultant matrix
    printf("\nResultant matrix after multiplication:\n");

    for (int i = 0; i < row_1; i++) {
        for (int j = 0; j < col_2; j++)
            printf("%d\t", result_matrix[i][j]);
        printf("\n");
    }

    // Freeing the memory
    for (int i = 0; i < row_1; i++)
        free(matrix_1[i]);
    free(matrix_1);

    for (int i = 0; i < row_2; i++)
        free(matrix_2[i]);
    free(matrix_2);

    for (int i = 0; i < row_1; i++)
        free(result_matrix[i]);
    free(result_matrix);

    return 0;
}