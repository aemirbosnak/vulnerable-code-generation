//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct {
    int vertices[MAX_VERTICES];
    int numVertices;
} Graph;

// Function prototypes
void initializeGraph(Graph* g, int vertices);
void addEdge(Graph* g, int src, int dest);
void printGraph(const Graph* g);
bool isSafe(const Graph* g, int vertex, int color, int colors[]);
bool graphColoringUtil(const Graph* g, int m, int colors[], int vertex);
void graphColoring(Graph* g, int m);

int main() {
    Graph graph;
    int numVertices, m;

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);
    
    if (numVertices > MAX_VERTICES || numVertices <= 0) {
        fprintf(stderr, "Invalid number of vertices!\n");
        return 1;
    }

    initializeGraph(&graph, numVertices);

    int edges;
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest format):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }
    
    printf("Adjacency List Representation of the Graph:\n");
    printGraph(&graph);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(&graph, m);
    
    return 0;
}

void initializeGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->vertices[i] = -1; // Initialize all vertices with no color
    }
}

void addEdge(Graph* g, int src, int dest) {
    // Logic for storing the edges in some form can be added
    // For simplicity, we can ignore the implementation here.
    // Note: This implementation assumes a simple undirected graph.
}

void printGraph(const Graph* g) {
    // Print adjacency list representation (this would require storage for edges)
    // For simplicity, assume a static example since we neglected edges logic
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertex %d: [Add adjacency details here later]\n", i);
    }
}

bool isSafe(const Graph* g, int vertex, int color, int colors[]) {
    for (int i = 0; i < g->numVertices; i++) {
        // Assuming an edge exists between vertex and i (for example)
        if (/* Check if there's an edge between vertex and i */ false) {
            if (colors[i] == color) {
                return false;
            }
        }
    }
    return true;
}

bool graphColoringUtil(const Graph* g, int m, int colors[], int vertex) {
    // Base case: all vertices are assigned a color
    if (vertex == g->numVertices) {
        return true;
    }
    
    for (int color = 1; color <= m; color++) {
        if (isSafe(g, vertex, color, colors)) {
            colors[vertex] = color;

            if (graphColoringUtil(g, m, colors, vertex + 1)) {
                return true;
            }
            
            colors[vertex] = 0; // Backtrack
        }
    }
    return false;
}

void graphColoring(Graph* g, int m) {
    int* colors = (int *)malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        colors[i] = 0; // Initialize colors
    }
    
    if (graphColoringUtil(g, m, colors, 0)) {
        printf("Solution Exists:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, colors[i]);
        }
    } else {
        printf("No Solution Exists!\n");
    }
    
    free(colors);
}