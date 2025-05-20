//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int rows1,cols1,rows2,cols2,i,j,k;
    int **matrix1,**matrix2,**result;
    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d%d",&rows1,&cols1);
    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d%d",&rows2,&cols2);

    if(cols1!=rows2)
    {
        printf("Multiplication is not possible. Exiting...\n");
        exit(0);
    }

    matrix1=(int **)malloc(rows1*sizeof(int *));
    matrix2=(int **)malloc(rows2*sizeof(int *));
    result=(int **)malloc(rows1*sizeof(int *));

    for(i=0;i<rows1;i++)
    {
        matrix1[i]=(int *)malloc(cols1*sizeof(int));
        result[i]=(int *)malloc(cols2*sizeof(int));
    }
    for(i=0;i<rows2;i++)
    {
        matrix2[i]=(int *)malloc(cols2*sizeof(int));
    }

    printf("Enter the elements of first matrix:\n");
    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols1;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for(i=0;i<rows2;i++)
    {
        for(j=0;j<cols2;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }

    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols2;j++)
        {
            result[i][j]=0;
            for(k=0;k<cols1;k++)
            {
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    printf("Product of matrices:\n");
    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols2;j++)
        {
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<rows1;i++)
    {
        free(matrix1[i]);
        free(result[i]);
    }

    for(i=0;i<rows2;i++)
    {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}