//Gemma-7B DATASET v1.0 Category: Sorting ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Crack the code and unveil the sorting algorithm
    int n;
    scanf("%d", &n);

    // Allocate memory like a magician's hat
    int *arr = malloc(n * sizeof(int));

    // Fill the array with secrets, one by one
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Shuffle the array, like a drunken dancer
    for (int i = 0; i < n; i++)
    {
        int r = rand() % n;
        int tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
    }

    // Sort the array in ascending order, like a master chef
    int i = 0;
    while (i < n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        i++;
    }

    // Display the sorted array, like a proud warrior
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Free the memory, like a responsible citizen
    free(arr);

    return 0;
}