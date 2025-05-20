//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int from, to;
    double weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge* edges;
} Circuit;

void add_edge(Circuit* circuit, int from, int to, double weight) {
    if (circuit->num_edges == MAX_EDGES) {
        printf("Error: maximum number of edges reached\n");
        return;
    }

    circuit->edges[circuit->num_edges].from = from;
    circuit->edges[circuit->num_edges].to = to;
    circuit->edges[circuit->num_edges].weight = weight;
    circuit->num_edges++;
}

double calculate_resistance(Circuit* circuit) {
    double total_resistance = 0.0;

    for (int i = 0; i < circuit->num_edges; i++) {
        double weight = circuit->edges[i].weight;
        total_resistance += weight * weight;
    }

    return total_resistance;
}

int main() {
    Circuit circuit;
    circuit.num_nodes = 0;
    circuit.num_edges = 0;
    circuit.edges = NULL;

    int nodes[MAX_NODES];
    int edges[MAX_EDGES][3];
    double weights[MAX_EDGES];

    printf("Enter the number of nodes: ");
    int num_nodes_input = scanf("%d", &circuit.num_nodes);
    if (num_nodes_input!= 1) {
        printf("Invalid number of nodes\n");
        return 1;
    }

    for (int i = 0; i < circuit.num_nodes; i++) {
        nodes[i] = i;
    }

    printf("Enter the number of edges: ");
    int num_edges_input = scanf("%d", &circuit.num_edges);
    if (num_edges_input!= 1) {
        printf("Invalid number of edges\n");
        return 1;
    }

    for (int i = 0; i < circuit.num_edges; i++) {
        printf("Enter from node: ");
        scanf("%d", &edges[i][0]);
        printf("Enter to node: ");
        scanf("%d", &edges[i][1]);
        printf("Enter weight: ");
        scanf("%lf", &weights[i]);
    }

    for (int i = 0; i < circuit.num_nodes; i++) {
        add_edge(&circuit, nodes[i], i, 0.0);
    }

    for (int i = 0; i < circuit.num_edges; i++) {
        add_edge(&circuit, edges[i][0], edges[i][1], weights[i]);
    }

    double resistance = calculate_resistance(&circuit);
    printf("Total resistance: %lf\n", resistance);

    return 0;
}