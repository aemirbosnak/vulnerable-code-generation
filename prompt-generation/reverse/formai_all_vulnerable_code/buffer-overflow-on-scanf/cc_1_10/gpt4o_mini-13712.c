//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct {
    int vertexCount;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
    Graph *graph;
    int vertex;
} ThreadData;

void initializeGraph(Graph *g, int vertices) {
    g->vertexCount = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    if (src >= g->vertexCount || dest >= g->vertexCount) {
        printf("Invalid edge (%d, %d) for graph with %d vertices.\n", src, dest, g->vertexCount);
        return;
    }
    g->adjacencyMatrix[src][dest] = 1;
    g->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

void *displayVertexEdges(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    Graph *g = data->graph;
    int vertex = data->vertex;
    
    printf("Edges connected to vertex %d: ", vertex);
    for (int j = 0; j < g->vertexCount; j++) {
        if (g->adjacencyMatrix[vertex][j]) {
            printf("%d ", j);
        }
    }
    printf("\n");
    
    return NULL;
}

void displayGraph(Graph *g) {
    pthread_t threads[MAX_VERTICES];
    ThreadData threadData[MAX_VERTICES];
    
    for (int i = 0; i < g->vertexCount; i++) {
        threadData[i].graph = g;
        threadData[i].vertex = i;
        pthread_create(&threads[i], NULL, displayVertexEdges, (void *)&threadData[i]);
    }
    
    for (int i = 0; i < g->vertexCount; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    Graph g;
    int vertices, edges, src, dest;
    
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    
    if (vertices > MAX_VERTICES) {
        printf("Exceeded maximum vertices limit.\n");
        return 1;
    }
    
    initializeGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination) pairs:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("The adjacency list of the graph:\n");
    displayGraph(&g);

    return 0;
}