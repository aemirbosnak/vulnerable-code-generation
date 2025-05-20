//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

struct Node {
    int id;
    char name[20];
};

struct Edge {
    int from;
    int to;
    int weight;
};

void add_node(struct Node *nodes, int num_nodes, int id, char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }

    struct Node *new_node = &nodes[num_nodes];
    new_node->id = id;
    strcpy(new_node->name, name);

    num_nodes++;
}

void add_edge(struct Edge *edges, int num_edges, int from, int to, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }

    struct Edge *new_edge = &edges[num_edges];
    new_edge->from = from;
    new_edge->to = to;
    new_edge->weight = weight;

    num_edges++;
}

void print_node(struct Node node) {
    printf("ID: %d, Name: %s\n", node.id, node.name);
}

void print_edge(struct Edge edge) {
    printf("From: %d, To: %d, Weight: %d\n", edge.from, edge.to, edge.weight);
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    struct Node nodes[MAX_NODES];
    struct Edge edges[MAX_EDGES];

    int i;
    for (i = 0; i < num_nodes; i++) {
        int id;
        char name[20];
        scanf("%d %s", &id, name);
        add_node(nodes, i, id, name);
    }

    for (i = 0; i < num_edges; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        add_edge(edges, i, from, to, weight);
    }

    for (i = 0; i < num_nodes; i++) {
        print_node(nodes[i]);
    }

    for (i = 0; i < num_edges; i++) {
        print_edge(edges[i]);
    }

    return 0;
}