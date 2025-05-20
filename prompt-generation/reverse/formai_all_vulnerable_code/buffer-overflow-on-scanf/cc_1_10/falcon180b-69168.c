//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void generate_matrix(int **mat, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = rand() % 100;
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    generate_matrix(matrix, rows, cols);
    printf("Generated matrix:\n");
    print_matrix(matrix, rows, cols);

    int **transpose = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose of the matrix:\n");
    print_matrix(transpose, cols, rows);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++) {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}