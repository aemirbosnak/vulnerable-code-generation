//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int id;
    char name[50];
    int degree;
    int *connected_nodes;
} Node;

typedef struct {
    int start_node;
    int end_node;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(char *name) {
    num_nodes++;
    Node *new_node = &nodes[num_nodes - 1];
    strcpy(new_node->name, name);
    new_node->id = num_nodes - 1;
    new_node->degree = 0;
    new_node->connected_nodes = malloc(sizeof(int) * MAX_NODES);
    memset(new_node->connected_nodes, -1, sizeof(int) * MAX_NODES);
}

void add_edge(int start_node_id, int end_node_id, int weight) {
    num_edges++;
    Edge *new_edge = &edges[num_edges - 1];
    new_edge->start_node = start_node_id;
    new_edge->end_node = end_node_id;
    new_edge->weight = weight;
    nodes[start_node_id].degree++;
    nodes[end_node_id].degree++;
}

void print_node(Node node) {
    printf("Node: %s (%d)\n", node.name, node.id);
    printf("Degree: %d\n", node.degree);
    printf("Connected nodes: ");
    for (int i = 0; i < MAX_NODES; i++) {
        if (node.connected_nodes[i]!= -1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void print_edge(Edge edge) {
    printf("Edge: %d -> %d (%d)\n", edge.start_node, edge.end_node, edge.weight);
}

void print_network() {
    for (int i = 0; i < num_nodes; i++) {
        print_node(nodes[i]);
        for (int j = 0; j < MAX_NODES; j++) {
            if (nodes[i].connected_nodes[j]!= -1) {
                print_edge(edges[nodes[i].connected_nodes[j]]);
            }
        }
    }
}

int main() {
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_edge(0, 1, 3);
    add_edge(0, 2, 2);
    add_edge(1, 2, 4);
    add_edge(2, 3, 5);
    print_network();
    return 0;
}