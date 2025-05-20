//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Function to perform binary search (iteratively)
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

// Driver code
int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the element to be searched: ");
    int x;
    scanf("%d", &x);

    if (n == 0) {
        printf("Array is empty\n");
        return -1;
    }
    if (n == 1) {
        if (arr[0] == x)
            printf("Element found at index 0\n");
        else
            printf("Element not found\n");
        return -1;
    }

    int result = linearSearch(arr, n, x);
    (result == -1) ? printf("Element not present in the array\n")
                   : printf("Element found at index %d\n", result);

    result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element not present in the array\n")
                   : printf("Element found at index %d\n", result);

    return 0;
}