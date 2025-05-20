//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 30

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Matrix to represent connections
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize the adjacency matrix to zero
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int startVertex, int endVertex) {
    graph->adjacencyMatrix[startVertex][endVertex] = 1; // Directed edge from startVertex to endVertex
    graph->adjacencyMatrix[endVertex][startVertex] = 1; // Comment this line for a directed graph
}

void displayGraph(Graph* graph) {
    printf("Graph Adjacency Matrix:\n");

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearch(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the node as visited
    printf("%d ", vertex); // Print the visited node

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(graph, i, visited);
        }
    }
}

void breadthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to track visited vertices
    int queue[MAX_VERTICES], front = 0, rear = -1; // Queue for BFS

    visited[startVertex] = 1; 
    queue[++rear] = startVertex; // Enqueue the start vertex

    printf("\nBFS starting from vertex %d: ", startVertex);
    
    while (front <= rear) {
        int currentVertex = queue[front++]; // Dequeue the front vertex
        printf("%d ", currentVertex); // Print the current vertex

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[++rear] = i; // Enqueue the neighbor vertex
            }
        }
    }
}

int main() {
    int vertices, edges, startVertex;
    
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        fprintf(stderr, "Error: Maximum number of vertices exceeded.\n");
        return 1;
    }

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);
        if (start >= vertices || end >= vertices) {
            fprintf(stderr, "Error: Vertex index out of bounds.\n");
            free(graph);
            return 1;
        }
        addEdge(graph, start, end);
    }

    displayGraph(graph);

    int visited[MAX_VERTICES] = {0}; // Reset visited for DFS
    printf("DFS traversal starting from vertex 0: ");
    depthFirstSearch(graph, 0, visited);
    
    printf("\n");
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);
    
    if (startVertex >= vertices) {
        fprintf(stderr, "Error: Vertex index out of bounds.\n");
        free(graph);
        return 1;
    }

    breadthFirstSearch(graph, startVertex);

    free(graph);
    return 0;
}