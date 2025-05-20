//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int main() {
    srand(time(NULL));
    int rows, cols;
    printf("Enter the number of rows and columns for the matrix:\n");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Invalid input. Please enter positive integers.\n");
        return 0;
    }

    int matrix[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("The original matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int **transpose_matrix;
    transpose_matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        transpose_matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose_matrix[j][i] = matrix[i][j];
        }
    }

    printf("\nThe transpose matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose_matrix[i][j]);
        }
        printf("\n");
    }

    free(transpose_matrix);

    return 0;
}