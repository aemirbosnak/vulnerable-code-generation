//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Alan Turing
// C program to represent a graph using an adjacency list

#include <stdio.h>
#include <stdlib.h>

// Adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Adjacency list
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// Graph structure
typedef struct Graph {
    int numVertices;
    AdjList* array;
} Graph;

// Utility function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* node = (AdjListNode*)malloc(sizeof(AdjListNode));
    node->dest = dest;
    node->next = NULL;
    return node;
}

// Utility function to create a new graph
Graph* newGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->array = (AdjList*)malloc(numVertices * sizeof(AdjList));
    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Utility function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add the destination to the source's adjacency list
    AdjListNode* node = newAdjListNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    // Add the source to the destination's adjacency list
    node = newAdjListNode(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

// Utility function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        AdjListNode* node = graph->array[i].head;
        while (node != NULL) {
            printf("%d -> ", node->dest);
            node = node->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a graph with 5 vertices
    Graph* graph = newGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}