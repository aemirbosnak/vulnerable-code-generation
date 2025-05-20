//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
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
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// DFS utility function
void DFSUtil(int vertex, int visited[], Graph* graph) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to perform DFS
void DFS(Graph* graph) {
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFSUtil(i, visited, graph);
        }
    }
    printf("\n");
}

// Menu-driven interface for user input
void menu() {
    int choice, vertices, src, dest;
    Graph* graph = NULL;

    while (1) {
        printf("\nGraph Menu:\n");
        printf("1. Create graph\n");
        printf("2. Add edge\n");
        printf("3. Display graph\n");
        printf("4. Perform DFS\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);
                printf("Graph created with %d vertices.\n", vertices);
                break;
            case 2:
                if (!graph) {
                    printf("Graph not created yet!\n");
                } else {
                    printf("Enter source and destination (0 to %d): ", graph->numVertices - 1);
                    scanf("%d %d", &src, &dest);
                    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
                        addEdge(graph, src, dest);
                        printf("Edge added between %d and %d.\n", src, dest);
                    } else {
                        printf("Invalid vertex numbers!\n");
                    }
                }
                break;
            case 3:
                if (graph) {
                    displayGraph(graph);
                } else {
                    printf("Graph not created yet!\n");
                }
                break;
            case 4:
                if (graph) {
                    printf("DFS Traversal: ");
                    DFS(graph);
                } else {
                    printf("Graph not created yet!\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                free(graph);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}