//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a graph
struct Graph {
    int numVertices;               // Number of vertices in the graph
    struct Node** adjacentLists;   // Array of pointers to adjacency lists
};

// Define a structure to represent a node in an adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjacentLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjacentLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add the edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacentLists[src];
    graph->adjacentLists[src] = newNode;

    // Add the edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjacentLists[dest];
    graph->adjacentLists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjacentLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the allocated memory of the graph
void freeGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjacentLists[v];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjacentLists);
    free(graph);
}

// Main function to demonstrate the graph implementation
int main() {
    int vertices, edges, src, dest;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination) for edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid edge! Please enter edges between 0 and %d.\n", vertices - 1);
            i--; // Decrement i to repeat this edge input
            continue;
        }
        addEdge(graph, src, dest);
    }

    printf("\nGraph representation (adjacency list):\n");
    printGraph(graph);
    
    // Free the allocated memory
    freeGraph(graph);

    return 0;
}