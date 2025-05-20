//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10

int graph[MAX_VERTEX][MAX_VERTEX] = {0};
int color[MAX_VERTEX] = {0};
int num_vertex = 0, num_color = 0;

int is_safe_to_color(int vertex_index, int color_index)
{
    for (int i = 0; i < num_vertex; i++)
    {
        if (graph[vertex_index][i] && color[i] == color_index)
        {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int vertex_index)
{
    if (vertex_index == num_vertex)
    {
        return 1;
    }

    for (int i = 1; i <= num_color; i++)
    {
        if (is_safe_to_color(vertex_index, i))
        {
            color[vertex_index] = i;
            if (graph_coloring(vertex_index + 1))
            {
                return 1;
            }
            color[vertex_index] = 0;
        }
    }

    return 0;
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertex);

    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < num_vertex; i++)
    {
        for (int j = 0; j < num_vertex; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors available: ");
    scanf("%d", &num_color);

    if (graph_coloring(0))
    {
        printf("The colors assigned are:\n");
        for (int i = 0; i < num_vertex; i++)
        {
            printf("%d ", color[i]);
        }
    }
    else
    {
        printf("It is not possible to color the graph with the given number of colors.\n");
    }

    return 0;
}