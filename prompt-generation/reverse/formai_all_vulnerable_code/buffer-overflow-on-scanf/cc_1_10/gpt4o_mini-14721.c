//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct {
    int vertices[MAX_VERTICES];
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initializeGraph(Graph *g, int vertices) {
    g->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        g->vertices[i] = i;
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0; // No edges yet
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // Undirected graph
}

void printGraph(Graph g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            printf("%d ", g.adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int isSafe(Graph g, int vertex, int color[], int col) {
    for (int i = 0; i < g.numVertices; i++) {
        if (g.adjMatrix[vertex][i] == 1 && color[i] == col) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

int graphColoringUtil(Graph g, int m, int color[], int vertex) {
    if (vertex == g.numVertices) {
        return 1; // All vertices colored
    }

    for (int col = 1; col <= m; col++) {
        if (isSafe(g, vertex, color, col)) {
            color[vertex] = col; // Assign color

            if (graphColoringUtil(g, m, color, vertex + 1)) {
                return 1;
            }

            color[vertex] = 0; // Backtrack
        }
    }
    return 0; // No solution found
}

void graphColoring(Graph g, int m) {
    int *color = (int *)malloc(g.numVertices * sizeof(int));
    for (int i = 0; i < g.numVertices; i++) {
        color[i] = 0; // Initialize color
    }

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < g.numVertices; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists for %d colors.\n", m);
    }

    free(color);
}

int main() {
    Graph g;
    int vertices, edges, m;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    if (vertices > MAX_VERTICES || vertices <= 0) {
        fprintf(stderr, "Invalid number of vertices.\n");
        return EXIT_FAILURE;
    }

    initializeGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            fprintf(stderr, "Invalid edge input.\n");
            return EXIT_FAILURE;
        }
        addEdge(&g, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);
    if (m <= 0) {
        fprintf(stderr, "Invalid number of colors.\n");
        return EXIT_FAILURE;
    }

    printGraph(g);
    graphColoring(g, m);

    return EXIT_SUCCESS;
}