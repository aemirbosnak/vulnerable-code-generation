//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// Structure to represent a graph
typedef struct {
    int numVertices;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* g, int vertex1, int vertex2);
bool isSafe(Graph* g, int vertex, int color[], int c);
bool graphColorUtil(Graph* g, int m, int color[], int vertex);
bool graphColoring(Graph* g, int m);
void freeGraph(Graph* g);
void printGraph(Graph* g);

int main() {
    int vertices, edges, m;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    if (vertices > MAX_VERTICES) {
        fprintf(stderr, "Exceeds maximum allowed vertices.\n");
        return 1;
    }

    Graph* g = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (vertex1 vertex2 format):\n");
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        addEdge(g, v1, v2);
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    if (graphColoring(g, m)) {
        printf("Graph can be colored with %d colors.\n", m);
    } else {
        printf("Graph cannot be colored with %d colors.\n", m);
    }

    freeGraph(g);
    return 0;
}

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;
    
    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = false;
        }
    }

    return g;
}

void addEdge(Graph* g, int vertex1, int vertex2) {
    g->adj[vertex1][vertex2] = true;
    g->adj[vertex2][vertex1] = true; // since the graph is undirected
}

bool isSafe(Graph* g, int vertex, int color[], int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColorUtil(Graph* g, int m, int color[], int vertex) {
    if (vertex == g->numVertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(g, vertex, color, c)) {
            color[vertex] = c;
            if (graphColorUtil(g, m, color, vertex + 1)) {
                return true;
            }
            color[vertex] = 0; // Backtrack
        }
    }
    return false;
}

bool graphColoring(Graph* g, int m) {
    int* color = (int*)malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        color[i] = 0; // Initialize all colors to 0 (no color)
    }

    bool result = graphColorUtil(g, m, color, 0);
    free(color);
    return result;
}

void freeGraph(Graph* g) {
    free(g);
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adj[i][j]) {
                printf("%d -- %d\n", i, j);
            }
        }
    }
}