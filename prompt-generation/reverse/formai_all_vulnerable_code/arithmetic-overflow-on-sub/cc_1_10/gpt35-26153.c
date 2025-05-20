//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// function to print the solution
void printSolution(int color[], int V);

// function to check if coloring the vertex with color c
// is safe or not
int isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// function to solve graph coloring problem
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V)
{
    // If all vertices are assigned a color, return true
    if (v == V)
        return 1;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++)
    {
        // Check if assignment of color c to v is possible
        if (isSafe(v, graph, color, c, V))
        {
            color[v] = c;

            // recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, V))
                return 1;

            // If assigning color c doesn't lead to a solution
            color[v] = 0;
        }
    }
    return 0;
}

// function to solve graph coloring problem using backtracking
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V)
{
    int color[MAX_VERTICES];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call the recursive utility function
    if (!graphColoringUtil(graph, m, color, 0, V))
        printf("Solution does not exist\n");

    // Print the solution
    printSolution(color, V);
}

// function to print the solution
void printSolution(int color[], int V)
{
    printf("Solution Exists: Following are the assigned colors on the vertices:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
}

// main function
int main()
{
    int V, E, color[MAX_VERTICES], m;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    // initialize the graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    // input the edges of the graph
    printf("Enter the edges of the graph:\n");
    int u, v;
    for (int i = 0; i < E; i++)
    {
        printf("Enter edge %d: ", i + 1);
        scanf("%d%d", &u, &v);
        graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1;
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // solve graph coloring problem
    graphColoring(graph, m, V);

    return 0;
}