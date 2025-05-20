//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int main()
{
    int m,n,i,j;
    printf("Enter number of rows: ");
    scanf("%d",&m);
    printf("Enter number of columns: ");
    scanf("%d",&n);
    int **matrix1=malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        matrix1[i]=malloc(n*sizeof(int));
    }
    printf("Enter elements of first matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    int **matrix2=malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        matrix2[i]=malloc(n*sizeof(int));
    }
    printf("Enter elements of second matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    int **sum=malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        sum[i]=malloc(n*sizeof(int));
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    printf("Sum of matrices:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}