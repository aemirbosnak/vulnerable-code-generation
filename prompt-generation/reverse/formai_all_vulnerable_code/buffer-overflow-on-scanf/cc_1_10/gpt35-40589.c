//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include<stdio.h>

/* A function to sort an array using greedy algorithm */
void greedy_sort(int arr[],int n)
{
    int i,j,min_idx;

    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }
        if(min_idx!=i) 
        {
            // Swap elements
            int temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
        }
    }
}

int main()
{
    int arr[100],n,i;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nBefore Sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    greedy_sort(arr,n);

    printf("\n\nAfter Sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}