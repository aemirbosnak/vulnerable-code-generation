//Gemma-7B DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char **data = NULL;
    int size = 0;
    int i, j, k;

    // Allocate memory for the data
    data = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Read data from the file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        perror("Error reading file");
        exit(1);
    }
    size = fread(data, MAX_SIZE * MAX_SIZE, 1, fp);
    fclose(fp);

    // Preprocess the data
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            data[i][j] = toupper(data[i][j]) - 64;
        }
    }

    // Find the frequent items
    int **freq = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        freq[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (data[i][j] != 0)
            {
                freq[data[i][j]]++;
            }
        }
    }

    // Print the frequent items
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (freq[i][j] > 0)
            {
                printf("%c: %d\n", i + 1, freq[i][j]);
            }
        }
    }

    // Free memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(freq[i]);
    }
    free(freq);

    return 0;
}