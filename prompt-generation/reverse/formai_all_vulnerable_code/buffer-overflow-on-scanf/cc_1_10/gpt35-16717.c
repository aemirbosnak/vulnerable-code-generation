//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>

/* Function to perform binary search on an array of integers */
int binarySearch(int arr[], int num, int key)
{
    int low = 0, high = num - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            printf("\nFound %d at position %d\n", key, mid + 1);
            return 1;
        }

        else if (arr[mid] > key)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return 0;
}

/* Main function */
int main()
{
    int arr[10] = {1, 3, 5, 9, 10, 14, 15, 18, 20, 22};
    int key, result;

    // Get element to be searched from user
    printf("Enter element to be searched: ");
    scanf("%d", &key);

    // Perform binary search
    result = binarySearch(arr, 10, key);

    if (!result)
    {
        printf("Element not found\n");
    }

    return 0;
}