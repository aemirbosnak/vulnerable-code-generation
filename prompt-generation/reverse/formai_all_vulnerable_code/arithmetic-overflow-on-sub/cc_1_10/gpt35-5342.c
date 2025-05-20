//FormAI DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to perform binary search
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (key == arr[mid]) {
        return mid;
    }
    else if (key < arr[mid]) {
        return binarySearch(arr, low, mid - 1, key);
    }
    else {
        return binarySearch(arr, mid + 1, high, key);
    }
}

int main()
{
    int n, i, key, found;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array in ascending order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    found = binarySearch(arr, 0, n - 1, key);

    if (found == -1) {
        printf("Element not found!\n");
    }
    else {
        printf("Element found at index %d\n", found);
    }

    free(arr);
    return 0;
}