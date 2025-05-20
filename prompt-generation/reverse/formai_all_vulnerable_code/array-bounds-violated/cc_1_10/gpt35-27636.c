//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int vertices, edges, colors;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

bool isSafe(int vertex, int c) {
    for (int i = 0; i < vertices; ++i) {
        if (graph[vertex][i] && c == color[i]) {    
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int vertex) {
    if (vertex == vertices) {
        return true;
    }

    for (int i = 1; i <= colors; ++i) {
        if (isSafe(vertex, i)) {
            color[vertex] = i;

            if (graphColoringUtil(vertex + 1)) {
                return true;
            }
            color[vertex] = 0;
        }
    }

    return false;
}

bool graphColoring(int numOfVertices, int numOfEdges, int numOfColors) {
    vertices = numOfVertices;
    edges = numOfEdges;
    colors = numOfColors;

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph[i][j] = 0;
        }
        color[i] = 0;
    }

    printf("Enter %d Edges:\n", edges);
    int u, v;
    for (int i = 0; i < edges; ++i) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    if (graphColoringUtil(0)) {
        printf("\nSolution Exists: ");
        for (int i = 0; i < vertices; ++i) {
            printf("%d ", color[i]);
        }
        return true;
    }
    printf("\nSolution does not exist!");
    return false;
}

int main() {
    int numOfVertices, numOfEdges, numOfColors;
    printf("Enter number of vertices: ");
    scanf("%d", &numOfVertices);
    printf("\nEnter number of edges: ");
    scanf("%d", &numOfEdges);
    printf("\nEnter number of colors: ");
    scanf("%d", &numOfColors);

    graphColoring(numOfVertices, numOfEdges, numOfColors);
    return 0;
}