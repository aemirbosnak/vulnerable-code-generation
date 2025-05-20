//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdio.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 200
#define MAX_BRANCHES 200

typedef struct {
    int node1;
    int node2;
    double resistance;
} Branch;

typedef struct {
    int node;
    double voltage;
} Node;

int num_components;
int num_nodes;
int num_branches;
int *component_nodes;
Node *node_voltages;
Branch *branches;

void add_component(int node1, int node2, double resistance) {
    num_components++;
    branches = realloc(branches, sizeof(Branch) * num_components);
    branches[num_components - 1].node1 = node1;
    branches[num_components - 1].node2 = node2;
    branches[num_components - 1].resistance = resistance;
}

int get_node_index(int node) {
    for (int i = 0; i < num_nodes; i++) {
        if (node_voltages[i].node == node) {
            return i;
        }
    }
    num_nodes++;
    component_nodes = realloc(component_nodes, sizeof(int) * num_nodes);
    component_nodes[num_nodes - 1] = node;
    node_voltages = realloc(node_voltages, sizeof(Node) * num_nodes);
    node_voltages[num_nodes - 1].node = node;
    node_voltages[num_nodes - 1].voltage = 0;
    return num_nodes - 1;
}

void solve() {
    for (int i = 0; i < num_nodes; i++) {
        node_voltages[i].voltage = 0;
    }
    for (int i = 0; i < num_components; i++) {
        int node1 = get_node_index(branches[i].node1);
        int node2 = get_node_index(branches[i].node2);
        node_voltages[node1].voltage -= node_voltages[node2].voltage;
        node_voltages[node2].voltage += node_voltages[node1].voltage;
    }
}

void print_solution() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %.2fV\n", component_nodes[i], node_voltages[i].voltage);
    }
}

int main() {
    num_components = 0;
    num_nodes = 0;
    num_branches = 0;
    component_nodes = NULL;
    node_voltages = NULL;
    branches = NULL;

    // Example circuit
    add_component(0, 1, 100);
    add_component(1, 2, 200);
    add_component(2, 0, 300);

    solve();
    print_solution();

    return 0;
}