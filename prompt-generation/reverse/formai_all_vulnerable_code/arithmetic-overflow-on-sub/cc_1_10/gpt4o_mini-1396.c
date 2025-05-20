//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(int vertex);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);
void displayMenu();
void handleUserInput(Graph* graph);

// Main function
int main() {
    int vertices, choice;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        handleUserInput(graph);
        
    } while (choice != 3);

    freeGraph(graph);
    return 0;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        Node* next;

        while (temp) {
            next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add edge\n");
    printf("2. Print graph\n");
    printf("3. Exit\n");
}

// Function to handle user input
void handleUserInput(Graph* graph) {
    int src, dest, choice;

    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter source and destination vertices (0 to %d): ", graph->numVertices - 1);
            scanf("%d %d", &src, &dest);
            if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
                addEdge(graph, src, dest);
                printf("Edge added between %d and %d\n", src, dest);
            } else {
                printf("Invalid vertex! Please try again.\n");
            }
            break;

        case 2:
            printGraph(graph);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please select again.\n");
            break;
    }
}