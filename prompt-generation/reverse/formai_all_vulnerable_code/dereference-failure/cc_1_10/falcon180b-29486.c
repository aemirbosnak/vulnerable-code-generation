//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 1000
#define MAX_NODES 2000
#define MAX_EDGES 2000

typedef struct component {
    int num_nodes;
    int *nodes;
    float *values;
} Component;

typedef struct circuit {
    int num_components;
    Component *components;
} Circuit;

Circuit *create_circuit() {
    Circuit *circuit = (Circuit *) malloc(sizeof(Circuit));
    circuit->num_components = 0;
    circuit->components = NULL;
    return circuit;
}

void add_component(Circuit *circuit, int num_nodes, int *nodes, float *values) {
    Component *component = (Component *) malloc(sizeof(Component));
    component->num_nodes = num_nodes;
    component->nodes = nodes;
    component->values = values;
    circuit->components = realloc(circuit->components, sizeof(Component) * (circuit->num_components + 1));
    circuit->components[circuit->num_components++] = *component;
}

void simulate_circuit(Circuit *circuit) {
    int i, j, k;
    for (i = 0; i < circuit->num_components; i++) {
        Component *component = &circuit->components[i];
        for (j = 0; j < component->num_nodes; j++) {
            int node_index = component->nodes[j];
            float value = component->values[j];
            for (k = 0; k < circuit->num_components; k++) {
                if (k == i)
                    continue;
                Component *other_component = &circuit->components[k];
                int other_node_index = other_component->nodes[0];
                if (other_node_index == node_index) {
                    value += other_component->values[0];
                }
            }
            printf("Node %d has a voltage of %.2f\n", node_index, value);
        }
    }
}

int main() {
    Circuit *circuit = create_circuit();
    add_component(circuit, 2, (int []) {0, 1}, (float []) {1.0, -1.0});
    add_component(circuit, 3, (int []) {1, 2, 0}, (float []) {1.0, 1.0, -2.0});
    simulate_circuit(circuit);
    free(circuit->components);
    free(circuit);
    return 0;
}