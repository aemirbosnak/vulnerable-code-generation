//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // Maximum number of vertices

// Function prototypes
void init_graph(int);
void add_edge(int, int);
void graph_coloring(int);

// Graph variables
int graph[MAX_VERTICES][MAX_VERTICES];
int vertices[MAX_VERTICES], colors[MAX_VERTICES];
int num_vertices, num_colors = 0;

int main()
{
    int x, y;

    // Welcome message
    printf("\n=== MIND-BENDING GRAPH COLORING PROBLEM EXAMPLE ===\n");

    // Prompt user to enter the number of vertices
    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    // Clear the graph
    init_graph(num_vertices);

    // Prompt user to enter each edge
    printf("\nEnter each edge in the format 'x y' (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d %d", &x, &y);
        if (x == -1 || y == -1)
            break;
        add_edge(x, y);
    }

    // Perform graph coloring
    graph_coloring(num_vertices);

    // Print the colors assigned to each vertex
    printf("\nColors assigned to each vertex:");
    for (int i = 0; i < num_vertices; i++)
    {
        printf("\nVertex %d: Color %d", i, colors[i]);
    }

    return 0;
}

// Initialize graph
void init_graph(int num_vertices)
{
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
}

// Add edge to graph
void add_edge(int x, int y)
{
    graph[x][y] = 1;
    graph[y][x] = 1;
}

// Perform graph coloring
void graph_coloring(int num_vertices)
{
    int i, j, k;

    // Assign the first color to the first vertex
    colors[0] = 0;

    // Assign colors to remaining vertices
    for (i = 1; i < num_vertices; i++)
    {
        // Reset the vertices array to all uncolored
        for (j = 0; j < num_vertices; j++)
        {
            vertices[j] = 0;
        }

        // Check the colors of adjacent vertices and mark them as unavailable
        for (j = 0; j < num_vertices; j++)
        {
            if (graph[i][j])
            {
                int color = colors[j];
                vertices[color] = 1;
            }
        }

        // Find the first available color
        for (k = 0; k < num_vertices; k++)
        {
            if (vertices[k] == 0)
            {
                colors[i] = k;
                break;
            }
        }

        // Update the maximum number of colors used
        if (colors[i] > num_colors)
        {
            num_colors = colors[i];
        }
    }
}