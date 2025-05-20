//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

int graph[MAX_Vertices][MAX_Vertices];
int color[MAX_Vertices];
int available[MAX_Vertices];

void dfs(int currentVertex)
{
    for (int i = 0; i < MAX_Vertices; i++)
    {
        if (graph[currentVertex][i] && !available[i])
        {
            available[i] = 1;
            color[i] = color[currentVertex];
            dfs(i);
        }
    }
}

int main()
{
    int i, j, v, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < e; i++)
    {
        int u, v;

        printf("Enter the two vertices connected by the edge: ");
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
    }

    for (i = 0; i < v; i++)
    {
        available[i] = 1;
    }

    dfs(0);

    for (i = 0; i < v; i++)
    {
        printf("Vertex %d has color %d\n", i, color[i]);
    }

    return 0;
}