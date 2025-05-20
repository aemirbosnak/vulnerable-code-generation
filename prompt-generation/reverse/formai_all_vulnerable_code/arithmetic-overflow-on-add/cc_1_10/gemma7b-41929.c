//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                color = colors[graph[i][j]] == -1 ? 0 : colors[graph[i][j]] + 1;
                colors[j] = color;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d\n", i + 1, colors[i]);
    }
}

int main()
{
    int n, k, i, j;
    int **graph;

    printf("Welcome, dear Watson, to the case of the Graph Coloring.\n");

    printf("Please provide the number of vertices: ");
    scanf("%d", &n);

    printf("Now, tell me the number of edges: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Alright, describe the edges: ");
    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &j, &i);
        graph[j][i] = 1;
    }

    graph_coloring(graph, n, k);

    return 0;
}