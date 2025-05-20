//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Function to create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
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

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth-First Search (DFS) Algorithm
void DFSUtil(int vertex, int visited[], Graph* graph) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFSUtil(connectedVertex, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    DFSUtil(startVertex, visited, graph);
    free(visited);
}

// Function to free the graph's memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

// Main function to interact with the graph
int main() {
    int vertices, choice, src, dest;

    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    if (vertices >= MAX_VERTICES || vertices <= 0) {
        printf("Invalid number of vertices. Please restart the program.\n");
        return 1;
    }

    Graph* graph = createGraph(vertices);

    do {
        printf("\nMenu:\n");
        printf("1. Add edge\n");
        printf("2. Display graph\n");
        printf("3. Perform DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
                    printf("Invalid vertices. Please try again.\n");
                } else {
                    addEdge(graph, src, dest);
                }
                break;
            case 2:
                displayGraph(graph);
                break;
            case 3:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &src);
                if (src >= vertices || src < 0) {
                    printf("Invalid vertex. Please try again.\n");
                } else {
                    printf("Depth-First Traversal starting from vertex %d:\n", src);
                    DFS(graph, src);
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeGraph(graph);
    return 0;
}