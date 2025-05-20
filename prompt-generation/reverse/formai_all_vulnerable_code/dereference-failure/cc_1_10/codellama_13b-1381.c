//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: creative
// Graph representation using adjacency list

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    struct AdjList* adjList;
};

// Structure to represent an adjacency list node
struct AdjList {
    int vertex;
    struct AdjList* next;
};

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjList* newNode = (struct AdjList*) malloc(sizeof(struct AdjList));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src].next;
    graph->adjList[src].next = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = (struct AdjList*) malloc(sizeof(struct AdjList));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest].next;
    graph->adjList[dest].next = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct AdjList* node = graph->adjList[i].next;
        printf("%d: ", i);
        while (node != NULL) {
            printf("%d ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a graph with 4 vertices
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = 4;
    graph->numEdges = 0;
    graph->adjList = (struct AdjList**) malloc(graph->numVertices * sizeof(struct AdjList*));
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjList[i].next = NULL;
    }

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // Print the graph
    printGraph(graph);

    return 0;
}