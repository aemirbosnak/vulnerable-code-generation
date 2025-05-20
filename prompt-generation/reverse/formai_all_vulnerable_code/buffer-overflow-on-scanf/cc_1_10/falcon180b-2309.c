//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[20];
    int degree;
    int *adjacent_nodes;
} Node;

typedef struct {
    int source_node_id;
    int destination_node_id;
} Edge;

void initialize_graph(Node *nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        strcpy(nodes[i].name, "Node ");
        sprintf(&nodes[i].name[6], "%d", i);
        nodes[i].degree = 0;
        nodes[i].adjacent_nodes = NULL;
    }
}

void add_edge(Edge *edges, int num_edges, int source_node_id, int destination_node_id) {
    for (int i = 0; i < num_edges; i++) {
        if (edges[i].source_node_id == -1 && edges[i].destination_node_id == -1) {
            edges[i].source_node_id = source_node_id;
            edges[i].destination_node_id = destination_node_id;
            return;
        }
    }
}

void print_graph(Node *nodes, int num_nodes, Edge *edges, int num_edges) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s, Degree: %d\n", nodes[i].id, nodes[i].name, nodes[i].degree);
    }

    for (int i = 0; i < num_edges; i++) {
        if (edges[i].source_node_id!= -1 && edges[i].destination_node_id!= -1) {
            printf("Edge %d: (%d, %d)\n", i, edges[i].source_node_id, edges[i].destination_node_id);
        }
    }
}

int main() {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];

    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    initialize_graph(nodes, num_nodes);

    for (int i = 0; i < num_edges; i++) {
        int source_node_id, destination_node_id;
        scanf("%d %d", &source_node_id, &destination_node_id);
        add_edge(edges, num_edges, source_node_id, destination_node_id);
    }

    print_graph(nodes, num_nodes, edges, num_edges);

    return 0;
}