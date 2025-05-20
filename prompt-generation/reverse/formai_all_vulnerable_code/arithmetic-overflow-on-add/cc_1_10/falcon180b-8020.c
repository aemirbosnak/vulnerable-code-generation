//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 100
#define MAX_NAME_LENGTH 20

struct node {
    char name[MAX_NAME_LENGTH];
    int id;
    int num_edges;
    struct edge *edges;
};

struct edge {
    int to_node_id;
    int weight;
};

int num_nodes = 0;
int num_edges = 0;

struct node *nodes = NULL;
struct edge *edges = NULL;

void add_node(char *name) {
    num_nodes++;
    if (num_nodes == MAX_NODES) {
        printf("Error: maximum number of nodes reached.\n");
        exit(1);
    }
    nodes = realloc(nodes, sizeof(struct node) * num_nodes);
    strcpy(nodes[num_nodes - 1].name, name);
    nodes[num_nodes - 1].id = num_nodes - 1;
    nodes[num_nodes - 1].num_edges = 0;
    nodes[num_nodes - 1].edges = NULL;
}

void add_edge(int from_node_id, int to_node_id, int weight) {
    num_edges++;
    if (num_edges == MAX_EDGES) {
        printf("Error: maximum number of edges reached.\n");
        exit(1);
    }
    edges = realloc(edges, sizeof(struct edge) * num_edges);
    edges[num_edges - 1].to_node_id = to_node_id;
    edges[num_edges - 1].weight = weight;
    nodes[from_node_id - 1].num_edges++;
}

void print_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", i + 1, nodes[i].name);
    }
}

void print_edges() {
    printf("Edges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].to_node_id + 1, edges[i].to_node_id + 1, edges[i].weight);
    }
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_node("Node 3");
    add_edge(1, 2, 10);
    add_edge(2, 3, 20);
    add_edge(3, 1, 30);
    print_nodes();
    print_edges();
    return 0;
}