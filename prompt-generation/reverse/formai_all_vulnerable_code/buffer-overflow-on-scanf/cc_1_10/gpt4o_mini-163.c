//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void display_matrix(int rows, int cols, int matrix[rows][cols], const char* name) {
    printf("Oh, behold the matrix of %s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int rows, int cols, int a[rows][cols], int b[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply_matrices(int a_rows, int a_cols, int a[a_rows][a_cols], int b_cols, int result[a_rows][b_cols]) {
    int b[a_cols][b_cols];
    printf("Enter elements for second matrix:\n");
    for (int i = 0; i < a_cols; i++) {
        for (int j = 0; j < b_cols; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            result[i][j] = 0; // Begin with the void of nothing
            for (int k = 0; k < a_cols; k++) {
                result[i][j] += a[i][k] * b[k][j]; 
            }
        }
    }
}

int main() {
    int rows = 2; // Families of two they are
    int cols = 2; // Matrices join in pairs

    int romeo[rows][cols], juliet[rows][cols], sum[rows][cols], product[rows][cols];

    // Inputs for Romeo's heart
    printf("Enter Romeo's matrix (2x2):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &romeo[i][j]);
        }
    }
    
    display_matrix(rows, cols, romeo, "Romeo");

    // Inputs for Juliet's love
    printf("Enter Juliet's matrix (2x2):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &juliet[i][j]);
        }
    }

    display_matrix(rows, cols, juliet, "Juliet");

    // Operation of Addition
    add_matrices(rows, cols, romeo, juliet, sum);
    display_matrix(rows, cols, sum, "Their Sum");

    // Operation of Multiplication
    printf("Let us be the architects of a new bond:\n");
    multiply_matrices(rows, cols, romeo, cols, product);
    display_matrix(rows, cols, product, "Their Product");

    // Closing sentiments
    printf("And thus concluded our tale of numbers,\n");
    printf("United by love, they soar as one,\n");
    printf("In matrix realms of zeros and ones.\n");

    return 0;
}