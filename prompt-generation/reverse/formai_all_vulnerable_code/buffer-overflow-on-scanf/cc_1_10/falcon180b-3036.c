//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    char name[20];
    int index;
} Node;

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(char *name) {
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].index = num_nodes;
    num_nodes++;
}

int find_node(char *name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    add_node(name);
    return num_nodes - 1;
}

void add_edge(int from, int to, int weight) {
    edges[num_edges].from = from;
    edges[num_edges].to = to;
    edges[num_edges].weight = weight;
    num_edges++;
}

void print_nodes() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", i, nodes[i].name);
    }
}

void print_edges() {
    int i;
    for (i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].from, edges[i].to, edges[i].weight);
    }
}

int main() {
    int i, j, k, n;
    char name[20];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", name);
        add_node(name);
    }
    printf("Enter the number of edges: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the source node of edge %d: ", i+1);
        scanf("%d", &j);
        printf("Enter the destination node of edge %d: ", i+1);
        scanf("%d", &k);
        printf("Enter the weight of edge %d: ", i+1);
        scanf("%d", &n);
        add_edge(j, k, n);
    }
    printf("Nodes:\n");
    print_nodes();
    printf("Edges:\n");
    print_edges();
    return 0;
}