//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, found = 0;
    char **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (char**)malloc(n * sizeof(char*));

    for (i = 0; i < n; i++)
    {
        arr[i] = (char*)malloc(20 * sizeof(char));
    }

    printf("Enter the elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    printf("Enter the search element: ");
    scanf("%s", &l);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (strcmp(arr[i], l) == 0)
            {
                found = 1;
                break;
            }
        }
    }

    if (found)
    {
        printf("Element found!\n");
    }
    else
    {
        printf("Element not found.\n");
    }

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}