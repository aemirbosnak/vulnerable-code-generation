//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the graph
struct Node {
    int vertex;
    struct Node* next;
};

// Define a structure to represent an adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    
    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since it's an undirected graph, add an edge from destination to source also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to execute the graph mapping
int main() {
    int vertices, edges;
    printf("Welcome to the Network Topology Mapper!\n");
    
    // Get the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Create the graph
    struct Graph* graph = createGraph(vertices);

    // Get edges from the user
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Print the graph
    printf("\nHere is the represented network topology:\n");
    printGraph(graph);
    
    // Cleanup: free memory
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);

    printf("\nThank you for using the Network Topology Mapper! Goodbye!\n");
    return 0;
}