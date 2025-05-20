//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 200
#define MAX_LINKS 1000

typedef struct {
    int id;
    double value;
} component;

typedef struct {
    int id;
    double voltage;
} node;

typedef struct {
    int source_node_id;
    int dest_node_id;
    double resistance;
} link;

int num_components = 0;
int num_nodes = 0;
int num_links = 0;

component *components;
node *nodes;
link *links;

void create_component(int id, double value) {
    components = realloc(components, sizeof(component) * ++num_components);
    components[num_components - 1].id = id;
    components[num_components - 1].value = value;
}

void create_node(int id, double voltage) {
    nodes = realloc(nodes, sizeof(node) * ++num_nodes);
    nodes[num_nodes - 1].id = id;
    nodes[num_nodes - 1].voltage = voltage;
}

void create_link(int source_node_id, int dest_node_id, double resistance) {
    links = realloc(links, sizeof(link) * ++num_links);
    links[num_links - 1].source_node_id = source_node_id;
    links[num_links - 1].dest_node_id = dest_node_id;
    links[num_links - 1].resistance = resistance;
}

void simulate() {
    for (int i = 0; i < num_links; i++) {
        int source_node_id = links[i].source_node_id;
        int dest_node_id = links[i].dest_node_id;
        double resistance = links[i].resistance;
        double current = (nodes[dest_node_id].voltage - nodes[source_node_id].voltage) / resistance;
        double voltage_drop = current * resistance;
        nodes[source_node_id].voltage -= voltage_drop;
        nodes[dest_node_id].voltage += voltage_drop;
    }
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %.2fV\n", nodes[i].id, nodes[i].voltage);
    }
}

int main() {
    create_component(1, 1.0);
    create_component(2, 2.0);
    create_node(1, 5.0);
    create_node(2, 0.0);
    create_link(1, 2, 3.0);
    simulate();
    print_nodes();
    return 0;
}