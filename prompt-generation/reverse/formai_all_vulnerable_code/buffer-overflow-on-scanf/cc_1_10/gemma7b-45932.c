//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int n, int k)
{
    int **visited = (int *)malloc(n * sizeof(int));
    int **color = (int *)malloc(n * sizeof(int));
    int i, j, c = 0;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (visited[j] == 0 && graph[i][j] == 1)
            {
                color[i] = j;
                visited[j] = 1;
                c++;
            }
        }
    }

    if (c == n)
    {
        printf("Graph coloring successful!\n");
    }
    else
    {
        printf("Graph coloring unsuccessful!\n");
    }

    free(visited);
    free(color);
}

int main()
{
    int n, k;
    int **graph;

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("Enter the number of colors:");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the adjacency matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, n, k);

    return 0;
}