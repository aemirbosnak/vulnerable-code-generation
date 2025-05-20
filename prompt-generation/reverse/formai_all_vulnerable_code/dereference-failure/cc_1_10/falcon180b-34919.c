//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 1000000

int main()
{
    int i,j,k;
    int **a,**b,**c;
    int sum=0;
    clock_t start,end;
    double cpu_time_used;

    a=(int **)malloc(sizeof(int *)*2);
    b=(int **)malloc(sizeof(int *)*2);
    c=(int **)malloc(sizeof(int *)*2);

    for(i=0;i<2;i++)
    {
        a[i]=(int *)malloc(sizeof(int)*SIZE);
        b[i]=(int *)malloc(sizeof(int)*SIZE);
        c[i]=(int *)malloc(sizeof(int)*SIZE);
    }

    for(i=0;i<SIZE;i++)
    {
        a[0][i]=i;
        b[0][i]=i*2;
    }

    start=clock();

    for(k=0;k<10;k++)
    {
        for(i=0;i<SIZE;i++)
        {
            sum=0;
            for(j=0;j<SIZE;j++)
            {
                sum+=a[0][i]*b[0][j];
            }
            c[0][i]=sum;
        }
    }

    end=clock();
    cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;

    printf("Time taken by the program: %lf\n",cpu_time_used);

    for(i=0;i<SIZE;i++)
    {
        printf("%d ",c[0][i]);
    }

    return 0;
}