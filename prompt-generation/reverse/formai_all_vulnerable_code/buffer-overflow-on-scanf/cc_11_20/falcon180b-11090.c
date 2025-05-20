//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows1, cols1, rows2, cols2;
    int **matrix1, **matrix2, **result;

    // Get dimensions of first matrix
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    // Allocate memory for first matrix
    matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    // Get elements of first matrix
    printf("Enter the elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Get dimensions of second matrix
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Allocate memory for second matrix
    matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Get elements of second matrix
    printf("Enter the elements of second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix addition
    if (rows1 == rows2 && cols1 == cols2) {
        result = (int **)malloc(rows1 * sizeof(int *));
        for (int i = 0; i < rows1; i++) {
            result[i] = (int *)malloc(cols1 * sizeof(int));
        }

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        printf("The sum of the two matrices is:\n");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < rows1; i++) {
            free(matrix1[i]);
        }
        free(matrix1);

        for (int i = 0; i < rows1; i++) {
            free(matrix2[i]);
        }
        free(matrix2);

        for (int i = 0; i < rows1; i++) {
            free(result[i]);
        }
        free(result);
    } else {
        printf("The matrices cannot be added.\n");
    }

    return 0;
}