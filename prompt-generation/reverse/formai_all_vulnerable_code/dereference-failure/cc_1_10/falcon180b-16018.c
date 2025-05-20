//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int id;
    char name[50];
    int num_edges;
    struct edge *edges[MAX_EDGES];
} node_t;

typedef struct edge {
    int weight;
    node_t *src;
    node_t *dest;
} edge_t;

void add_edge(node_t *src, node_t *dest, int weight) {
    edge_t *new_edge = (edge_t *)malloc(sizeof(edge_t));
    new_edge->weight = weight;
    new_edge->src = src;
    new_edge->dest = dest;
    src->num_edges++;
    src->edges[src->num_edges - 1] = new_edge;
}

void print_graph(node_t *graph, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", graph[i].id, graph[i].name);
        for (int j = 0; j < graph[i].num_edges; j++) {
            printf("  Edge %d: %d -> %d (weight: %d)\n", j, graph[i].edges[j]->src->id, graph[i].edges[j]->dest->id, graph[i].edges[j]->weight);
        }
    }
}

int main() {
    node_t *graph = (node_t *)malloc(MAX_NODES * sizeof(node_t));
    int num_nodes = 0;
    int num_edges = 0;

    node_t *node1 = &graph[num_nodes++];
    strcpy(node1->name, "Node 1");
    node1->id = 1;

    node_t *node2 = &graph[num_nodes++];
    strcpy(node2->name, "Node 2");
    node2->id = 2;

    node_t *node3 = &graph[num_nodes++];
    strcpy(node3->name, "Node 3");
    node3->id = 3;

    add_edge(node1, node2, 10);
    add_edge(node2, node3, 20);
    add_edge(node3, node1, 30);

    print_graph(graph, num_nodes);

    return 0;
}