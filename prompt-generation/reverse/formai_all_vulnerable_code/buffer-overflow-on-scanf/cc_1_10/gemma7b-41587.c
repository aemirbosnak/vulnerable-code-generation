//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = 0;
        }
    }

    int **colors = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        colors[i] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        graph[u][v] = c;
    }

    int chromaticNumber = graphColoring(graph, colors, n, m);

    printf("The chromatic number is: %d", chromaticNumber);

    return 0;
}

int graphColoring(int **graph, int *colors, int n, int m)
{
    int chromaticNumber = 0;

    for (int i = 0; i < n; i++)
    {
        int availableColors = 0;
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] != 0 && colors[j] != 0)
            {
                availableColors++;
            }
        }

        colors[i] = availableColors;
    }

    chromaticNumber = findChromaticNumber(colors, n);

    return chromaticNumber;
}

int findChromaticNumber(int *colors, int n)
{
    int chromaticNumber = 1;

    for (int i = 0; i < n; i++)
    {
        if (colors[i] < chromaticNumber)
        {
            chromaticNumber = colors[i];
        }
    }

    return chromaticNumber;
}