//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: relaxed
// Graph representation example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    struct AdjList* adjList; // Array of adjacency lists
};

// Structure to represent an adjacency list
struct AdjList {
    int v; // Vertex number
    struct AdjList* next; // Pointer to next vertex
};

// Utility function to create a new graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = 0;
    graph->adjList = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++) {
        graph->adjList[i].v = i;
        graph->adjList[i].next = NULL;
    }
    return graph;
}

// Utility function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjList* newNode = (struct AdjList*)malloc(sizeof(struct AdjList));
    newNode->v = dest;
    newNode->next = graph->adjList[src].next;
    graph->adjList[src].next = newNode;
    graph->E++;
}

// Utility function to print a graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        struct AdjList* pCrawl = graph->adjList[i].next;
        while (pCrawl != NULL) {
            printf("%d ", pCrawl->v);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}