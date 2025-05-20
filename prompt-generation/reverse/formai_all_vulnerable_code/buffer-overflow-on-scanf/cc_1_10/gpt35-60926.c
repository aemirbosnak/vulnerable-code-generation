//FormAI DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // Maximum number of vertices in the graph

struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; ++j) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
}

void printGraph(struct Graph* graph) {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    int numEdges;
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; ++i) {
        printf("Enter edge %d source and destination: ", i + 1);
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(graph, source, destination);
    }

    printGraph(graph);

    return 0;
}