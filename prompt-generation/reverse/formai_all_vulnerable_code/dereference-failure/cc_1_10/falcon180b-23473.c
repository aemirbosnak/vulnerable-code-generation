//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 200

typedef struct {
    int num_nodes;
    double value;
    int *node_indices;
} Component;

typedef struct {
    int num_components;
    Component *components;
} Circuit;

Circuit *create_circuit() {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->num_components = 0;
    circuit->components = (Component *)malloc(MAX_COMPONENTS * sizeof(Component));
    return circuit;
}

void add_component(Circuit *circuit, int num_nodes, double value, int *node_indices) {
    if (circuit->num_components >= MAX_COMPONENTS) {
        printf("Error: Maximum number of components reached.\n");
        exit(1);
    }
    Component component;
    component.num_nodes = num_nodes;
    component.value = value;
    component.node_indices = (int *)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        component.node_indices[i] = node_indices[i];
    }
    circuit->components[circuit->num_components++] = component;
}

void simulate_circuit(Circuit *circuit, double *node_voltages) {
    for (int i = 0; i < circuit->num_components; i++) {
        Component component = circuit->components[i];
        double sum = 0.0;
        for (int j = 0; j < component.num_nodes; j++) {
            int node_index = component.node_indices[j];
            sum += node_voltages[node_index] * component.value;
        }
        node_voltages[component.node_indices[0]] = sum;
    }
}

int main() {
    Circuit *circuit = create_circuit();
    int num_nodes = 3;
    int node_indices[3] = {0, 1, 2};
    double node_voltages[3] = {1.0, 0.0, 0.0};
    add_component(circuit, num_nodes, 1.0, node_indices);
    add_component(circuit, num_nodes, 2.0, node_indices);
    add_component(circuit, num_nodes, 3.0, node_indices);
    simulate_circuit(circuit, node_voltages);
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d voltage: %lf\n", i, node_voltages[i]);
    }
    free(circuit->components);
    free(circuit);
    return 0;
}