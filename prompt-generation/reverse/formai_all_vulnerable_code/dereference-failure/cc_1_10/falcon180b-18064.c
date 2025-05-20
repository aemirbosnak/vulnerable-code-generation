//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Graph representation structure definition
typedef struct graph {
    int V;
    Node** adj;
} Graph;

// Function to create a new graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = w;
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        Node* node = graph->adj[i];
        printf("Vertex %d is connected with: ", i);
        while (node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int V = 5;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("The graph representation is:\n");
    printGraph(graph);

    return 0;
}