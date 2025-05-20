//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int main()
{
    int i,j,n;
    int **a,**b,**c;
    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d",&n,&n);

    //Creating first matrix
    a=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
        printf("Enter the elements of row %d: ",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    //Creating second matrix
    b=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        b[i]=(int *)malloc(n*sizeof(int));
        printf("Enter the elements of row %d: ",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    //Creating third matrix for storing the result
    c=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        c[i]=(int *)malloc(n*sizeof(int));
    }

    //Performing matrix multiplication
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    //Printing the result
    printf("\nThe result of matrix multiplication is: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}