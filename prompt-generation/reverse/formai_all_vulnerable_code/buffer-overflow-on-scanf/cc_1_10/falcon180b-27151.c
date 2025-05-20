//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include<stdio.h>

#define size 10

int main()
{
    int i,j,n;
    int arr[size];
    int max;
    int count[size]={0};

    printf("Enter the size of array: ");
    scanf("%d",&n);

    printf("Enter the elements of array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    max=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    printf("Max element is: %d\n",max);

    for(i=0;i<=max;i++)
    {
        count[i]=0;
    }

    for(i=0;i<n;i++)
    {
        count[arr[i]]++;
    }

    printf("Bucket array:\n");
    for(i=0;i<=max;i++)
    {
        printf("%d ",i);
    }

    printf("\n");

    for(i=0;i<=max;i++)
    {
        for(j=0;j<count[i];j++)
        {
            printf("%d ",i);
        }
    }

    return 0;
}