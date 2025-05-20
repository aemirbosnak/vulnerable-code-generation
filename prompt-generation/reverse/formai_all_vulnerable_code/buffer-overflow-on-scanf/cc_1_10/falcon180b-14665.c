//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10

void createMatrix(int matrix[MAX][MAX], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int size)
{
    int i, j, k;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            result[i][j] = 0;
            for(k = 0; k < size; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX], size;
    srand(time(0));
    printf("Enter the size of the matrices: ");
    scanf("%d", &size);
    createMatrix(matrix1, size);
    createMatrix(matrix2, size);
    printMatrix(matrix1, size);
    printMatrix(matrix2, size);
    addMatrices(matrix1, matrix2, result, size);
    printf("The sum of the matrices is:\n");
    printMatrix(result, size);
    subtractMatrices(matrix1, matrix2, result, size);
    printf("The difference of the matrices is:\n");
    printMatrix(result, size);
    multiplyMatrices(matrix1, matrix2, result, size);
    printf("The product of the matrices is:\n");
    printMatrix(result, size);
    return 0;
}