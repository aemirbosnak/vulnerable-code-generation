//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000

typedef struct component {
    char name[20];
    int num_nodes;
    int *node_indices;
} component_t;

typedef struct node {
    char name[20];
    int component_index;
    int voltage;
} node_t;

component_t components[MAX_COMPONENTS];
node_t nodes[MAX_NODES];

int num_components = 0;
int num_nodes = 0;

void add_component(char *name, int num_nodes) {
    if (num_components >= MAX_COMPONENTS) {
        printf("Error: Maximum number of components reached.\n");
        exit(1);
    }

    strcpy(components[num_components].name, name);
    components[num_components].num_nodes = num_nodes;
    components[num_components].node_indices = malloc(num_nodes * sizeof(int));

    num_components++;
}

void add_node(char *name, int component_index, int voltage) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }

    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].component_index = component_index;
    nodes[num_nodes].voltage = voltage;

    num_nodes++;
}

void connect_nodes(int node1_index, int node2_index) {
    nodes[node1_index].voltage = nodes[node2_index].voltage;
}

int main() {
    add_component("resistor", 2);
    add_component("capacitor", 2);
    add_component("transistor", 3);

    add_node("A", 0, 5);
    add_node("B", 0, 0);
    add_node("C", 1, 0);
    add_node("D", 1, 0);
    add_node("E", 2, 0);

    connect_nodes(0, 1);
    connect_nodes(1, 2);
    connect_nodes(2, 3);
    connect_nodes(3, 4);

    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: %s (%dV)\n", i, nodes[i].name, nodes[i].voltage);
    }

    return 0;
}