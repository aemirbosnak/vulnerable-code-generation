//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, found = 0;
    char **arr = NULL;

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * MAX);

    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX);
    }

    // Fill the array with characters
    for (i = 0; i < n; i++)
    {
        printf("Enter the character for slot %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    // Search for a character
    printf("Enter the character you want to find: ");
    scanf("%s", &k);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (strcmp(arr[i], k) == 0)
            {
                found = 1;
                printf("Character found at slot %d, column %d\n", i + 1, j + 1);
            }
        }
    }

    if (found == 0)
    {
        printf("Character not found\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}