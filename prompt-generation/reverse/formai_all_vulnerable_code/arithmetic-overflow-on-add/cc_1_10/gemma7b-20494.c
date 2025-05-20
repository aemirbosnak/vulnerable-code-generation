//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void graphColoring(int **graph, int n, int currentColor, int **visited, int **colors)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0 && graph[currentColor][i] == 1)
        {
            visited[i] = 1;
            colors[i] = currentColor;

            graphColoring(graph, n, (currentColor + 1) % n, visited, colors);

            visited[i] = 0;
        }
    }
}

int main()
{
    int n, m, i, j, currentColor = 0, **graph, **visited, **colors;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    visited = (int *)malloc(n * sizeof(int));
    colors = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        visited[i] = 0;
        colors[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        scanf("Enter the edge (%d, %d): ", &i, &j);
        graph[i][j] = 1;
    }

    graphColoring(graph, n, currentColor, visited, colors);

    printf("The optimal coloring is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", colors[i]);
    }

    return 0;
}