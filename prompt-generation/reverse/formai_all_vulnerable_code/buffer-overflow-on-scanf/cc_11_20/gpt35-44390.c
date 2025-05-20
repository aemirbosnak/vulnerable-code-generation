//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols, choice;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];
    printf("Enter elements of first matrix: \n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements of second matrix: \n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("Enter the operation you want to perform (1 for addition, 2 for multiplication): ");
    scanf("%d", &choice);
    if(choice==1)
    {
        printf("Addition of first and second matrix: \n");
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
    else if(choice==2)
    {
        printf("Multiplication of first and second matrix: \n");
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                result[i][j] = 0;
                for(int k=0;k<cols;k++)
                {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    return 0;
}