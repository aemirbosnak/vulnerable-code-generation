//Gemma-7B DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char **data = NULL;
    int i, j, k, n, m;
    char query[MAX];

    // Allocate memory for the data
    data = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        data[i] = (char *)malloc(m * sizeof(char));
    }

    // Read the data
    printf("Enter the number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the data for record %d: ", i + 1);
        scanf("%s", data[i]);
    }

    // Store the query
    printf("Enter your query: ");
    scanf("%s", query);

    // Search the data
    for (i = 0; i < n; i++)
    {
        for (j = 0; data[i][j] != '\0'; j++)
        {
            if (strstr(query, data[i][j]) != NULL)
            {
                printf("Record %d contains the query: %s\n", i + 1, data[i]);
            }
        }
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}