//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int main()
{
    int arr[MAX_SIZE];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int search_key;
    printf("Enter the element to search: ");
    scanf("%d", &search_key);

    int index = binary_search(arr, search_key, 0, n - 1);
    if (index == -1)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Element found at index %d!\n", index);
    }

    return 0;
}

int binary_search(int arr[], int search_key, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == search_key)
        {
            return mid;
        }
        else if (arr[mid] > search_key)
        {
            return binary_search(arr, search_key, low, mid - 1);
        }
        else
        {
            return binary_search(arr, search_key, mid + 1, high);
        }
    }

    return -1;
}