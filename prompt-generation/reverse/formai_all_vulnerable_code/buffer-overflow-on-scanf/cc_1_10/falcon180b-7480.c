//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE], n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, key, 0, n-1);
    if (index == -1)
    {
        printf("Element not found in the array.");
    }
    else
    {
        printf("Element found at index: %d", index);
    }

    return 0;
}

int binarySearch(int arr[], int key, int left, int right)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(arr, key, left, mid - 1);
        }
        else
        {
            return binarySearch(arr, key, mid + 1, right);
        }
    }
    return -1;
}