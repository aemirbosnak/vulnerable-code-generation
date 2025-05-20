//FormAI DATASET v1.0 Category: Matrix operations ; Style: recursive
#include<stdio.h>

void display(int arr[][3],int i,int j)
{
    if(i<=2)
    {
        if(j<=2)
        {
            printf("%d ",arr[i][j]);
            display(arr,i,j+1);
        }
        else
        {
            printf("\n");
            display(arr,i+1,0);

        }
    }
}

void add(int A[][3],int B[][3],int C[][3],int i,int j)
{
    if(i<=2)
    {
        if(j<=2)
        {
            C[i][j]=A[i][j]+B[i][j];
            add(A,B,C,i,j+1);
        }
        else
        {
            add(A,B,C,i+1,0);
        }
    }
}

void sub(int A[][3],int B[][3],int C[][3],int i,int j)
{
    if(i<=2)
    {
        if(j<=2)
        {
            C[i][j]=A[i][j]-B[i][j];
            sub(A,B,C,i,j+1);
        }
        else
        {
            sub(A,B,C,i+1,0);
        }
    }
}

void mul(int A[][3],int B[][3],int C[][3],int i,int j,int k)
{
    if(i<=2)
    {
        if(j<=2)
        {
            if(k<=2)
            {
                C[i][j]+=A[i][k]*B[k][j];
                mul(A,B,C,i,j,k+1);
            }
            else
            {
                mul(A,B,C,i,j+1,0);
            }
        }
        else
        {
            mul(A,B,C,i+1,0,0);
        }
    }
}

int main()
{
    int A[3][3],B[3][3],C[3][3];
    printf("Enter the elements of 3x3 matrix A:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the elements of 3x3 matrix B:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    printf("Matrix A:\n");
    display(A,0,0);
    printf("Matrix B:\n");
    display(B,0,0);
    add(A,B,C,0,0);
    printf("Sum of matrices:\n");
    display(C,0,0);
    sub(A,B,C,0,0);
    printf("Difference of matrices:\n");
    display(C,0,0);
    mul(A,B,C,0,0,0);
    printf("Product of matrices:\n");
    display(C,0,0);
    return 0;
}