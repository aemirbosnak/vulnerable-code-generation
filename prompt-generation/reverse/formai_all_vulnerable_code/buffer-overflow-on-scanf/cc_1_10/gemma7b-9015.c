//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **arr = NULL;
    int n, m, i, j, k, l, count = 0, found = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the target number: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == k)
            {
                found = 1;
                break;
            }
        }
    }

    if (found)
    {
        printf("The target number has been found.\n");
    }
    else
    {
        printf("The target number has not been found.\n");
    }

    free(arr);

    return 0;
}