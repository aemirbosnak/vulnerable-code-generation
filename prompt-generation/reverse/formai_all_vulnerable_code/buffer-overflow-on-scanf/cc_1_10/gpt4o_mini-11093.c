//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices; // number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
} Graph;

void initializeGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0; // no edges yet
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->graph[src][dest] = 1; // directed graph
    g->graph[dest][src] = 1; // undirected graph
}

void printSolution(int color[], int vertices) {
    printf("Solution: \n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
    }
}

bool isSafe(int v, Graph* g, int color[], int c) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph* g, int m, int color[], int v) {
    // Base case: All vertices colored
    if (v == g->vertices) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c)) {
            color[v] = c; // Assign color

            if (graphColoringUtil(g, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

bool graphColoring(Graph* g, int m) {
    int* color = (int*)malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++) {
        color[i] = 0; // Initialize all vertices to no color
    }

    if (!graphColoringUtil(g, m, color, 0)) {
        printf("No solution exists for %d colors.\n", m);
        free(color);
        return false;
    }

    printSolution(color, g->vertices);
    free(color);
    return true;
}

int main() {
    int vertices, edges, colorCount;
    Graph g;

    printf("Welcome to the Futuristic Graph Coloring Console!\n");
    printf("Enter number of vertices (up to %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    
    initializeGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(&g, u - 1, v - 1); // Adjust for 0-based index
    }

    printf("Enter number of colors to use: ");
    scanf("%d", &colorCount);

    if (!graphColoring(&g, colorCount)) {
        printf("Graph coloring failed.\n");
    }

    printf("Thank you for using the Futuristic Graph Coloring Console!\n");
    return 0;
}