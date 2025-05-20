//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int is_safe(int vertex, int color, int num_vertices)
{
    for (int i = 0; i < num_vertices; i++)
    {
        if (graph[vertex][i] && colors[i] == color) // Checking if any adjacent vertex has the same color.
        {
            return 0;
        }
    }
    return 1;
}

int graph_color(int vertex, int num_vertices, int num_colors)
{
    if (vertex == num_vertices) // Checking if all vertices have been assigned colors
    {
        return 1;
    }
    for (int color = 1; color <= num_colors; color++)
    {
        if (is_safe(vertex, color, num_vertices)) // Checking if it is safe to assign color to vertex
        {
            colors[vertex] = color;
            if (graph_color(vertex + 1, num_vertices, num_colors))
            {
                return 1;
            }
            colors[vertex] = 0; // Backtracking step. If assigning the color does not work, backtrack and try with another color.
        }
    }
    return 0;
}

int main()
{
    int num_vertices, num_edges, u, v;

    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d %d", &num_vertices, &num_edges);

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges in the graph: \n");

    for (int i = 0; i < num_edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    int num_colors;

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    if (graph_color(0, num_vertices, num_colors))
    {
        printf("\nGraph can be colored with %d colors as follows:\n", num_colors);
        for (int i = 0; i < num_vertices; i++)
        {
            printf("Vertex %d : Color %d\n", i+1, colors[i]);
        }
    }
    else
    {
        printf("\nGraph cannot be colored with %d colors.\n", num_colors);
    }

    return 0;
}