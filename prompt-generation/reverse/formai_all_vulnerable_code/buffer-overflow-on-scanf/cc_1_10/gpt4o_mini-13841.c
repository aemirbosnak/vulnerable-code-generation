//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int destination;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void DFS(Graph* graph, int startVertex);
void DFSUtil(Graph* graph, int vertex, int* visited);
Node* createNode(int dest);

// Main Function
int main() {
    int vertices, choice, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    do {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph\n");
        printf("3. Perform DFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination (e.g., 0 1): ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                printf("Edge added from %d to %d.\n", src, dest);
                break;
            case 2:
                printGraph(graph);
                break;
            case 3:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &src);
                printf("DFS traversal starting from vertex %d:\n", src);
                DFS(graph, src);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Create a node for the adjacency list
Node* createNode(int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->destination = dest;
    newNode->next = NULL;
    return newNode;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->destination);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Perform DFS traversal
void DFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Utility function for DFS
void DFSUtil(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    while (temp) {
        int connectedVertex = temp->destination;

        if (!visited[connectedVertex]) {
            DFSUtil(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}