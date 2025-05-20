//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare an array of 100 integers
    int arr[100];

    // Initialize the array with random numbers
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Search for a target number
    int target = 500;

    // Start the search
    clock_t start = clock();
    int result = search(arr, target);
    clock_t end = clock();

    // Print the result
    if (result == -1)
    {
        printf("Target not found\n");
    }
    else
    {
        printf("Target found at index %d\n", result);
    }

    // Print the time taken
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.2f seconds\n", timeTaken);

    return 0;
}

int search(int *arr, int target)
{
    // Iterate over the array
    for (int i = 0; i < 100; i++)
    {
        // Compare the target number with the current element
        if (arr[i] == target)
        {
            // Target found
            return i;
        }
    }

    // Target not found
    return -1;
}