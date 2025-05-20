//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define NODE_NAME_LENGTH 20

typedef struct {
    char name[NODE_NAME_LENGTH];
    int num_edges;
    int *edges;
} Node;

typedef struct {
    int from;
    int to;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes, num_edges;

void add_node(char *name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            printf("Node %s already exists.\n", name);
            return;
        }
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].num_edges = 0;
    nodes[num_nodes].edges = NULL;
    num_nodes++;
}

void add_edge(int from, int to) {
    Edge edge;
    edge.from = from;
    edge.to = to;
    edges[num_edges] = edge;
    num_edges++;
    nodes[from].num_edges++;
    nodes[to].num_edges++;
}

void print_nodes() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("%s (%d edges)\n", nodes[i].name, nodes[i].num_edges);
    }
}

void print_edges() {
    int i;
    for (i = 0; i < num_edges; i++) {
        printf("Edge %d: %d -> %d\n", i, edges[i].from, edges[i].to);
    }
}

int main() {
    int i, j, from, to;
    char name[NODE_NAME_LENGTH];

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", nodes[i].name);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; i++) {
        printf("Enter the nodes for edge %d: ", i+1);
        scanf("%d %d", &from, &to);
        add_edge(from, to);
    }

    print_nodes();
    print_edges();

    return 0;
}