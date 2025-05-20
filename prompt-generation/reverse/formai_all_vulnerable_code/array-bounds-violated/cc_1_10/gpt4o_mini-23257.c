//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int numVertices;

void initializeGraph() {
    for (int i = 0; i < numVertices; i++) {
        colors[i] = -1; // Assign no color initially
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0; // Initialize edges to 0
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // Since the graph is undirected
}

int isSafe(int vertex, int color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && colors[i] == color) {
            return 0; // Conflict found
        }
    }
    return 1; // Safe to color
}

int graphColorUtil(int vertex, int m) {
    if (vertex == numVertices) {
        return 1; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, c)) {
            colors[vertex] = c; // Assign color c to vertex

            if (graphColorUtil(vertex + 1, m)) {
                return 1; // Recursive call successful
            }

            colors[vertex] = -1; // Backtrack
        }
    }
    return 0; // No solution found
}

int graphColoring(int m) {
    if (graphColorUtil(0, m)) {
        return 1; // Coloring successful
    }
    return 0; // No valid coloring found
}

void printColors() {
    printf("Vertex Colors:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

int main() {
    int edges, u, v, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initializeGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter the number of colors to use: ");
    scanf("%d", &m);

    if (graphColoring(m)) {
        printColors();
    } else {
        printf("No solution exists for the given graph with %d colors.\n", m);
    }

    return 0;
}