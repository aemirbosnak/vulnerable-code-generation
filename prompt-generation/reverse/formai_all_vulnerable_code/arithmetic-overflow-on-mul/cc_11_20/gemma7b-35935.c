//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int n, i, j, k, l, m, t, x, y, z;
    int **graph = NULL;
    char **map = NULL;

    scanf("Enter the number of nodes: ", &n);
    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    map = (char *)malloc(n * n * sizeof(char));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            map[i * n + j] = 'O';

    scanf("Enter the number of edges: ", &t);
    for (i = 0; i < t; i++)
    {
        scanf("Enter the source and destination nodes: ", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                map[i * n + j] = 'C';
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c ", map[i * n + j]);
        }
        printf("\n");
    }

    free(graph);
    free(map);

    return 0;
}