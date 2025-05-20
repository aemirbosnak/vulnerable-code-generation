//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int node1;
    int node2;
    double value;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Circuit;

void add_edge(Circuit* circuit, int node1, int node2, double value) {
    Edge* edge = &circuit->edges[circuit->num_edges];
    edge->node1 = node1;
    edge->node2 = node2;
    edge->value = value;
    circuit->num_edges++;
}

void simulate(Circuit* circuit) {
    double voltages[MAX_NODES];
    for (int i = 0; i < circuit->num_nodes; i++) {
        voltages[i] = 0;
    }

    for (int i = 0; i < circuit->num_edges; i++) {
        Edge edge = circuit->edges[i];
        double current = (voltages[edge.node1] - voltages[edge.node2]) / edge.value;
        voltages[edge.node1] -= current;
        voltages[edge.node2] += current;
    }

    printf("Node\tVoltage\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("%d\t%.2f\n", i, voltages[i]);
    }
}

int main() {
    Circuit circuit;
    circuit.num_nodes = 3;
    circuit.num_edges = 2;

    add_edge(&circuit, 0, 1, 10);
    add_edge(&circuit, 1, 2, 20);

    simulate(&circuit);

    return 0;
}