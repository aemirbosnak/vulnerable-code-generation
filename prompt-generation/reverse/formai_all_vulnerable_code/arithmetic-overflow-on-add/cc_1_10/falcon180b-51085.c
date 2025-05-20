//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    char name[10];
    int id;
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes, num_edges;

void add_node(char* name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(name, nodes[i].name) == 0) {
            printf("Node %s already exists.\n", name);
            return;
        }
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].id = num_nodes;
    num_nodes++;
}

void add_edge(int src, int dest, int weight) {
    Edge edge;
    edge.src = src;
    edge.dest = dest;
    edge.weight = weight;
    edges[num_edges] = edge;
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
        printf("Edge %d: %d -> %d (Weight: %d)\n", i, edges[i].src, edges[i].dest, edges[i].weight);
    }
}

int main() {
    char name[10];
    int choice, src, dest, weight;

    printf("Welcome to the Network Topology Mapper!\n");
    printf("Please enter the number of nodes you want to add: ");
    scanf("%d", &num_nodes);

    printf("Enter the names of the nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        scanf("%s", nodes[i].name);
    }

    printf("Please enter the number of edges you want to add: ");
    scanf("%d", &num_edges);

    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        add_edge(src, dest, weight);
    }

    printf("Network Topology:\n");
    print_nodes();
    print_edges();

    return 0;
}