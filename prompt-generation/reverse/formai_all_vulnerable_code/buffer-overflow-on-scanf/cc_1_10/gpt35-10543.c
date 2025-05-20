//FormAI DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void displayMatrix(int matrix[ROWS][COLS]);
void addMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]);
void subtractMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]);
void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]);

int main()
{
    int matrixA[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int resultMatrix[ROWS][COLS];
    int option;

    printf("Choose a matrix operation:\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Multiplication\n");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            addMatrices(matrixA, matrixB, resultMatrix);
            printf("The result of matrix addition is:\n");
            displayMatrix(resultMatrix);
            break;
        case 2:
            subtractMatrices(matrixA, matrixB, resultMatrix);
            printf("The result of matrix subtraction is:\n");
            displayMatrix(resultMatrix);
            break;
        case 3:
            multiplyMatrices(matrixA, matrixB, resultMatrix);
            printf("The result of matrix multiplication is:\n");
            displayMatrix(resultMatrix);
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}

void displayMatrix(int matrix[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            resultMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS])
{
    int i, j, k;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            resultMatrix[i][j] = 0;
            for (k = 0; k < ROWS; k++)
            {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}