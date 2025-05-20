//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: configurable
// A C program to simulate a classical circuit.
// The circuit is described by a netlist file.
// The netlist file is parsed and a graph is created to represent the circuit.
// The graph is then simulated using a modified version of the Gauss-Seidel method.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the graph.
typedef struct node {
    char *name;
    int num_inputs;
    int *inputs;
    int output;
} node;

// A graph representing a circuit.
typedef struct graph {
    int num_nodes;
    node *nodes;
} graph;

// Parses a netlist file and creates a graph representing the circuit.
graph *parse_netlist(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the number of nodes in the circuit.
    int num_nodes;
    fscanf(fp, "%d", &num_nodes);

    // Create a graph to represent the circuit.
    graph *g = malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->nodes = malloc(sizeof(node) * num_nodes);

    // Read the nodes from the netlist file.
    for (int i = 0; i < num_nodes; i++) {
        node *n = &g->nodes[i];

        // Read the node's name.
        char name[256];
        fscanf(fp, "%s", name);
        n->name = strdup(name);

        // Read the number of inputs to the node.
        fscanf(fp, "%d", &n->num_inputs);

        // Read the node's inputs.
        n->inputs = malloc(sizeof(int) * n->num_inputs);
        for (int j = 0; j < n->num_inputs; j++) {
            fscanf(fp, "%d", &n->inputs[j]);
        }

        // Read the node's output.
        fscanf(fp, "%d", &n->output);
    }

    fclose(fp);

    return g;
}

// Simulates a graph representing a circuit using a modified version of the Gauss-Seidel method.
void simulate(graph *g) {
    // Initialize the node outputs to 0.
    for (int i = 0; i < g->num_nodes; i++) {
        g->nodes[i].output = 0;
    }

    // Iterate over the nodes until the outputs converge.
    int converged = 0;
    while (!converged) {
        converged = 1;

        // Iterate over the nodes.
        for (int i = 0; i < g->num_nodes; i++) {
            node *n = &g->nodes[i];

            // Calculate the node's output.
            int output = 0;
            for (int j = 0; j < n->num_inputs; j++) {
                output += g->nodes[n->inputs[j]].output;
            }

            // Update the node's output if it has changed.
            if (output != n->output) {
                n->output = output;
                converged = 0;
            }
        }
    }
}

// Prints the outputs of the nodes in a graph.
void print_outputs(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *n = &g->nodes[i];

        printf("%s: %d\n", n->name, n->output);
    }
}

// Frees the memory allocated for a graph.
void free_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        free(g->nodes[i].name);
        free(g->nodes[i].inputs);
    }
    free(g->nodes);
    free(g);
}

// The main function.
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <netlist file>\n", argv[0]);
        return 1;
    }

    // Parse the netlist file.
    graph *g = parse_netlist(argv[1]);
    if (g == NULL) {
        return 1;
    }

    // Simulate the circuit.
    simulate(g);

    // Print the outputs of the nodes.
    print_outputs(g);

    // Free the memory allocated for the graph.
    free_graph(g);

    return 0;
}