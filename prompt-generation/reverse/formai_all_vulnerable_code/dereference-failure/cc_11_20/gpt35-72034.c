//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    int** matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix entered is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // matrix multiplication example
    int** matB = (int**) malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        matB[i] = (int*) malloc(rows * sizeof(int));
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    printf("The matrix B entered is:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matB[i][j]);
        }
        printf("\n");
    }

    int** product = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        product[i] = (int*) malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            product[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                product[i][j] += matrix[i][k] * matB[k][j];
            }
        }
    }

    printf("The product of the two matrices is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++) {
        free(matB[i]);
    }
    free(matB);

    for (int i = 0; i < rows; i++) {
        free(product[i]);
    }
    free(product);

    return 0;
}