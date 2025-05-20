//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define INFINITY 9999

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numberOfVertices;
} Graph;

void initializeGraph(Graph *g, int numVertices) {
    g->numberOfVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adjacencyMatrix[src][dest] = 1;
    g->adjacencyMatrix[dest][src] = 1; // For undirected graph
}

int isSafe(Graph *g, int vertex, int color[], int c) {
    for (int i = 0; i < g->numberOfVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] && color[i] == c) {
            return 0; // Not safe to color this vertex with color c
        }
    }
    return 1; // Safe to color this vertex
}

int graphColoringUtil(Graph *g, int m, int color[], int vertex) {
    if (vertex == g->numberOfVertices) {
        return 1; // All vertices processed
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(g, vertex, color, c)) {
            color[vertex] = c; // Assign color c to vertex

            if (graphColoringUtil(g, m, color, vertex + 1)) {
                return 1;
            }

            color[vertex] = 0; // Remove color (backtrack)
        }
    }
    return 0; // No colors can be assigned
}

void graphColoring(Graph *g, int m) {
    int *color = (int *)malloc(g->numberOfVertices * sizeof(int));

    for (int i = 0; i < g->numberOfVertices; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(g, m, color, 0) == 0) {
        printf("Solution does not exist\n");
        return;
    }

    printf("Solution Exists! Following are the assigned colors:\n");
    for (int i = 0; i < g->numberOfVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
    }

    free(color);
}

int main() {
    Graph g;
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    initializeGraph(&g, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (src dest) format:\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&g, src - 1, dest - 1); // Adjusting for 0-based indexing
    }

    int m; // Number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(&g, m);
    return 0;
}