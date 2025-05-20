//FormAI DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>

// Function to search for a number in a given array
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        // If the element is found, return the index
        if (arr[i] == x)
            return i;
    }

    // If the element is not found, return -1
    return -1;
}

int main()
{
    int n, x, i;

    // Get the length of the array
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    // Create an array of the given length
    int arr[n];

    // Get the values for the array
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Get the number to search for
    printf("Enter the number to search for: ");
    scanf("%d", &x);

    // Search for the number in the array
    int index = search(arr, n, x);

    // Print the result
    if (index != -1)
        printf("The number %d is found at index %d\n", x, index);
    else
        printf("The number %d is not found in the array\n", x);

    return 0;
}