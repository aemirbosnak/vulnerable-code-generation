//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAX 100

int main()
{
    int i,j,k,l,m,n,p;
    int choice;
    int **a,**b;
    int *x,*y;
    int flag=0;

    printf("\nEnter the number of bits for the keys: ");
    scanf("%d",&n);

    a=(int **)malloc(sizeof(int *)*n);
    b=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++)
    {
        a[i]=(int *)malloc(sizeof(int)*n);
        b[i]=(int *)malloc(sizeof(int)*n);
    }

    printf("\nEnter the public key:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nEnter the private key:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    printf("\nEnter the message: ");
    scanf("%d",&m);

    for(i=0;i<n;i++)
    {
        x[i]=(int)rand();
        y[i]=(int)rand();
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                a[i][j]=1;
                b[i][j]=0;
            }
            else
            {
                a[i][j]=0;
                b[i][j]=0;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                for(k=0;k<n;k++)
                {
                    if(a[i][k]==1)
                    {
                        b[j][k]=(b[j][k]+a[i][k])%2;
                    }
                }
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(b[i][j]==1)
                {
                    x[i]=(x[i]+y[j])%2;
                }
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }

    printf("\n");

    return 0;
}