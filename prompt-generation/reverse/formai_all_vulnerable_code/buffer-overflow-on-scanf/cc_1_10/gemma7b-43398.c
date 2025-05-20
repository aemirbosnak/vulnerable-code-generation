//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, graph[10][10], color[10], visited[10];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            color[i] = 1;
            visited[i] = 1;

            for (j = 0; j < n; j++)
            {
                if (graph[i][j] && !visited[j])
                {
                    color[j] = -color[i];
                    visited[j] = 1;
                }
            }
        }
    }

    printf("The coloring is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", color[i]);
    }

    return 0;
}