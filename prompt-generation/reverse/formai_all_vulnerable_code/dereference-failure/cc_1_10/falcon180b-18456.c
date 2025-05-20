//Falcon-180B DATASET v1.0 Category: Educational ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, m, count = 0;
    int **matrix1, **matrix2, **multiplication_matrix;
    char ch;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &n, &m);

    matrix1 = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix1[i] = (int *)malloc(m * sizeof(int));
        printf("Enter the elements of row %d:\n", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    matrix2 = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix2[i] = (int *)malloc(m * sizeof(int));
        printf("Enter the elements of row %d:\n", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    multiplication_matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        multiplication_matrix[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++) {
            multiplication_matrix[i][j] = 0;
            for (int k = 0; k < n; k++) {
                multiplication_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("The multiplication matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", multiplication_matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix1);
    free(matrix2);
    free(multiplication_matrix);

    return 0;
}