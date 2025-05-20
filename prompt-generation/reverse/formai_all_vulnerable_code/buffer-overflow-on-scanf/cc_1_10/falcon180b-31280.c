//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void print_matrix(int mat[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX], rows1, cols1, rows2, cols2, i, j, k;

    // Input dimensions of first matrix
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    // Input elements of first matrix
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input dimensions of second matrix
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if matrices can be multiplied
    if (cols1!= rows2) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }

    // Input elements of second matrix
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Multiply matrices
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            for (k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Print result matrix
    printf("Product of matrices:\n");
    print_matrix(result, rows1, cols2);

    return 0;
}