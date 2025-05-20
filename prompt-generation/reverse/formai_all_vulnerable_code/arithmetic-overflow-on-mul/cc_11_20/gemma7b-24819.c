//Gemma-7B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int main()
{
    int i, j, k, l, n, m;
    char **arr = NULL;
    char **str = NULL;
    int **freq = NULL;
    double **dist = NULL;
    FILE *fp;

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // Read the number of documents and words
    fscanf(fp, "%d %d", &n, &m);

    // Allocate memory for the array
    arr = (char **)malloc(n * MAX_SIZE * sizeof(char *));
    str = (char **)malloc(m * MAX_SIZE * sizeof(char *));
    freq = (int *)malloc(n * MAX_SIZE * sizeof(int));
    dist = (double *)malloc(n * MAX_SIZE * sizeof(double));

    // Read the documents and words
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
        fscanf(fp, "%[^\n]%*c", arr[i]);
    }

    for (j = 0; j < m; j++)
    {
        str[j] = (char *)malloc(MAX_SIZE * sizeof(char));
        fscanf(fp, "%s", str[j]);
    }

    // Calculate the frequency of each word
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            int flag = 0;
            for (k = 0; k < MAX_SIZE; k++)
            {
                if (strcmp(str[j], arr[i][k]) == 0)
                {
                    freq[i]++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                freq[i] = 1;
            }
        }
    }

    // Calculate the distance between documents
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = 0;
            for (k = 0; k < m; k++)
            {
                dist[i][j] += abs(freq[i] - freq[j]) * 0.01;
            }
        }
    }

    // Print the distance matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%f ", dist[i][j]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}