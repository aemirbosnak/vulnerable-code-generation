//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,k,temp;
    int arr[100];
    int bucket[100];
    int max = 0;
    int min = 100;
    int range = 0;
    int count = 0;
    int *ptr;
    int *end;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    //calculating the range of the array
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
            max = arr[i];
        if(arr[i]<min)
            min = arr[i];
    }
    range = max - min + 1;

    //initializing the buckets
    for(i=0;i<range;i++)
        bucket[i] = -1;

    //placing the elements in the buckets
    for(i=0;i<n;i++)
        bucket[arr[i]-min]++;

    //sorting the array
    ptr = (int*)malloc(n*sizeof(int));
    end = ptr + n;
    for(i=0;i<range;i++)
    {
        j = 0;
        for(k=0;k<n;k++)
        {
            if(bucket[i]!= -1 && arr[k] == i+min)
            {
                *ptr++ = arr[k];
                bucket[i]--;
            }
        }
        while(j<n)
        {
            if(bucket[i] == -1)
                break;
            else if(bucket[i] == 0)
            {
                printf("\nBucket %d is empty\n",i+min);
                break;
            }
            else
            {
                printf("\nBucket %d is not empty\n",i+min);
                for(k=0;k<n;k++)
                {
                    if(arr[k] == i+min)
                    {
                        *ptr++ = arr[k];
                        bucket[i]--;
                    }
                }
                j++;
            }
        }
    }

    //printing the sorted array
    printf("\nSorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",*(ptr+i));
    printf("\n");

    return 0;
}