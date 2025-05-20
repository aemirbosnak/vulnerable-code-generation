//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int node1;
    int node2;
    double resistance;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Circuit;

Circuit* create_circuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->num_nodes = 0;
    circuit->num_edges = 0;
    return circuit;
}

void add_node(Circuit* circuit) {
    circuit->num_nodes++;
}

void add_edge(Circuit* circuit, int node1, int node2, double resistance) {
    Edge edge = {node1, node2, resistance};
    circuit->edges[circuit->num_edges++] = edge;
}

void print_circuit(Circuit* circuit) {
    printf("Circuit:\n");
    printf("Nodes: %d\n", circuit->num_nodes);
    printf("Edges: %d\n", circuit->num_edges);
    for (int i = 0; i < circuit->num_edges; i++) {
        printf("Edge %d: (%d, %d) -> %g\n", i + 1, circuit->edges[i].node1, circuit->edges[i].node2, circuit->edges[i].resistance);
    }
}

void destroy_circuit(Circuit* circuit) {
    free(circuit);
}

int main() {
    Circuit* circuit = create_circuit();
    add_node(circuit);
    add_node(circuit);
    add_edge(circuit, 0, 1, 10.0);
    print_circuit(circuit);
    destroy_circuit(circuit);
    return 0;
}