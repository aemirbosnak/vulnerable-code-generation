//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define the structure of a graph node
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Define the structure of a graph
typedef struct graph {
    Node* vertices[MAX_VERTICES];
} Graph;

// Function to create a new graph
Graph* createGraph() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i] = NULL;
    }
    return graph;
}

// Function to add a vertex to the graph
void addVertex(Graph* graph, int vertex) {
    if (graph->vertices[vertex] == NULL) {
        graph->vertices[vertex] = (Node*) malloc(sizeof(Node));
        graph->vertices[vertex]->vertex = vertex;
        graph->vertices[vertex]->next = NULL;
    }
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int vertex1, int vertex2) {
    Node* vertex1Node = graph->vertices[vertex1];
    Node* vertex2Node = graph->vertices[vertex2];

    if (vertex1Node == NULL || vertex2Node == NULL) {
        printf("Invalid vertex\n");
        return;
    }

    vertex1Node->next = vertex2Node;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        Node* vertexNode = graph->vertices[i];

        if (vertexNode == NULL) {
            printf("%d -> None\n", i);
            continue;
        }

        printf("%d -> ", i);

        while (vertexNode!= NULL) {
            printf("%d ", vertexNode->vertex);
            vertexNode = vertexNode->next;
        }

        printf("None\n");
    }
}

// Main function
int main() {
    Graph* graph = createGraph();

    addVertex(graph, 0);
    addVertex(graph, 1);
    addVertex(graph, 2);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}