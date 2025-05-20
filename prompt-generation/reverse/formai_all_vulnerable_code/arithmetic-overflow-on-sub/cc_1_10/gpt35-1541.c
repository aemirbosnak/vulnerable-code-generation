//FormAI DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;   // if the key is not found
}

int main()
{
    int n, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array in sorted order:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int index = binarySearch(arr, n, key);

    if (index != -1)
    {
        printf("The key %d is found at index %d.\n", key, index);
    }
    else
    {
        printf("The key %d is not found in the array!\n", key);
    }

    return 0;
}