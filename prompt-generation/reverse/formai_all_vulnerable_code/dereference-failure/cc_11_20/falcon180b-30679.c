//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows, &cols);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    int rows2, cols2;
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int rows3, cols3;
    printf("Enter the number of rows and columns of the result matrix: ");
    scanf("%d %d", &rows3, &cols3);

    int **result = (int **)malloc(rows3 * sizeof(int *));
    for (int i = 0; i < rows3; i++) {
        result[i] = (int *)malloc(cols3 * sizeof(int));
    }

    for (int i = 0; i < rows3; i++) {
        for (int j = 0; j < cols3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("The result matrix is:\n");
    for (int i = 0; i < rows3; i++) {
        for (int j = 0; j < cols3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows3; i++) {
        free(result[i]);
    }
    free(result);

    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}