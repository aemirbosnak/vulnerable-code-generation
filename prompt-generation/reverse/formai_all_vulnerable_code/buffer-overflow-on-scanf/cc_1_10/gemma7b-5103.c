//Gemma-7B DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char **arr = NULL;
    int i, j, k, n, m;
    char query[200];

    // Allocate memory for the array
    arr = (char **)malloc(n * m * sizeof(char *));

    // Read the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Read the data
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = getchar();
        }
    }

    // Print the data
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    free(arr);

    // Query the data
    printf("Enter your query: ");
    scanf("%s", query);

    // Search for the query in the data
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == query[0])
            {
                printf("Found: (%d, %d)\n", i, j);
            }
        }
    }

    return 0;
}