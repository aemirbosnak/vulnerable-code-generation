//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for a graph
typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Function to display the graph
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix Representation of Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search
void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Function to perform Depth First Search
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}

// Function to perform Breadth First Search
void BFS(Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Breadth First Search starting from vertex %d:\n", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++]; 
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i; 
            }
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

// Function to free the allocated memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    displayGraph(graph);

    int startVertex;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &startVertex);
    DFS(graph, startVertex);

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);
    BFS(graph, startVertex);

    freeGraph(graph);
    return 0;
}