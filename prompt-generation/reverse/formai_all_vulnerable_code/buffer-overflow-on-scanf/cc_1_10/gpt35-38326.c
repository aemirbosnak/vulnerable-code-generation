//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // Maximum number of vertices
#define TRUE 1
#define FALSE 0

int graph[MAX_VERTICES][MAX_VERTICES]; // Graph adjacency matrix
int numVertices; // Number of vertices in the graph
int colors[MAX_VERTICES]; // Array to store colors of each vertex

// Returns true if adjacent vertices have different colors, false otherwise
int isSafe(int vertex, int color)
{
    for (int i = 0; i < numVertices; i++)
    {
        if (graph[vertex][i] && colors[i] == color)
        {
            return FALSE;
        }
    }
    return TRUE;
}

// Recursive function to color vertices
int colorGraph(int vertex)
{
    if (vertex == numVertices) // All vertices have been colored
    {
        return TRUE;
    }

    for (int color = 1; color <= numVertices; color++)
    {
        if (isSafe(vertex, color))
        {
            colors[vertex] = color;

            if (colorGraph(vertex + 1)) // Recursively color next vertex
            {
                return TRUE;
            }

            colors[vertex] = 0; // Backtrack and reset color
        }
    }

    return FALSE; // No valid color found for vertex
}

int main()
{
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix of the graph: \n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    if (colorGraph(0)) // Color the vertices starting from 1st vertex
    {
        printf("The graph can be colored with %d colors as follows:\n", numVertices);

        for (int i = 0; i < numVertices; i++)
        {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }
    }
    else
    {
        printf("The graph cannot be colored with %d colors.", numVertices);
    }

    return 0;
}