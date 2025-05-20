//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int color[], int c, int v) {
    for (int i = 0; i < v; i++) {
        if (graph[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int v) {
    if (vertex == v) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c, v)) {
            color[vertex] = c;

            if (graphColoringUtil(graph, m, color, vertex + 1, v)) {
                return true;
            }

            color[vertex] = 0; // Backtrack
        }
    }
    return false;
}

void printSolution(int color[], int v) {
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < v; i++) {
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
    }
}

void graphColoring(Graph *g, int m) {
    int color[MAX_VERTICES];
    for (int i = 0; i < g->vertices; i++) {
        color[i] = 0; // Initialize all vertices to no color
    }

    if (graphColoringUtil(g->adjacencyMatrix, m, color, 0, g->vertices) == false) {
        printf("Solution does not exist\n");
        return;
    }
    printSolution(color, g->vertices);
}

Graph createGraph(int vertices) {
    Graph g;
    g.vertices = vertices;

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g.adjacencyMatrix[i][j] = 0;
        }
    }
    return g;
}

void addEdge(Graph *g, int src, int dest) {
    g->adjacencyMatrix[src][dest] = 1;
    g->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

void takeGraphInput(Graph *g) {
    int edges, src, dest;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(g, src - 1, dest - 1); // Adjust index for 0-based
    }
}

int main() {
    int vertices, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    Graph g = createGraph(vertices);

    takeGraphInput(&g);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(&g, m);
    return 0;
}