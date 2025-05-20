//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_components 100
#define max_nodes 100
#define max_edges 200

typedef struct {
    int node1;
    int node2;
    double resistance;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[max_edges];
} Circuit;

void add_edge(Circuit *circuit, int node1, int node2, double resistance) {
    Edge *new_edge = &circuit->edges[circuit->num_edges];
    new_edge->node1 = node1;
    new_edge->node2 = node2;
    new_edge->resistance = resistance;
    circuit->num_edges++;
}

void print_circuit(Circuit *circuit) {
    printf("Circuit:\n");
    printf("Num Nodes: %d\n", circuit->num_nodes);
    printf("Num Edges: %d\n", circuit->num_edges);
    for (int i = 0; i < circuit->num_edges; i++) {
        printf("Edge %d: (%d, %d) - %.2f Ohms\n", i+1, circuit->edges[i].node1, circuit->edges[i].node2, circuit->edges[i].resistance);
    }
}

void calculate_currents(Circuit *circuit, double *currents, double voltage) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        currents[i] = 0;
    }
    for (int i = 0; i < circuit->num_edges; i++) {
        int node1 = circuit->edges[i].node1;
        int node2 = circuit->edges[i].node2;
        currents[node1] += (circuit->edges[i].resistance / voltage) * (currents[node2] - currents[node1]);
    }
}

int main() {
    Circuit circuit;
    circuit.num_nodes = 3;
    circuit.num_edges = 2;
    add_edge(&circuit, 0, 1, 10);
    add_edge(&circuit, 1, 2, 20);
    double currents[circuit.num_nodes];
    double voltage = 12;
    calculate_currents(&circuit, currents, voltage);
    print_circuit(&circuit);
    printf("Currents:\n");
    for (int i = 0; i < circuit.num_nodes; i++) {
        printf("Node %d: %.2f Amps\n", i+1, currents[i]);
    }
    return 0;
}