//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initializeGraph(Graph *g, int vertices) {
    g->vertices = vertices;

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adjacencyMatrix[src][dest] = 1;
    g->adjacencyMatrix[dest][src] = 1; // For undirected graph
}

bool isSafe(Graph *g, int colors[], int vertex, int c) {
    for(int i = 0; i < g->vertices; i++) {
        if(g->adjacencyMatrix[vertex][i] == 1 && colors[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph *g, int m, int colors[], int vertex) {
    if(vertex == g->vertices) {
        return true;
    }

    for(int c = 1; c <= m; c++) {
        if(isSafe(g, colors, vertex, c)) {
            colors[vertex] = c;

            if(graphColoringUtil(g, m, colors, vertex + 1)) {
                return true;
            }

            colors[vertex] = 0; // Backtrack
        }
    }
    return false;
}

bool graphColoring(Graph *g, int m) {
    int *colors = (int *)malloc(g->vertices * sizeof(int));

    for(int i = 0; i < g->vertices; i++) {
        colors[i] = 0;
    }

    if(!graphColoringUtil(g, m, colors, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    printf("Solution exists: Following are the assigned colors:\n");
    for(int i = 0; i < g->vertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, colors[i]);
    }
    free(colors);
    return true;
}

int main() {
    Graph g;
    int vertices, edges, src, dest, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (source destination) format:\n");
    for(int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(&g, m);

    return 0;
}