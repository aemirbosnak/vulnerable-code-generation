//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Cryptic
/*
 * Unique C Graph representation program
 */

#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int vertices;
    int edges;
    struct AdjacencyList *adj;
};

struct AdjacencyList {
    int vertex;
    int weight;
    struct AdjacencyList *next;
};

struct Graph *createGraph(int vertices, int edges) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->adj = malloc(vertices * sizeof(struct AdjacencyList));
    for (int i = 0; i < vertices; i++) {
        graph->adj[i].vertex = i;
        graph->adj[i].weight = 0;
        graph->adj[i].next = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int v1, int v2, int weight) {
    struct AdjacencyList *newNode = malloc(sizeof(struct AdjacencyList));
    newNode->vertex = v2;
    newNode->weight = weight;
    newNode->next = graph->adj[v1].next;
    graph->adj[v1].next = newNode;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct AdjacencyList *temp = graph->adj[i].next;
        printf("%d -> ", graph->adj[i].vertex);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph *graph = createGraph(5, 5);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 1);
    printGraph(graph);
    return 0;
}