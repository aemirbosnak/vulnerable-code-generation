//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: shocked
/*
 * 🚨 🚨 🚨 WARNING 🚨 🚨 🚨
 * This is a shocking program that uses a unique C Graph representation!
 * It's not for the faint of heart, so be prepared for a wild ride! 💣🚨
 * 🚨 🚨 🚨 WARNING 🚨 🚨 🚨
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    char label[100];
    int weight;
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
} Graph;

void print_graph(Graph* graph) {
    printf("Graph with %d nodes and %d edges\n", graph->num_nodes, graph->num_edges);
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: %s (weight: %d)\n", graph->nodes[i].id, graph->nodes[i].label, graph->nodes[i].weight);
    }
    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge %d: %d -> %d (weight: %d)\n", i, graph->edges[i].src, graph->edges[i].dest, graph->edges[i].weight);
    }
}

int main() {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_nodes = 0;
    graph->num_edges = 0;

    // Add nodes
    Node node1;
    node1.id = 0;
    strcpy(node1.label, "Node 1");
    node1.weight = 10;
    graph->nodes[graph->num_nodes++] = node1;

    Node node2;
    node2.id = 1;
    strcpy(node2.label, "Node 2");
    node2.weight = 20;
    graph->nodes[graph->num_nodes++] = node2;

    Node node3;
    node3.id = 2;
    strcpy(node3.label, "Node 3");
    node3.weight = 30;
    graph->nodes[graph->num_nodes++] = node3;

    // Add edges
    Edge edge1;
    edge1.src = 0;
    edge1.dest = 1;
    edge1.weight = 100;
    graph->edges[graph->num_edges++] = edge1;

    Edge edge2;
    edge2.src = 1;
    edge2.dest = 2;
    edge2.weight = 200;
    graph->edges[graph->num_edges++] = edge2;

    Edge edge3;
    edge3.src = 0;
    edge3.dest = 2;
    edge3.weight = 300;
    graph->edges[graph->num_edges++] = edge3;

    print_graph(graph);

    free(graph);
    return 0;
}