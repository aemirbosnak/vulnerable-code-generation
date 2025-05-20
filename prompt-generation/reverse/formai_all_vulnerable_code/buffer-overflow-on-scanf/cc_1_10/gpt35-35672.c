//FormAI DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

void printMat(int rows, int cols, int matrix[][cols])
{
    int i, j;

    printf("\nThe Matrix is:\n");

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int matrix1[][cols], int matrix2[][cols], int result[][cols])
{
    int i, j;

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(int rows1, int cols1, int matrix1[][cols1], int rows2, int cols2, int matrix2[][cols2], int result[][cols2])
{
    int i, j, k;

    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols2;j++)
        {
            result[i][j] = 0;

            for(k=0;k<cols1;k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int rows1, cols1, rows2, cols2, i, j;

    printf("Enter the number of rows and columns of Matrix 1: ");
    scanf("%d %d",&rows1,&cols1);

    printf("Enter the number of rows and columns of Matrix 2: ");
    scanf("%d %d",&rows2,&cols2);

    if(cols1!=rows2)
    {
        printf("\nMatrix Multiplication is not possible\n");
        return 0;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    printf("\nEnter the elements of Matrix 1:\n");

    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols1;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("\nEnter the elements of Matrix 2:\n");

    for(i=0;i<rows2;i++)
    {
        for(j=0;j<cols2;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }

    printMat(rows1, cols1, matrix1);
    printMat(rows2, cols2, matrix2);

    addMatrices(rows1, cols1, matrix1, matrix2, result);

    printf("\nMatrix Addition:\n");
    printMat(rows1, cols1, result);

    multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

    printf("\nMatrix Multiplication:\n");
    printMat(rows1, cols2, result);

    return 0;
}