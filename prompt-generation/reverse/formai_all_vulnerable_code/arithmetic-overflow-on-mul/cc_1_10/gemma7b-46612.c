//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main()
{
    int n, i, key, found = 0;
    clock_t start, end;

    // Allocate memory for an array
    int *arr = (int *)malloc(n * sizeof(int));

    // Fill the array with random numbers
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % MAX;
    }

    // Start the timer
    start = clock();

    // Search for the key
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    // End the timer
    end = clock();

    // Calculate the time taken
    int timeTaken = (end - start) * 1000 / CLOCKS_PER_SEC;

    // Print the results
    if (found)
    {
        printf("Key found in %d ms\n", timeTaken);
    }
    else
    {
        printf("Key not found\n");
    }

    // Free the memory
    free(arr);

    return 0;
}