//FormAI DATASET v1.0 Category: Searching algorithm ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// Function to implement the binary search algorithm
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

// Function to implement the interpolation search algorithm
int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
 
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        int pos = lo + (((double)(hi-lo) / (arr[hi]-arr[lo]))*(x - arr[lo]));
 
        if (arr[pos] == x)
            return pos;
 
        if (arr[pos] < x)
            lo = pos + 1;
 
        else
            hi = pos - 1;
    }

    return -1;
}
 
int main()
{
    int i, n, x, arr[MAX], choice, result;

    // Reading user's input
    printf("\nEnter the number of elements in the array: ");
    scanf("%d",&n);
 
    printf("\nEnter the elements of the array (in ascending order):\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
 
    printf("\nEnter the element to be searched: ");
    scanf("%d",&x);

    // Offering the user to choose between different searching algorithms
    printf("\nSelect a searching algorithm for the array (1/2):\n1. Binary Search\n2. Interpolation Search\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            // Calling the binary search function
            result = binarySearch(arr, 0, n-1, x);
            break;
        case 2:
            // Calling the interpolation search function
            result = interpolationSearch(arr, n, x);
            break;
        default:
            printf("\nInvalid choice!");
            return 0;
    }

    // Displaying the search result
    if(result == -1)
        printf("\nElement not found!\n");
    else
        printf("\nElement found at index %d!\n",result);
 
    return 0;
}