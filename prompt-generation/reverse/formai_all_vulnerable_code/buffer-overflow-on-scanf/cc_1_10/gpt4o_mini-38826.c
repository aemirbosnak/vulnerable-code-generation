//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

typedef struct Graph {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph* g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            g->adjacencyMatrix[i][j] = 0;
}

void addEdge(Graph* g, int start, int end) {
    if (start >= 0 && start < g->numVertices && end >= 0 && end < g->numVertices) {
        g->adjacencyMatrix[start][end] = 1;
        g->adjacencyMatrix[end][start] = 1; // For undirected graph
    }
}

void displayGraph(const Graph* g) {
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearch(const Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(g, i, visited);
        }
    }
}

void traverseGraph(const Graph* g) {
    bool visited[MAX_VERTICES] = {false};

    printf("Depth First Traversal:\n");
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i])
            depthFirstSearch(g, i, visited);
    }
    printf("\n");
}

void freeGraph(Graph* g) {
    // In our case, there is no dynamic memory allocation in this code.
    // This function can include cleanup code if needed in future
}

int main() {
    Graph g;
    int numVertices;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return -1;
    }

    initGraph(&g, numVertices);

    int edges, start, end;
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);
        addEdge(&g, start, end);
    }

    displayGraph(&g);
    traverseGraph(&g);
    freeGraph(&g);

    return 0;
}