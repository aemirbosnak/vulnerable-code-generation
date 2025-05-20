//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void initialize_matrix(int matrix[ROWS][COLS]);

void print_matrix(int matrix[ROWS][COLS]);

void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);

int main()
{
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int result_matrix[ROWS][COLS];
    
    printf("Enter values for matrix 1:\n");
    initialize_matrix(matrix1);
    
    printf("\nEnter values for matrix 2:\n");
    initialize_matrix(matrix2);
    
    printf("\nMatrix 1:\n");
    print_matrix(matrix1);
    
    printf("\nMatrix 2:\n");
    print_matrix(matrix2);
    
    multiply_matrices(matrix1, matrix2, result_matrix);
    
    printf("\nResult Matrix:\n");
    print_matrix(result_matrix);
    
    return 0;
}

void initialize_matrix(int matrix[ROWS][COLS])
{
    int row, col;
    
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            printf("Enter value for row %d, column %d: ", row+1, col+1);
            scanf("%d", &matrix[row][col]);
        }
    }
}

void print_matrix(int matrix[ROWS][COLS])
{
    int row, col;
    
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    int row, col, i;
    int sum;
    
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            sum = 0;
            for (i = 0; i < ROWS; i++)
            {
                sum += matrix1[row][i] * matrix2[i][col];
            }
            
            result[row][col] = sum;
        }
    }
}