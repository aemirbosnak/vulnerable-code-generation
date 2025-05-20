//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n,i,j,k;
    int **a,**b,**c;
    clock_t start,end;
    double cpu_time_used;

    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d",&n,&n);

    a=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
    }

    b=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        b[i]=(int *)malloc(n*sizeof(int));
    }

    c=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        c[i]=(int *)malloc(n*sizeof(int));
    }

    printf("Enter the elements of the first matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    start=clock();
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
    end=clock();
    cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;

    printf("The product of the matrices is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

    printf("CPU time used: %lf seconds\n",cpu_time_used);

    for(i=0;i<n;i++)
    {
        free(a[i]);
    }
    free(a);

    for(i=0;i<n;i++)
    {
        free(b[i]);
    }
    free(b);

    for(i=0;i<n;i++)
    {
        free(c[i]);
    }
    free(c);

    return 0;
}