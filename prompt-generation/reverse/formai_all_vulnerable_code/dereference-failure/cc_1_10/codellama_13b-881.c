//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: scientific
// Unique C Data structures visualization example program in a scientific style

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a linked list
struct Node {
    int data;
    struct Node *next;
};

// Define a structure for a graph
struct Graph {
    int num_vertices;
    int num_edges;
    struct Node *adj_list;
};

// Function to create a graph with V vertices and E edges
struct Graph *createGraph(int V, int E) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->num_vertices = V;
    graph->num_edges = E;
    graph->adj_list = malloc(V * sizeof(struct Node));
    for (int i = 0; i < V; i++) {
        graph->adj_list[i].data = i;
        graph->adj_list[i].next = NULL;
    }
    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adj_list[src].next;
    graph->adj_list[src].next = newNode;
}

// Function to print a graph
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        struct Node *node = graph->adj_list[i].next;
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// Function to free a graph
void freeGraph(struct Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct Node *node = graph->adj_list[i].next;
        while (node != NULL) {
            struct Node *temp = node->next;
            free(node);
            node = temp;
        }
    }
    free(graph->adj_list);
    free(graph);
}

int main() {
    struct Graph *graph = createGraph(5, 8);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 0);
    printGraph(graph);
    freeGraph(graph);
    return 0;
}