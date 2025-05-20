//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    int i,j,k,n,m,sum=0,temp;
    double start,end;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    for(i=0;i<n;i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the number of times you want to run the benchmark: ");
    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        start=clock();

        for(j=0;j<n-1;j++)
        {
            for(k=0;k<n-j-1;k++)
            {
                if(arr[k]>arr[k+1])
                {
                    temp=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;
                }
            }
        }

        end=clock();

        sum+=(end-start);
    }

    printf("\nAverage time taken for %d runs: %lf seconds",m,((double)sum)/m);

    return 0;
}