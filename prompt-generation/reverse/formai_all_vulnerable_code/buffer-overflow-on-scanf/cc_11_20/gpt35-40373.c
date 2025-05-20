//FormAI DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {

    int rows, columns, i, j;
    printf("Enter number of rows in matrix: ");
    scanf("%d", &rows);
    printf("Enter number of columns in matrix: ");
    scanf("%d", &columns);

    // Dynamically allocate memory for matrix
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for (i=0; i<rows; i++) {
        matrix[i] = (int *) malloc(columns * sizeof(int));
    }

    // Input matrix elements from user
    printf("Enter elements of matrix:\n");
    for (i=0; i<rows; i++) {
        for (j=0; j<columns; j++) {
           scanf("%d", &matrix[i][j]);
        }
    }

    // Print entered matrix
    printf("\nMatrix Entered:\n");
    for (i=0; i<rows; i++) {
        for (j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose of matrix
    int **transposed_matrix = (int **) malloc(columns * sizeof(int *));
    for (i=0; i<columns; i++) {
        transposed_matrix[i] = (int *) malloc(rows * sizeof(int));
    }

    for (i=0; i<columns; i++) {
        for (j=0; j<rows; j++) {
            transposed_matrix[i][j] = matrix[j][i];
        }
    }

    // Print transposed matrix
    printf("\nTransposed Matrix:\n");
    for (i=0; i<columns; i++) {
        for (j=0; j<rows; j++) {
            printf("%d ", transposed_matrix[i][j]);
        }
        printf("\n");
    }

    // Matrix multiplication
    int k, sum;
    int **mult_result = (int **) malloc(rows * sizeof(int *));
    for (i=0; i<rows; i++) {
        mult_result[i] = (int *) malloc(columns * sizeof(int));
    }

    for (i=0; i<rows; i++) {
        for (j=0; j<columns; j++) {
            sum = 0;
            for (k=0; k<rows; k++) {
                sum += matrix[i][k] * transposed_matrix[k][j];
            }
            mult_result[i][j] = sum;
        }
    }

    // Print matrix multiplication result
    printf("\nMatrix Multiplication Result:\n");
    for (i=0; i<rows; i++) {
        for (j=0; j<columns; j++) {
            printf("%d ", mult_result[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory
    for (i=0; i<rows; i++) {
        free(matrix[i]);
        free(transposed_matrix[i]);
        free(mult_result[i]);
    }
    free(matrix);
    free(transposed_matrix);
    free(mult_result);

    return 0;
}