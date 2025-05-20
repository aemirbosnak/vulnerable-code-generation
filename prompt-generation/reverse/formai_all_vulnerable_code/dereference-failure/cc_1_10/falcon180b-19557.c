//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000

// Graph representation using adjacency list
typedef struct {
    int n;
    int m;
    int *nodes;
    int **adj_list;
} Graph;

// Create a new graph with n nodes
Graph *createGraph(int n) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->n = n;
    graph->m = 0;
    graph->nodes = (int *) malloc(n * sizeof(int));
    graph->adj_list = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph->nodes[i] = i;
        graph->adj_list[i] = (int *) malloc(MAX_EDGES * sizeof(int));
        for (int j = 0; j < MAX_EDGES; j++) {
            graph->adj_list[i][j] = -1;
        }
    }
    return graph;
}

// Add an edge between two nodes
void addEdge(Graph *graph, int u, int v) {
    if (graph->m >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }
    graph->adj_list[u][graph->m++] = v;
    graph->adj_list[v][graph->m++] = u;
}

// Print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->n; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < graph->m; j++) {
            if (graph->adj_list[i][j]!= -1) {
                printf("%d ", graph->adj_list[i][j]);
            } else {
                printf("-1 ");
            }
        }
        printf("\n");
    }
}

// Free the memory used by the graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->n; i++) {
        free(graph->adj_list[i]);
    }
    free(graph->adj_list);
    free(graph->nodes);
    free(graph);
}

int main() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    printGraph(graph);
    freeGraph(graph);
    return 0;
}