//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: calm
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rows,cols,i,j;

    printf("Enter number of rows: ");
    scanf("%d",&rows);

    printf("Enter number of columns: ");
    scanf("%d",&cols);

    int **matrix = (int **)malloc(rows*sizeof(int *));
    for(i=0;i<rows;i++)
    {
        matrix[i] = (int *)malloc(cols*sizeof(int));
    }

    printf("Enter elements of matrix:\n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("Sum of all elements in matrix:\n");
    int sum=0;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            sum+=matrix[i][j];
        }
    }
    printf("%d\n",sum);

    printf("Product of all elements in matrix:\n");
    int product=1;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            product*=matrix[i][j];
        }
    }
    printf("%d\n",product);

    printf("Transpose of matrix:\n");
    int **transpose = (int **)malloc(cols*sizeof(int *));
    for(i=0;i<cols;i++)
    {
        transpose[i] = (int *)malloc(rows*sizeof(int));
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    for(i=0;i<cols;i++)
    {
        for(j=0;j<rows;j++)
        {
            printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<rows;i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for(i=0;i<cols;i++)
    {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}