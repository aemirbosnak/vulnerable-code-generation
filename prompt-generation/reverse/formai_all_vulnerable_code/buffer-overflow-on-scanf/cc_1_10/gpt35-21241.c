//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices, num_colors;

bool isSafe(int v, int color, int colors[])
{
    for (int i = 0; i < num_vertices; i++)
        if (graph[v][i] && color == colors[i])
            return false;

    return true;
}

bool graphColoringHelper(int colors[], int v)
{
    if (v == num_vertices)
        return true;

    for (int c = 1; c <= num_colors; c++)
    {
        if (isSafe(v, c, colors))
        {
            colors[v] = c;

            if (graphColoringHelper(colors, v+1))
                return true;

            colors[v] = 0;
        }
    }

    return false;
}

bool graphColoring()
{
    int colors[MAX_VERTICES] = {0};

    if (!graphColoringHelper(colors, 0))
        return false;

    printf("Assigned colors:\n");
    for (int i = 0; i < num_vertices; i++)
        printf("%d ", colors[i]);

    return true;
}

int main()
{
    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);

    printf("Enter the number of colors to use: ");
    scanf("%d", &num_colors);

    printf("Enter the adjacency matrix rowwise:\n");
    for (int i = 0; i < num_vertices; i++)
        for (int j = 0; j < num_vertices; j++)
            scanf("%d", &graph[i][j]);

    if (!graphColoring())
        printf("Failed to color the graph with %d colors.\n", num_colors);

    return 0;
}