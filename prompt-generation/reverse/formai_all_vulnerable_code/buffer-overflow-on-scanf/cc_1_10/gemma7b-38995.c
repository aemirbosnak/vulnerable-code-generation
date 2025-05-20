//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main()
{
    int n, i, j, k, l, count = 0, arr[MAX], freq[MAX], pos[MAX], original[MAX];
    char ch;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Calculate frequency of each element
    for (i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Find the position of each element in the sorted order
    for (i = 0; i < MAX; i++)
    {
        if (freq[i] > 0)
        {
            pos[count] = i;
            count++;
        }
    }

    // Reconstruct the original array
    for (i = 0; i < n; i++)
    {
        original[i] = arr[pos[i]];
    }

    // Print the original array
    printf("The original array is:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", original[i]);
    }

    return 0;
}