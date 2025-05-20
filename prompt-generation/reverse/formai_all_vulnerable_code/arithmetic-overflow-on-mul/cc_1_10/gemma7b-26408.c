//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, n, m;
    char **words;
    char **lines;

    printf("Enter the number of lines: ");
    scanf("%d", &n);

    lines = malloc(n * MAX_BUFFER_SIZE);
    words = malloc(n * MAX_BUFFER_SIZE);

    for (i = 0; i < n; i++)
    {
        printf("Enter the line: ");
        getline(buffer, MAX_BUFFER_SIZE, stdin);
        lines[i] = strdup(buffer);
    }

    printf("Enter the number of words to summarize: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
    {
        words[i] = malloc(MAX_BUFFER_SIZE);
    }

    for (i = 0; i < n; i++)
    {
        k = 0;
        for (j = 0; lines[i][j] != '\0'; j++)
        {
            if (lines[i][j] >= 'a' && lines[i][j] <= 'z')
            {
                words[i][k++] = lines[i][j];
            }
        }
        words[i][k] = '\0';
    }

    for (i = 0; i < n; i++)
    {
        printf("Summary of line %d: %s\n", i + 1, words[i]);
    }

    free(lines);
    free(words);

    return 0;
}