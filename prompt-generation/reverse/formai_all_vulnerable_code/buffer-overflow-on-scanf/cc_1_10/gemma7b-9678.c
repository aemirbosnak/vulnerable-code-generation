//Gemma-7B DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int arr[MAX_SIZE], i, j, n, count = 0, paranoid = 1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX_SIZE)
    {
        printf("Error: Number of elements exceeds the limit.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                count++;
            }
        }
    }

    if (count == 0)
    {
        printf("No sorting necessary.\n");
    }
    else
    {
        printf("Number of swaps: %d\n", count);
    }

    if (paranoid)
    {
        printf("Attention: The sorting algorithm may have been tampered with. Please verify the results.\n");
    }

    return 0;
}