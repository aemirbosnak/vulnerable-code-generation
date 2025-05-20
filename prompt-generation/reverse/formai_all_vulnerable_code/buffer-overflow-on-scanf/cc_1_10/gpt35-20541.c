//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int vertices;
int colors[MAX_VERTICES];

int create_graph();
int graph_color(int vertex);
int is_safe(int vertex, int color);

int main()
{
    int i;
    int color;
    printf("Graph Color Problem\n\n");
    
    if (!create_graph())
    {
        printf("Error creating graph.\n");
        return -1;
    }
    
    for (i = 0; i < vertices; i++)
        colors[i] = 0;
    
    if (graph_color(0))
    {
        printf("Solution found:\n");
        for (i = 0; i < vertices; i++)
        {
            color = colors[i];
            printf("Vertex %d: Color %d\n", i, color);
        }
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}

int create_graph()
{
    int i, j, edges;
    int start, end;

    printf("Enter the total number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter the total number of edges: ");
    scanf("%d", &edges);
    
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    
    printf("Enter the edges (format: start end): (-1 -1 to stop)\n");
    scanf("%d %d", &start, &end);
    
    while (start != -1 && end != -1)
    {
        if (start >= vertices || end >= vertices || start < 0 || end < 0)
        {
            printf("Invalid edge!\n");
        }
        else
        {
            adj_matrix[start][end] = 1;
            adj_matrix[end][start] = 1;
        }
        scanf("%d %d", &start, &end);
    }

    return 1;
}

int graph_color(int vertex)
{
    int color;
    int i;
    if (vertex == vertices)
        return 1;
    
    for (color = 1; color <= MAX_COLORS; color++)
    {
        if (is_safe(vertex, color))
        {
            colors[vertex] = color;
            if (graph_color(vertex+1))
                return 1;
            colors[vertex] = 0;
        }
    }
    
    return 0;
}

int is_safe(int vertex, int color)
{
    int i;
    for (i = 0; i < vertices; i++)
    {
        if (adj_matrix[vertex][i] && color == colors[i])
            return 0;
    }

    return 1;
}