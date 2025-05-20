//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int i,j,n,m,k;
    double sum=0,av;
    int **a,**b,**c;
    int *row,*col;
    clock_t start,end;
    double cpu_time_used;

    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d%d",&m,&n);

    a=(int **)malloc(m*sizeof(int *));
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
    scanf("%d%d",&n,&k);

    b=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        b[i]=(int *)malloc(k*sizeof(int));
    }

    printf("Enter the elements of second matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    c=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
    {
        c[i]=(int *)malloc(k*sizeof(int));
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<k;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }

    printf("The product of two matrices is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<k;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}