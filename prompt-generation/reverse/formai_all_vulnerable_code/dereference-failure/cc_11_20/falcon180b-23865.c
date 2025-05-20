//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int rows1, cols1, rows2, cols2, i, j, k;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        printf("Enter the elements of the first matrix: ");
        for (j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
        printf("Enter the elements of the second matrix: ");
        for (j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("The product of the matrices is:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}