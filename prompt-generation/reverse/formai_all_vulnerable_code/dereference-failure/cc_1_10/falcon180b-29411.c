//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000

typedef struct {
    int type;
    int node1;
    int node2;
    double value;
} Component;

typedef struct {
    int num_nodes;
    int *nodes;
    double *values;
} Node;

Node *create_node(int num_nodes) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->num_nodes = num_nodes;
    node->nodes = (int *)malloc(sizeof(int) * num_nodes);
    node->values = (double *)malloc(sizeof(double) * num_nodes);
    return node;
}

void destroy_node(Node *node) {
    free(node->nodes);
    free(node->values);
    free(node);
}

int add_component(Component *components, int num_components, int type, int node1, int node2, double value) {
    for (int i = 0; i < num_components; i++) {
        if (components[i].type == type && components[i].node1 == node1 && components[i].node2 == node2) {
            components[i].value += value;
            return 0;
        }
    }
    if (num_components >= MAX_COMPONENTS) {
        return -1;
    }
    components[num_components].type = type;
    components[num_components].node1 = node1;
    components[num_components].node2 = node2;
    components[num_components].value = value;
    return num_components + 1;
}

void solve(Node *nodes, Component *components, int num_nodes, int num_components) {
    double *values = nodes->values;
    for (int i = 0; i < num_nodes; i++) {
        values[i] = 0;
    }
    for (int i = 0; i < num_components; i++) {
        int node1 = components[i].node1;
        int node2 = components[i].node2;
        double value = components[i].value;
        values[node1] -= value;
        values[node2] += value;
    }
    for (int i = 0; i < num_nodes; i++) {
        int node1 = nodes->nodes[i];
        for (int j = 0; j < num_nodes; j++) {
            int node2 = nodes->nodes[j];
            double value = values[node1] - values[node2];
            if (value!= 0) {
                printf("Node %d and %d have a potential difference of %lf V\n", node1, node2, value);
            }
        }
    }
}

int main() {
    int num_nodes = 5;
    int num_components = 0;
    Node *nodes = create_node(num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        nodes->nodes[i] = i;
    }
    add_component(NULL, 0, 1, 0, 1, 10);
    add_component(NULL, 0, 2, 1, 2, 20);
    add_component(NULL, 0, 3, 2, 3, 30);
    add_component(NULL, 0, 4, 3, 4, 40);
    solve(nodes, NULL, num_nodes, num_components);
    destroy_node(nodes);
    return 0;
}