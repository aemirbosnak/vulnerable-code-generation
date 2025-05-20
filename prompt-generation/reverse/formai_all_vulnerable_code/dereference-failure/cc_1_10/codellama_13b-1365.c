//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
/*
 * A unique C Graph representation example program
 * Inspired by Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
struct Graph {
    int V;
    struct AdjList* adjList;
};

// Structure to represent an adjacency list
struct AdjList {
    int V;
    struct AdjListNode* head;
};

// Structure to represent a adjacency list node
struct AdjListNode {
    int V;
    struct AdjListNode* next;
};

// Function to create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++) {
        graph->adjList[i].V = V;
        graph->adjList[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add the edge to the adjacency list of src
    struct AdjListNode* newNode = malloc(sizeof(struct AdjListNode));
    newNode->V = dest;
    newNode->next = NULL;
    if (graph->adjList[src].head == NULL) {
        graph->adjList[src].head = newNode;
    } else {
        struct AdjListNode* temp = graph->adjList[src].head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        struct AdjListNode* temp = graph->adjList[i].head;
        while (temp != NULL) {
            printf("%d -> ", temp->V);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}