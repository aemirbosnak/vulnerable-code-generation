//FormAI DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j, scalar;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    // Allocate memory for matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Take input for matrix
    printf("Enter the matrix elements: \n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the original matrix
    printf("The original matrix is:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Take scalar input
    printf("Enter the scalar value to multiply the matrix: ");
    scanf("%d", &scalar);

    // Multiply the matrix by scalar
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }

    // Print the multiplied matrix
    printf("The multiplied matrix is:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory
    for(i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;    
}