//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int n, int k)
{
    int i, j, color, currentColor = 0, conflict = 0;
    int *visited = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (visited[graph[i][j]] && color != visited[graph[i][j]])
            {
                conflict = 1;
            }
            visited[graph[i][j]] = color;
        }
        color++;
    }

    if (!conflict)
    {
        printf("No conflict found.\n");
    }
    else
    {
        printf("Conflict found.\n");
    }

    free(visited);
}

int main()
{
    int n, k, i, j;
    int **graph;

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("Enter the number of edges:");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the edges:");
    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &graph[0][i], &graph[1][i]);
    }

    graphColoring(graph, n, k);

    return 0;
}