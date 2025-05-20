//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n)
{
    int i,j;
    int *bucket = malloc(sizeof(int)*n);
    for(i=0;i<n;++i)
    {
        bucket[i]=0;
    }
    for(i=0;i<n;++i)
    {
        ++bucket[arr[i]];
    }
    for(i=0,j=0;i<n;++i)
    {
        for(;bucket[i]>0;--bucket[i])
        {
            arr[j++]=i;
        }
    }
    free(bucket);
}

int main()
{
    printf("Welcome to the C Bucket Sort Implementation program!\n");
    printf("This program sorts an array of integers using the bucket sort algorithm.\n");
    int n,i;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    int *arr = malloc(sizeof(int)*n);
    printf("Enter the integers to be sorted: ");
    for(i=0;i<n;++i)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted array: ");
    for(i=0;i<n;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    bucketSort(arr,n);
    printf("Sorted array: ");
    for(i=0;i<n;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    printf("Thank you for using the C Bucket Sort Implementation program!\n");
    return 0;
}