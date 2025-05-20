//FormAI DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

/* Function prototypes */
void printMatrix(int matrix[ROWS][COLS]);
void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);
void multiplyMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);

int main()
{
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];
    int choice;
    srand(time(NULL));  // Initialize random number generator

    /* Initialize matrices with random numbers */
    printf("Matrix 1:\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            matrix1[i][j] = rand() % 10;
        }
    }
    printMatrix(matrix1);

    printf("\nMatrix 2:\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            matrix2[i][j] = rand() % 10;
        }
    }
    printMatrix(matrix2);

    /* Menu for matrix operations */
    do
    {
        printf("\nSelect an operation:\n"
               "1 - Add matrices\n"
               "2 - Multiply matrices\n"
               "0 - Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addMatrix(matrix1, matrix2, result);
                printf("\nResult of addition:\n");
                printMatrix(result);
                break;
            case 2:
                multiplyMatrix(matrix1, matrix2, result);
                printf("\nResult of multiplication:\n");
                printMatrix(result);
                break;
            case 0:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }

    } while(choice != 0);

    return 0;
}

/* Function to print the elements of a matrix */
void printMatrix(int matrix[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to perform matrix addition */
void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/* Function to perform matrix multiplication */
void multiplyMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    int sum;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            sum = 0;
            for(int k = 0; k < COLS; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}