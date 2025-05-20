//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define NO_COLOR -1

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initializeGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;  // Because the graph is undirected
}

void printGraph(Graph *g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int isSafe(Graph *g, int v, int color[], int c) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[v][i] == 1 && color[i] == c) {
            return 0; // Not safe to color
        }
    }
    return 1; // Safe to color
}

int graphColoringUtil(Graph *g, int m, int color[], int v) {
    if (v == g->numVertices) {
        return 1; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(g, v, color, c)) {
            color[v] = c; // Assign color c to vertex v

            if (graphColoringUtil(g, m, color, v + 1)) {
                return 1; // If coloring is successful
            }

            color[v] = NO_COLOR; // Backtrack
        }
    }
    return 0; // No solution
}

void graphColoring(Graph *g, int m) {
    int color[MAX_VERTICES];
    for (int i = 0; i < g->numVertices; i++) {
        color[i] = NO_COLOR; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Solution exists: Colors assigned are:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists for the given graph with %d colors.\n", m);
    }
}

int main() {
    Graph g;
    int vertices, edges, src, dest, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printGraph(&g);
    graphColoring(&g, m);

    return 0;
}