//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0; // Initialize all edges to 0
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjMatrix[dest][src] = 1; // For undirected graph, add edge in both directions
}

// Function to display the graph
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix representation of the graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform BFS on the graph
void bfs(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS starting from vertex %d:\n", startVertex);
    while (front < rear) {
        int currVertex = queue[front++];
        printf("%d ", currVertex);
        
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// Function to perform DFS on the graph
void dfsUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

void dfs(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS starting from vertex %d:\n", startVertex);
    dfsUtil(graph, startVertex, visited);
    printf("\n");
}

// Function to delete the graph and free memory
void deleteGraph(Graph* graph) {
    free(graph);
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
    
    displayGraph(graph);
    
    int startVertex;
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);
    bfs(graph, startVertex);
    
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &startVertex);
    dfs(graph, startVertex);
    
    deleteGraph(graph);
    
    return 0;
}