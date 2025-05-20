//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    int **matrix1, **matrix2, **result;
    int i, j, k;

    // Get input from user
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Initialize matrices with random values
    matrix1 = (int **)malloc(rows * sizeof(int *));
    matrix2 = (int **)malloc(rows * sizeof(int *));
    result = (int **)malloc(rows * sizeof(int *));

    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));

        for (j = 0; j < cols; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    // Get matrix operation from user
    printf("Enter the matrix operation (1 for addition, 2 for subtraction, 3 for multiplication): ");
    scanf("%d", &k);

    switch (k) {
        case 1:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            printf("The result of matrix addition is:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            printf("The result of matrix subtraction is:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    result[i][j] = matrix1[i][j] * matrix2[i][j];
                }
            }
            printf("The result of matrix multiplication is:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid matrix operation!\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}