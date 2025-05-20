//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int matrix2[ROWS][COLS] = {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}};
    int sum_matrix[ROWS][COLS];

    // Matrix Addition
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print Sum Matrix
    printf("Sum Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", sum_matrix[i][j]);
        }
        printf("\n");
    }

    // Matrix Multiplication
    int product_matrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < COLS; k++) {
                product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print Product Matrix
    printf("\nProduct Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", product_matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose of Matrix
    int transpose_matrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transpose_matrix[j][i] = matrix1[i][j];
        }
    }

    // Print Transpose Matrix
    printf("\nTranspose Matrix:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%d ", transpose_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}