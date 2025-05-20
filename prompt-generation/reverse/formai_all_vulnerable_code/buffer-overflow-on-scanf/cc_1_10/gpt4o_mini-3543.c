//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

// Structure to represent an adjacency list node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Structure to represent the adjacency list
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
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

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge from dest to src as well
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

// Function to free the entire graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
}

// Main function to run the program
int main() {
    printf("🎉 Welcome to the Amazing Graph Representation Program! 🎉\n");

    int vertices, edges, src, dest;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Wow! You have created a graph with %d vertices! Let’s add some edges!\n", vertices);

    printf("Enter the number of edges you want to add: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (format: src dest): ", i + 1);
        scanf("%d %d", &src, &dest);

        // Validating vertex input
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("🚨 Invalid edge! Please enter vertices between 0 and %d.\n", vertices - 1);
            i--; // decrement to re-ask for the edge
            continue;
        }

        addEdge(graph, src, dest);
        printf("✨ Edge added successfully between %d and %d! ✨\n", src, dest);
    }

    printf("\n🎊 Here’s the awesome representation of your graph! 🎊\n");
    displayGraph(graph);

    // Free the allocated memory for the graph
    freeGraph(graph);
    
    printf("\n🗑️ All clean! Your graph has been safely deleted. Thank you for using the program! 🗑️\n");
    return 0;
}