//Falcon-180B DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    int size;
    int **matrix;
    int *row_sums;
    int *col_sums;
    int i, j;

    printf("Enter the size of the matrix (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    matrix = (int **)malloc(size * sizeof(int *));
    row_sums = (int *)malloc(size * sizeof(int));
    col_sums = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("The row sums are:\n");
    for (i = 0; i < size; i++) {
        row_sums[i] = 0;
        for (j = 0; j < size; j++) {
            row_sums[i] += matrix[i][j];
        }
        printf("%d ", row_sums[i]);
    }
    printf("\n");

    printf("The column sums are:\n");
    for (i = 0; i < size; i++) {
        col_sums[i] = 0;
        for (j = 0; j < size; j++) {
            col_sums[i] += matrix[j][i];
        }
        printf("%d ", col_sums[i]);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(row_sums);
    free(col_sums);

    return 0;
}