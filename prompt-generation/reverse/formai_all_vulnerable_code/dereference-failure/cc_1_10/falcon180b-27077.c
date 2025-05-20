//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_COMPONENTS 100
#define MAX_NODES 1000

typedef struct {
    double value;
    int node1;
    int node2;
} Component;

typedef struct {
    double value;
    int node;
} Node;

int num_components;
int num_nodes;

Node *nodes;
Component *components;

void init() {
    srand(time(NULL));
    nodes = (Node *)malloc(MAX_NODES * sizeof(Node));
    components = (Component *)malloc(MAX_COMPONENTS * sizeof(Component));
    num_components = 0;
    num_nodes = 0;
}

void create_node(double value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->node = num_nodes;
    nodes[num_nodes] = *node;
    num_nodes++;
}

void create_component(int node1, int node2, double value) {
    Component *component = (Component *)malloc(sizeof(Component));
    component->value = value;
    component->node1 = node1;
    component->node2 = node2;
    components[num_components] = *component;
    num_components++;
}

void connect_nodes(int node1, int node2) {
    create_component(node1, node2, 1.0);
    create_component(node2, node1, 1.0);
}

void simulate() {
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].value = 0.0;
    }

    for (int i = 0; i < num_components; i++) {
        Component *component = &components[i];
        Node *node1 = &nodes[component->node1];
        Node *node2 = &nodes[component->node2];

        node1->value += node2->value * component->value;
        node2->value += node1->value * component->value;
    }
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %.4f\n", i, nodes[i].value);
    }
}

int main() {
    init();

    create_node(5.0);
    create_node(10.0);

    connect_nodes(0, 1);

    simulate();

    print_nodes();

    return 0;
}