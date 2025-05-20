//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, found = 0;
    char **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (char**)malloc(n * sizeof(char*));

    for (i = 0; i < n; i++)
    {
        arr[i] = (char*)malloc(10 * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    printf("Enter the search element: ");
    scanf("%s", &k);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (strcmp(arr[i], k) == 0)
            {
                found = 1;
                printf("Element found at index %d, slot %d\n", i, j);
            }
        }
    }

    if (!found)
    {
        printf("Element not found\n");
    }

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}