//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

typedef struct {
    char name[30];
} Vertex;

Graph* createGraph(int vertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize adjacency matrix
        }
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Error: Vertex index out of bounds.\n");
        return;
    }
    graph->adjMatrix[src][dest] = 1; // Create the edge
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

void printGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearchUtil(Graph *graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex); // Print the vertex
  
    for (int v = 0; v < graph->numVertices; v++) {
        if (graph->adjMatrix[vertex][v] == 1 && !visited[v]) {
            depthFirstSearchUtil(graph, v, visited);
        }
    }
}

void depthFirstSearch(Graph *graph, int startVertex) {
    int *visited = (int*)malloc(graph->numVertices * sizeof(int));
    memset(visited, 0, graph->numVertices * sizeof(int)); // Initialize visited array
    depthFirstSearchUtil(graph, startVertex, visited);
    free(visited);
}

void breadthFirstSearch(Graph *graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // An array to keep track of visited vertices
    int queue[MAX_VERTICES], front = -1, rear = -1;

    visited[startVertex] = 1; // Mark the starting vertex as visited
    queue[++rear] = startVertex; // Enqueue the starting vertex

    while (front != rear) {
        front++; 
        int currentVertex = queue[front];
        printf("%d ", currentVertex); // Print current vertex

        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->adjMatrix[currentVertex][v] == 1 && !visited[v]) {
                visited[v] = 1; // Mark it visited
                queue[++rear] = v; // Enqueue it
            }
        }
    }
}

void freeGraph(Graph *graph) {
    free(graph);
}

int main() {
    int vertices, edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph *graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination pairs):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Graph representation:\n");
    printGraph(graph);

    printf("DFS Traversal starting from vertex 0:\n");
    depthFirstSearch(graph, 0);
    printf("\n");

    printf("BFS Traversal starting from vertex 0:\n");
    breadthFirstSearch(graph, 0);
    printf("\n");

    freeGraph(graph);
    return 0;
}