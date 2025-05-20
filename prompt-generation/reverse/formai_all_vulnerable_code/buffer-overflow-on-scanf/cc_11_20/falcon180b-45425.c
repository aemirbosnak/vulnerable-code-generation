//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int main() {
    int rows, cols, i, j, **matrix1, **matrix2, **result;
    double start_time, end_time;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    matrix1 = (int **)malloc(rows * sizeof(int *));
    matrix2 = (int **)malloc(rows * sizeof(int *));
    result = (int **)malloc(rows * sizeof(int *));

    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix1[i][j]);

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix2[i][j]);

    start_time = clock();
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];

    end_time = clock();
    printf("The sum of the matrices is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    printf("Time taken for the operation: %lf seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    for (i = 0; i < rows; i++)
        free(matrix1[i]);
    free(matrix1);

    for (i = 0; i < rows; i++)
        free(matrix2[i]);
    free(matrix2);

    for (i = 0; i < rows; i++)
        free(result[i]);
    free(result);

    return 0;
}