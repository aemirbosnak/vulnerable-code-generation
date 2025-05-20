//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n,i,j,k,l,count=0;
    int a[10][10],b[10][10],c[10][10],d[10][10];
    int sum=0;
    int s=0,e=9,t=0,f=9;
    int g=0,h=9,u=0,v=9;
    int x,y,z;
    int p,q,r;
    int m,n1,n2;
    int o=0;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d",&n,&n);

    printf("\nEnter the elements of the first matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=0;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            d[i][j]=c[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }

    return 0;
}