//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: active
// Graph representation example program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure for storing a graph node
struct GraphNode {
    int vertex;
    struct GraphNode* next;
};

// Structure for storing a graph
struct Graph {
    int numVertices;
    int numEdges;
    struct GraphNode** adjLists;
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = V;
    graph->numEdges = E;
    graph->adjLists = malloc(V * sizeof(struct GraphNode*));
    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct GraphNode* newNode = malloc(sizeof(struct GraphNode));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (if not already present)
    bool found = false;
    struct GraphNode* temp = graph->adjLists[dest];
    while (temp != NULL && !found) {
        if (temp->vertex == src) {
            found = true;
        } else {
            temp = temp->next;
        }
    }
    if (!found) {
        newNode = malloc(sizeof(struct GraphNode));
        newNode->vertex = src;
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// Function to print a graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        struct GraphNode* temp = graph->adjLists[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5, 6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    printGraph(graph);
    return 0;
}