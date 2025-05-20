//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,i,j;
    int **matrix;
    double **mat;
    double **temp;
    double **result;
    printf("Enter the number of matrices: ");
    scanf("%d",&n);
    matrix = (int **)malloc(n*sizeof(int *));
    mat = (double **)malloc(n*sizeof(double *));
    temp = (double **)malloc(n*sizeof(double *));
    result = (double **)malloc(n*sizeof(double *));
    for(i=0;i<n;i++)
    {
        matrix[i] = (int *)malloc(3*sizeof(int));
        mat[i] = (double *)malloc(3*sizeof(double));
        temp[i] = (double *)malloc(3*sizeof(double));
        result[i] = (double *)malloc(3*sizeof(double));
        printf("Enter the elements of the matrix: ");
        for(j=0;j<3;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Enter the elements of the other matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            mat[i][j] = matrix[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            temp[i][j] = matrix[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            result[i][j] = 0.0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            for(int k = 0; k < 3; k++)
            {
                result[i][j] += mat[i][k] * temp[k][j];
            }
        }
    }
    printf("The result is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%lf ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}