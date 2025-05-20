//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define MAX_COLORS 10

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->num_vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0; // Initialize adjacency matrix
        }
    }
}

void addEdge(Graph *g, int v1, int v2) {
    g->adj[v1][v2] = 1;
    g->adj[v2][v1] = 1; // Undirected graph
}

void printGraph(const Graph *g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int isSafe(Graph *g, int vertex, int color[], int c) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adj[vertex][i] && color[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

int graphColorUtil(Graph *g, int m, int color[], int vertex) {
    if (vertex == g->num_vertices) {
        return 1; // Successfully colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(g, vertex, color, c)) {
            color[vertex] = c;
            if (graphColorUtil(g, m, color, vertex + 1)) {
                return 1; // Found a solution
            }
            color[vertex] = 0; // Reset
        }
    }
    return 0; // No solution
}

int graphColoring(Graph *g, int m) {
    int color[MAX_VERTICES] = {0}; // Array to store colors
    if (graphColorUtil(g, m, color, 0)) {
        printf("Solution exists: \n");
        for (int i = 0; i < g->num_vertices; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
        return 1;
    }
    printf("No solution exists with %d colors.\n", m);
    return 0;
}

int main() {
    Graph g;
    int vertices, edges, v1, v2, m;
    
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Number of vertices exceeds the maximum limit.\n");
        return -1;
    }

    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: v1 v2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        if (v1 < 0 || v1 >= vertices || v2 < 0 || v2 >= vertices) {
            printf("Invalid vertex number. Please enter again.\n");
            i--; // Decrement index to retry
        } else {
            addEdge(&g, v1, v2);
        }
    }

    printGraph(&g);

    printf("Enter the number of colors to use for coloring: ");
    scanf("%d", &m);

    graphColoring(&g, m);
    return 0;
}