//FormAI DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>

// Function to implement unique searching algorithm
int unique_search(int arr[], int n, int key)
{
    int i = 0, j = 0, flag = 0;

    // Loop through the array
    for (i = 0; i < n; i++)
    {
        // Check if the current element matches the key
        if (arr[i] == key)
        {
            // If the key is found once, set flag to 1
            if (flag == 0)
            {
                flag = 1;
                j = i;
            }
            // If the key is found again, return -1 (not unique)
            else
            {
                return -1;
            }
        }
    }

    // If the key is found only once, return its index
    if (flag == 1)
    {
        return j;
    }
    // Otherwise, return -1 (not found)
    else
    {
        return -1;
    }
}

// Main function to test the unique searching algorithm
int main()
{
    printf("Welcome to the unique searching program!\n\n");

    // Initialize the array with some random values
    int arr[] = { 1, 2, 3, 4, 3, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Ask the user to enter a key to search
    int key;
    printf("Enter a key to search: ");
    scanf("%d", &key);

    // Call the unique searching function to search for the key
    int index = unique_search(arr, n, key);

    // Display the result based on the index returned by the function
    if (index == -1)
    {
        printf("\nSorry, the key is either not found or not unique :(\n");
    }
    else
    {
        printf("\nYay! The key is found at index %d :)\n", index);
    }

    return 0;
}