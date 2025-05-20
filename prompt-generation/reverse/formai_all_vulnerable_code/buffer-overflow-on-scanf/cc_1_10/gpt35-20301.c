//FormAI DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum array size

// Search function that returns the index of the element if found, -1 otherwise
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main()
{
    int n, x, arr[MAX_SIZE];

    // Get size of the array
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Get array elements
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    // Get element to search
    printf("Enter the element to search: ");
    scanf("%d", &x);

    // Search for the element
    int result = binarySearch(arr, 0, n-1, x);

    // Print the result
    if(result == -1)
        printf("Element not found in array.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}