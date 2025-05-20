//Falcon-180B DATASET v1.0 Category: Memory management ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int main()
{
    int i,j,n;
    float **matrix1,**matrix2,**result;
    float sum=0;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d%d",&n,&n);

    matrix1=(float **)malloc(n*sizeof(float *));
    matrix2=(float **)malloc(n*sizeof(float *));
    result=(float **)malloc(n*sizeof(float *));

    for(i=0;i<n;i++)
    {
        matrix1[i]=(float *)malloc(n*sizeof(float));
        matrix2[i]=(float *)malloc(n*sizeof(float));
        result[i]=(float *)malloc(n*sizeof(float));
    }

    printf("Enter the elements of the first matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%f",&matrix1[i][j]);
        }

    printf("Enter the elements of the second matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%f",&matrix2[i][j]);
        }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            result[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }

    printf("The sum of the two matrices is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%f\t",result[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}