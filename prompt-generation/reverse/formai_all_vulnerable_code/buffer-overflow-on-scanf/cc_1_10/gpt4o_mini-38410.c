//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initializeGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int start, int end) {
    g->adjacencyMatrix[start][end] = 1;
    g->adjacencyMatrix[end][start] = 1; // undirected graph
}

void printGraph(const Graph* g) {
    printf("Graph Adjacency Matrix:\n");
    for(int i = 0; i < g->numVertices; i++) {
        for(int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int vertex, bool* colorUsed, Graph* g, int v) {
    for(int i = 0; i < g->numVertices; i++) {
        if(g->adjacencyMatrix[vertex][i] == 1 && colorUsed[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph* g, int m, int* colors, int vertex) {
    if(vertex == g->numVertices) {
        return true; // All vertices colored
    }

    for(int c = 1; c <= m; c++) {
        colors[vertex] = c;
        if(isSafe(vertex, colors, g, g->numVertices)) {
            if(graphColoringUtil(g, m, colors, vertex + 1)) {
                return true;
            }
            colors[vertex] = 0; // Backtrack
        }
    }
    return false; // No color can be assigned
}

void graphColoring(Graph* g, int m) {
    int* colors = (int*)malloc(g->numVertices * sizeof(int));
    for(int i = 0; i < g->numVertices; i++) {
        colors[i] = 0; // Initial color assignment
    }

    if(graphColoringUtil(g, m, colors, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    printf("Solution exists: Following are the assigned colors:\n");
    for(int i = 0; i < g->numVertices; i++) {
        printf("Vertex %d => Color %d\n", i, colors[i]);
    }

    free(colors);
}

int main() {
    Graph g;
    int vertices, edges, start, end, m;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);
        if(start >= 0 && start < vertices && end >= 0 && end < vertices) {
            addEdge(&g, start, end);
        } else {
            printf("Invalid edge input! Please try again.\n");
            i--; // repeat the same iteration
        }
    }

    printGraph(&g);

    printf("Enter the number of colors to use: ");
    scanf("%d", &m);
    graphColoring(&g, m);

    return 0;
}