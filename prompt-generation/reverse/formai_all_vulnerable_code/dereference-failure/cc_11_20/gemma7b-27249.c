//Gemma-7B DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));
    int n = 0, i, j;

    // Gather evidence
    printf("Enter the number of suspects: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
        printf("Enter the suspect's name: ");
        scanf("%s", arr[i]);
    }

    // Create an index to categorize suspects
    int **index = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        index[i] = (int *)malloc(MAX * sizeof(int));
        for (j = 0; j < MAX; j++)
            index[i][j] = -1;
    }

    // Analyze the evidence
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (strcmp(arr[i], arr[j]) == 0)
                {
                    index[i][j] = 1;
                }
            }
        }
    }

    // Solve the case
    int guilty = -1;
    for (i = 0; i < n; i++)
    {
        int count = 0;
        for (j = 0; j < n; j++)
        {
            if (index[i][j] == 1)
                count++;
        }
        if (count > 1)
        {
            guilty = i;
            break;
        }
    }

    // Reveal the culprit
    if (guilty != -1)
    {
        printf("The culprit is: %s", arr[guilty]);
    }
    else
    {
        printf("No culprit found.");
    }

    // Free the evidence
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
    free(index);

    return 0;
}