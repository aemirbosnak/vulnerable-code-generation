//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_EDGES 50

typedef struct node {
    int id;
    int degree;
    struct node *neighbors[MAX_EDGES];
} node;

node nodes[MAX_NODES];
int num_nodes, num_edges;

void add_node(int id) {
    if (num_nodes >= MAX_NODES) {
        fprintf(stderr, "Too many nodes!\n");
        exit(1);
    }

    nodes[num_nodes].id = id;
    nodes[num_nodes].degree = 0;
    memset(nodes[num_nodes].neighbors, 0, sizeof(nodes[num_nodes].neighbors));

    num_nodes++;
}

void add_edge(int u, int v) {
    if (u > MAX_NODES || v > MAX_NODES || u == v) {
        fprintf(stderr, "Invalid node ID!\n");
        exit(1);
    }

    nodes[u].degree++;
    nodes[v].degree++;
    nodes[u].neighbors[nodes[u].degree - 1] = (struct node *)malloc(sizeof(struct node));
    *(nodes[u].neighbors[nodes[u].degree - 1]) = nodes[v];

    num_edges++;
}

void print_nodes() {
    int i;

    printf("Node ID\tDegree\n");
    for (i = 0; i < num_nodes; i++) {
        printf("%d\t%d\n", i, nodes[i].degree);
    }
}

void print_edges() {
    int i, j;

    printf("From\tTo\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < nodes[i].degree; j++) {
            printf("%d\t%d\n", i, nodes[i].neighbors[j]->id);
        }
    }
}

int main() {
    int num_nodes_input, num_edges_input;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes_input);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges_input);

    num_nodes = num_nodes_input;
    num_edges = num_edges_input;

    printf("Enter the node IDs (space separated): ");
    fgets(nodes[0].id, sizeof(nodes[0].id), stdin);
    for (int i = 1; i < num_nodes; i++) {
        nodes[i].id = 0;
        fgets(nodes[i].id, sizeof(nodes[i].id), stdin);
    }

    for (int i = 0; i < num_nodes - 1; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            add_edge(nodes[i].id, nodes[j].id);
        }
    }

    print_nodes();
    print_edges();

    return 0;
}