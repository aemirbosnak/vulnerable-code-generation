//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, k;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }

    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }

    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    printf("\nMatrix 1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    int **sum = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        sum[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nSum:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (i = 0; i < rows; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (i = 0; i < rows; i++) {
        free(sum[i]);
    }
    free(sum);

    return 0;
}