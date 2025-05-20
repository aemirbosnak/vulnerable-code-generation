//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

// Function Declaration
int binarySearch(int arr[],int n,int x);

int main()
{
    int n, arr[100], i, x, pos;

    // Input Size of Array
    printf("Enter size of array: ");
    scanf("%d",&n);

    // Input Array Elements
    printf("Enter array elements (in sorted order): ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    // Input Element to be Searched
    printf("Enter element to be searched: ");
    scanf("%d",&x);

    // Perform Binary Search
    pos=binarySearch(arr,n,x);

    // Display Result
    if(pos==-1)
        printf("Element not found in the array!");
    else
        printf("Element found at position %d.",pos);

    return 0;
}

// Binary Search Function Definition
int binarySearch(int arr[],int n,int x)
{
    int beg=0,end=n-1,mid,pos=-1;

    while(beg<=end)
    {
        mid=(beg+end)/2;

        if(arr[mid]==x)
        {
            pos=mid+1; // 1-based index
            break;
        }
        else if(arr[mid]>x)
            end=mid-1;
        else
            beg=mid+1;
    }

    return pos;
}