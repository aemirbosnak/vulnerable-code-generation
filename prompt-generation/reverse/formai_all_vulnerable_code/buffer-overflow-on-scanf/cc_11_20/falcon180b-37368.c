//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100

void main()
{
    int i,j,k,m,n,p,q;
    char ch;
    
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d%d",&m,&n);
    
    int **a= (int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
    }
    
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d%d",&p,&q);
    
    if(n!=p)
    {
        printf("The matrices can't be multiplied with each other.\n");
        exit(0);
    }
    
    int **b= (int **)malloc(p*sizeof(int *));
    for(i=0;i<p;i++)
    {
        b[i]=(int *)malloc(q*sizeof(int));
    }
    
    printf("Enter the elements of second matrix:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    
    int **c= (int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
    {
        c[i]=(int *)malloc(q*sizeof(int));
    }
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    
    printf("Product of matrices:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<m;i++)
    {
        free(a[i]);
    }
    free(a);
    
    for(i=0;i<p;i++)
    {
        free(b[i]);
    }
    free(b);
    
    for(i=0;i<m;i++)
    {
        free(c[i]);
    }
    free(c);
}