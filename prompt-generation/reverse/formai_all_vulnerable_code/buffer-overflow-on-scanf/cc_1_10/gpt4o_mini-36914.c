//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int numVertices;
    int **adjMatrix;
    int *colors;
} Graph;

Graph* createGraph(int vertices) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertices = vertices;

    // Allocate memory for adjacency matrix
    g->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        g->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = (i == j) ? 0 : 0; // No edges initially
        }
    }
    
    g->colors = (int *)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        g->colors[i] = -1; // No color assigned
    }
    
    return g;
}

void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // Undirected graph
}

int isSafe(Graph *g, int v, int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[v][i] == 1 && g->colors[i] == c) {
            return FALSE;
        }
    }
    return TRUE;
}

int graphColoringUtil(Graph *g, int m, int v) {
    // All vertices are assigned a color
    if (v == g->numVertices) {
        return TRUE;
    }

    // Try different colors for vertex v
    for (int c = 0; c < m; c++) {
        if (isSafe(g, v, c)) {
            g->colors[v] = c; // Assign color c to vertex v
            
            // Recur to assign colors to the rest
            if (graphColoringUtil(g, m, v + 1)) {
                return TRUE;
            }

            // Backtrack
            g->colors[v] = -1; // Remove color
        }
    }
    return FALSE; // If no color can be assigned
}

void graphColoring(Graph *g, int m) {
    if (graphColoringUtil(g, m, 0)) {
        printf("Solution found:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, g->colors[i]);
        }
    } else {
        printf("No solution exists for the given constraints.\n");
    }
}

void freeGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g->colors);
    free(g);
}

int main() {
    int vertices, edges, m;

    // Input the number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    Graph *g = createGraph(vertices);

    // Input edges
    printf("Enter the edges (source and destination pairs):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }

    // Input number of colors
    printf("Enter the number of colors to use: ");
    scanf("%d", &m);

    // Perform graph coloring
    graphColoring(g, m);

    // Free allocated memory
    freeGraph(g);
    
    return 0;
}