//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Structure for an adjacency list node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Structure for an adjacency list
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(Node*));
    
    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since this is an undirected graph, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth First Search (DFS) utility function
void DFSUtil(Graph* graph, int vertex, int* visited) {
    // Mark the current node as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    Node* temp = graph->adjLists[vertex];
    while (temp) {
        if (!visited[temp->dest]) {
            DFSUtil(graph, temp->dest, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal
void DFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    printf("DFS traversal starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Main function
int main() {
    int vertices, edges, src, dest;

    // Request the user to enter the number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    // Create the graph
    Graph* graph = createGraph(vertices);

    // Request the user to enter the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Get the edges from user input
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Display the graph
    printf("\nGraph representation:\n");
    displayGraph(graph);

    // Perform DFS
    printf("\n");
    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    DFS(graph, startVertex);

    // Free memory
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}