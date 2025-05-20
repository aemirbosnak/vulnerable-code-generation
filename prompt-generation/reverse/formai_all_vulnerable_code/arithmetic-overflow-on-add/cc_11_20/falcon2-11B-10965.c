//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main() {
    // Define matrices
    int matrix1[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int matrix2[ROWS][COLS] = {
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };
    
    int matrix3[ROWS][COLS] = {
        {25, 26, 27, 28},
        {29, 30, 31, 32},
        {33, 34, 35, 36}
    };
    
    // Multiply matrices
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix3[i][j] = 0;
            
            for (int k = 0; k < COLS; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // Add matrices
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix3[i][j] += matrix1[i][j];
        }
    }
    
    // Print matrices
    printf("Matrix 1:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    
    printf("Matrix 2:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    printf("Matrix 3:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}