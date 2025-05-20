//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, found = 0;
    char ***a = NULL;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &i);

    a = (char ***)malloc(n * sizeof(char **));
    for (j = 0; j < n; j++)
    {
        a[j] = (char **)malloc(i * sizeof(char *));
        for (k = 0; k < i; k++)
        {
            a[j][k] = (char *)malloc(10 * sizeof(char));
        }
    }

    printf("Enter the elements of the matrix: ");
    for (l = 0; l < n; l++)
    {
        for (j = 0; j < i; j++)
        {
            scanf("%s", a[l][j]);
        }
    }

    printf("Enter the search element: ");
    char searchElement[10];
    scanf("%s", searchElement);

    for (l = 0; l < n; l++)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(a[l][j], searchElement) == 0)
            {
                found = 1;
                printf("Element found at (%d, %d)\n", l, j);
            }
        }
    }

    if (!found)
    {
        printf("Element not found\n");
    }

    for (j = 0; j < n; j++)
    {
        for (k = 0; k < i; k++)
        {
            free(a[j][k]);
        }
        free(a[j]);
    }

    free(a);

    return 0;
}