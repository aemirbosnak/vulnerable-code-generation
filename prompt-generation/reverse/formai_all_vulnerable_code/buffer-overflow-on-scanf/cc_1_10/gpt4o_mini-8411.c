//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX][MAX];
} Graph;

// Function to create and initialize the graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize adjacency matrix with 0s
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Function to print the adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform depth-first search
void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to initiate DFS traversal
void DFS(Graph* graph) {
    int visited[MAX] = {0};
    printf("Depth First Search Traversal:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
    printf("\n");
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    free(graph);
}

// Function to create a visual representation of the graph
void visualizeGraph(Graph* graph) {
    printf("Visual Representation of the Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("-> %d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);
    visualizeGraph(graph);
    DFS(graph);
    
    freeGraph(graph);
    return 0;
}