//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 50
#define MAX_COLS 50

int generate_random_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101;
        }
    }
    return 0;
}

void print_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int temp[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Matrix dimensions are too large.\n");
        return 1;
    }

    generate_random_matrix(matrix, rows, cols);
    printf("Original Matrix:\n");
    print_matrix(matrix, rows, cols);

    transpose_matrix(matrix, rows, cols);
    printf("\nTransposed Matrix:\n");
    print_matrix(matrix, cols, rows);

    return 0;
}