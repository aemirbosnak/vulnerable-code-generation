//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Struct to represent a graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void visualizeGraph(Graph* graph);
void freeGraph(Graph* graph);

// Main function
int main() {
    int vertices, edges, i, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nGraph adjacency list:\n");
    printGraph(graph);

    printf("\nVisualizing the graph:\n");
    visualizeGraph(graph);

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

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph's adjacency list
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("%d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to visualize the graph
void visualizeGraph(Graph* graph) {
    printf("Graph Visualization in ASCII:\n");
    printf("Vertices:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if(j == i) {
                printf("O ");  // represent the vertex
            } else {
                Node* temp = graph->adjLists[i];
                int connected = 0;
                while (temp) {
                    if (temp->vertex == j) {
                        connected = 1;
                        break;
                    }
                    temp = temp->next;
                }
                printf(connected ? "- " : "  "); // represent edge or no connection
            }
        }
        printf("\n");
    }
}

// Function to free the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}