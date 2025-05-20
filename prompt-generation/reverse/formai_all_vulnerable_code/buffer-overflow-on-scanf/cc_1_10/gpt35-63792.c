//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

//color codes for graph coloring
#define WHITE 0
#define GRAY 1
#define BLACK 2

//function to print the graph color
void printGraphColor(int color[], int V)
{
    printf("\nGraph coloring:\n");
    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d: color %d\n", i, color[i]);
    }
}

//function to check if the current color is valid for the given vertex
int isSafe(int vertex, int graph[][MAX_VERTICES], int color[], int V, int current_color)
{
    //check if adjacent vertices have the same color
    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] && current_color == color[i])
            return 0;
    }
    return 1;
}

//function to perform graph coloring using backtracking
int graphColoringUtil(int graph[][MAX_VERTICES], int color[], int vertex, int V, int num_colors)
{
    // all vertices colored, return true
    if (vertex == V)
    {
        return 1;
    }

    // consider next vertex
    for (int i = 1; i <= num_colors; i++)
    {
        if (isSafe(vertex, graph, color, V, i))
        {
            color[vertex] = i;

            //recursively color rest of the vertices
            if (graphColoringUtil(graph, color, vertex + 1, V, num_colors))
            {
                return 1;
            }

            //if coloring not possible, backtrack
            color[vertex] = 0;
        }
    }

    return 0;
}

int main()
{
    int V, num_colors;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors to be used: ");
    scanf("%d", &num_colors);

    int color[MAX_VERTICES];

    for (int i = 0; i < V; i++)
    {
        color[i] = 0; //initialize all colors to 0
    }

    if (graphColoringUtil(graph, color, 0, V, num_colors))
    {
        printGraphColor(color, V);
    }
    else
    {
        printf("\nColoring not possible!\n");
    }

    return 0;
}