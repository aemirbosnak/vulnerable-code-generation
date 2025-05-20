//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: safe
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rows,cols;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    printf("Enter the number of columns: ");
    scanf("%d",&cols);

    int **matrix1 = (int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++)
    {
        matrix1[i] = (int *)malloc(cols*sizeof(int));
    }

    printf("Enter the elements of matrix 1:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }

    int **matrix2 = (int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++)
    {
        matrix2[i] = (int *)malloc(cols*sizeof(int));
    }

    printf("Enter the elements of matrix 2:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }

    int **sum = (int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++)
    {
        sum[i] = (int *)malloc(cols*sizeof(int));
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("The sum of the two matrices is:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<rows;i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    for(int i=0;i<rows;i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);

    for(int i=0;i<rows;i++)
    {
        free(sum[i]);
    }
    free(sum);

    return 0;
}