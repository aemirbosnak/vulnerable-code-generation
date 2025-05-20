//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void database_manage(int **arr, int n, int m)
{
    int i, j, k, search_key;

    printf("Enter the number of records: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter the value for record %d, column %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the search key: ");
    scanf("%d", &search_key);

    for (k = 0; k < n; k++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[k][j] == search_key)
            {
                printf("Record found: ");
                for (i = 0; i < m; i++)
                {
                    printf("%d ", arr[k][i]);
                }
                printf("\n");
            }
        }
    }

    free(arr);
}

int main()
{
    int **arr;
    int n, m;

    database_manage(arr, n, m);

    return 0;
}