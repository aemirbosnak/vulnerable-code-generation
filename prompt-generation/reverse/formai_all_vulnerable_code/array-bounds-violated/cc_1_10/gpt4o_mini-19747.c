//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure for the Graph
typedef struct Graph {
    int numVertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function Prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void removeEdge(Graph* graph, int src, int dest);
bool isEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);
void bfs(Graph* graph, int startVertex);
void dfsUtil(Graph* graph, int vertex, bool visited[]);
void dfs(Graph* graph, int startVertex);

// Main function
int main() {
    int vertices, choice, src, dest;
    
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Remove Edge\n");
        printf("3. Check Edge\n");
        printf("4. Print Graph\n");
        printf("5. BFS Traversal\n");
        printf("6. DFS Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                removeEdge(graph, src, dest);
                break;
            case 3:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                if (isEdge(graph, src, dest)) {
                    printf("Edge exists between %d and %d\n", src, dest);
                } else {
                    printf("No edge exists between %d and %d\n", src, dest);
                }
                break;
            case 4:
                printGraph(graph);
                break;
            case 5:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &src);
                printf("BFS traversal starting from vertex %d: ", src);
                bfs(graph, src);
                printf("\n");
                break;
            case 6:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &src);
                printf("DFS traversal starting from vertex %d: ", src);
                dfs(graph, src);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    freeGraph(graph);
    return 0;
}

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = true;
        graph->adjMatrix[dest][src] = true; // Undirected graph
        printf("Edge added between %d and %d\n", src, dest);
    } else {
        printf("Invalid vertices!\n");
    }
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = false;
        graph->adjMatrix[dest][src] = false; // Undirected graph
        printf("Edge removed between %d and %d\n", src, dest);
    } else {
        printf("Invalid vertices!\n");
    }
}

// Function to check if an edge exists
bool isEdge(Graph* graph, int src, int dest) {
    return graph->adjMatrix[src][dest];
}

// Function to print the adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    free(graph);
}

// Function for BFS traversal
void bfs(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = -1, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front < rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

// Utility function for DFS traversal
void dfsUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

// Function for DFS traversal
void dfs(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    dfsUtil(graph, startVertex, visited);
}