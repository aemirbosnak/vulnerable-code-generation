//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], color[MAX], V;

int isSafe(int vertex, int c)
{
    int i;
    for (i = 0; i < V; i++)
    {
        if (graph[vertex][i] && c == color[i])
            return 0;
    }
    return 1;
}

int graphColor(int vertex, int C)
{
    int colorIndex;
    if (vertex == V)
        return 1;
    for (colorIndex = 1; colorIndex <= C; colorIndex++)
    {
        if (isSafe(vertex, colorIndex))
        {
            color[vertex] = colorIndex;
            if (graphColor(vertex + 1, C) == 1)
                return 1;
            color[vertex] = 0;
        }
    }
    return 0;
}

int main()
{
    int i, j, C;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("Enter 1 if edge exists from vertex %d to vertex %d, otherwise enter 0: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d", &C);
    if (graphColor(0, C) == 1)
    {
        printf("Possible to color the graph using %d colors with the below coloring:\n", C);
        for (i = 0; i < V; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    }
    else
        printf("Not possible to color the graph using %d colors\n", C);
    return 0;
}