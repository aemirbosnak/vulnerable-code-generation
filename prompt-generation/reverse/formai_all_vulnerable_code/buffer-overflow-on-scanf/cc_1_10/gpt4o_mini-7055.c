//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define TRUE 1
#define FALSE 0

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int start, int end) {
    if (start >= 0 && start < g->numVertices && end >= 0 && end < g->numVertices) {
        g->adjMatrix[start][end] = 1;
        g->adjMatrix[end][start] = 1; // Undirected graph
    }
}

void printGraph(Graph* g) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int vertex, Graph* g, int* colors, int color) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && colors[i] == color) {
            return FALSE;
        }
    }
    return TRUE;
}

int graphColoringUtil(Graph* g, int m, int* colors, int vertex) {
    if (vertex == g->numVertices) {
        return TRUE; // All vertices are colored
    }

    for (int color = 1; color <= m; color++) {
        if (isSafe(vertex, g, colors, color)) {
            colors[vertex] = color;
            if (graphColoringUtil(g, m, colors, vertex + 1)) {
                return TRUE;
            }
            colors[vertex] = 0; // Backtrack
        }
    }
    return FALSE; // No valid color found
}

void graphColoring(Graph* g, int m) {
    int colors[MAX_VERTICES] = {0}; // 0 indicates no color assigned
    
    if (graphColoringUtil(g, m, colors, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < g->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, colors[i]);
        }
    } else {
        printf("Solution does not exist for %d colors.\n", m);
    }
}

int main() {
    Graph g;
    int vertices, edges, m;

    printf("Welcome to the Curious Graph Coloring Simulator!\n");
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Too many vertices! Exiting...\n");
        return 1;
    }

    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Enter edge (format: start end): ");
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    printf("Graph created successfully! Here it is:\n");
    printGraph(&g);

    printf("Now, how many colors do you want to use for this adventurous coloring? ");
    scanf("%d", &m);

    graphColoring(&g, m);

    return 0;
}