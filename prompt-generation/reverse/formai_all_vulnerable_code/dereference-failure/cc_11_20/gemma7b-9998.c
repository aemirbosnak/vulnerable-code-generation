//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_COLS 20

int main()
{
    char **data = NULL;
    int numLines = 0, numCols = 0;

    // Allocate memory for the data
    data = malloc(MAX_LINES * sizeof(char *));
    for (int i = 0; i < MAX_LINES; i++)
    {
        data[i] = malloc(MAX_COLS * sizeof(char));
    }

    // Read the CSV file
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get the number of lines and columns
    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL)
    {
        numLines++;
    }
    rewind(fp);

    char **cols = NULL;
    cols = malloc(numLines * sizeof(char *));
    for (int i = 0; i < numLines; i++)
    {
        cols[i] = malloc(MAX_COLS * sizeof(char));
    }

    int i = 0;
    while (fgets(line, MAX_LINES, fp) != NULL)
    {
        char *p = line;
        char **q = cols[i];
        while (*p)
        {
            *q++ = strchr(p, ',') ? strchr(p, ',') - p : NULL;
            p = strchr(p, ',') ? strchr(p, ',') + 1 : NULL;
        }
        i++;
    }

    // Print the data
    for (int i = 0; i < numLines; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_LINES; i++)
    {
        free(data[i]);
    }
    free(data);

    for (int i = 0; i < numLines; i++)
    {
        free(cols[i]);
    }
    free(cols);

    fclose(fp);

    return 0;
}