//Gemma-7B DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **data = NULL;
    int **frequency = NULL;
    int i = 0, j = 0, k = 0, l = 0, n = 0;

    // Allocate memory for data and frequency
    data = (char **)malloc(n * sizeof(char *));
    frequency = (int **)malloc(n * sizeof(int *));

    // Get the number of words in the text
    printf("Enter the number of words in the text: ");
    scanf("%d", &n);

    // Get the text
    printf("Enter the text: ");
    data[0] = (char *)malloc(n * sizeof(char));
    scanf("%s", data[0]);

    // Tokenize the text
    char *token = strtok(data[0], " ");

    // Create a frequency table
    frequency = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        frequency[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            frequency[i][j] = 0;
        }
    }

    // Iterate over the tokens and increment the frequency of each token
    while (token != NULL)
    {
        for (i = 0; i < n; i++)
        {
            if (strcmp(token, data[i]) == 0)
            {
                frequency[i][k]++;
                k++;
            }
        }
        token = strtok(NULL, " ");
    }

    // Print the frequency table
    printf("Word frequency:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%s: %d ", data[i], frequency[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free(data);
    free(frequency);

    return 0;
}