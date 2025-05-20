//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int id;
    int degree; // number of edges connected to this node
    int *adj_list; // list of adjacent nodes
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Node *create_node(int id) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    new_node->degree = 0;
    new_node->adj_list = (int*)malloc(MAX_EDGES * sizeof(int));
    for (int i = 0; i < MAX_EDGES; i++) {
        new_node->adj_list[i] = -1; // initialize with invalid value
    }
    return new_node;
}

void add_edge(Node *graph, int src, int dest, int weight) {
    Edge *new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->src = src;
    new_edge->dest = dest;
    new_edge->weight = weight;
    graph->adj_list[graph->degree++] = dest;
}

void print_graph(Node *graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->degree; i++) {
        printf("%d -> %d (%d)\n", graph->id, graph->adj_list[i], INF);
    }
}

int main() {
    Node *graph = create_node(1); // create a graph with one node
    add_edge(graph, 1, 2, 5); // add an edge between nodes 1 and 2 with weight 5
    add_edge(graph, 1, 3, 3); // add an edge between nodes 1 and 3 with weight 3
    add_edge(graph, 2, 4, 2); // add an edge between nodes 2 and 4 with weight 2
    add_edge(graph, 3, 4, 1); // add an edge between nodes 3 and 4 with weight 1
    print_graph(graph); // print the graph
    return 0;
}