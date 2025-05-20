//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int result[ROWS][COLS];
    
    printf("Enter values for the first %dx%d matrix:\n", ROWS, COLS);
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("\nEnter values for the second %dx%d matrix:\n", ROWS, COLS);
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Addition of matrices
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Print the result of the addition
    printf("\nAddition of the two matrices is:\n");
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Multiplication of matrices
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // Print the result of the multiplication
    printf("\nMultiplication of the two matrices is:\n");
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}