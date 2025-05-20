//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void colorGraph(int vertex, int numColors);

bool isSafe(int vertex, int c, int numVertices)
{
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(int numVertices, int numColors, int vertex)
{
    if (vertex == numVertices)
        return true;

    for (int c = 1; c <= numColors; c++) {
        if (isSafe(vertex, c, numVertices)) {
            color[vertex] = c;
            if (graphColoringUtil(numVertices, numColors, vertex + 1) == true)
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

void graphColoring(int numVertices, int numColors)
{
    if (graphColoringUtil(numVertices, numColors, 0) == false) {
        printf("Could not color the graph with %d colors.\n", numColors);
        return;
    }

    for (int i = 0; i < numVertices; i++)
        printf("Vertex %d has color %d.\n", i, color[i]);
}

void initializeGraph(int numVertices)
{
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
        color[i] = 0;
    }
}

void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main(void)
{
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    initializeGraph(numVertices);

    int u, v;
    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int c = 1; c <= numVertices; c++) {
        printf("Trying to color with %d colors...\n", c);
        graphColoring(numVertices, c);
        printf("\n");
    }

    return 0;
}