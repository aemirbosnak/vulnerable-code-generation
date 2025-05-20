//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initializeGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adj[i][j] = 0;
}

void addEdge(Graph *g, int start, int end) {
    g->adj[start][end] = 1;
    g->adj[end][start] = 1; // Since the graph is undirected
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adj[i][j])
                printf("%d ", j);
        }
        printf("\n");
    }
}

int isSafe(int vertex, Graph *g, int colors[], int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[vertex][i] && colors[i] == c) {
            return 0; // Not safe due to adjacent vertex having the same color
        }
    }
    return 1;
}

int graphColoringUtil(Graph *g, int m, int colors[], int vertex) {
    if (vertex == g->numVertices) {
        return 1; // All vertices are colored successfully
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, g, colors, c)) {
            colors[vertex] = c; // Assign color c to vertex

            if (graphColoringUtil(g, m, colors, vertex + 1)) {
                return 1;
            }

            colors[vertex] = 0; // Backtrack
        }
    }
    return 0; // No valid coloring found
}

void graphColoring(Graph *g, int m) {
    int colors[MAX_VERTICES] = {0}; // Array to store color assigned to vertices

    if (graphColoringUtil(g, m, colors, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d --> Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("No solution exists\n");
    }
}

int main() {
    Graph g;
    int vertices, edges, m;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (start end) format:\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(&g, start - 1, end - 1); // Convert to 0-based index
    }

    printGraph(&g);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(&g, m);

    return 0;
}