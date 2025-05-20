//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

// Structure to represent a node in the linked list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since it's an undirected graph, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\n Vertex %d:\n head ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the graph memory
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

// Main function with a user interface to interact with the graph
int main() {
    int numVertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    
    Graph* graph = createGraph(numVertices);
    
    int choice, src, dest;
    
    while (1) {
        printf("\nGraph Menu:\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter source and destination vertices (0 to %d): ", numVertices - 1);
                scanf("%d %d", &src, &dest);
                if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
                    addEdge(graph, src, dest);
                    printf("Edge added between %d and %d\n", src, dest);
                } else {
                    printf("Invalid vertices! Please try again.\n");
                }
                break;
                
            case 2:
                printGraph(graph);
                break;
                
            case 3:
                freeGraph(graph);
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}