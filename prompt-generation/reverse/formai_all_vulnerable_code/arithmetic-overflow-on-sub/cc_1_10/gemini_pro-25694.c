//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes and edges in the circuit
#define MAX_NODES 100
#define MAX_EDGES 200

// Define the types of nodes and edges
typedef enum {
    NODE_TYPE_INPUT,
    NODE_TYPE_OUTPUT,
    NODE_TYPE_AND,
    NODE_TYPE_OR,
    NODE_TYPE_NOT
} node_type;

typedef struct {
    int id;
    node_type type;
    int num_inputs;
    int *inputs;
    int output;
} node;

typedef struct {
    int id;
    int from;
    int to;
} edge;

// Define the circuit structure
typedef struct {
    int num_nodes;
    node *nodes;
    int num_edges;
    edge *edges;
} circuit;

// Create a new circuit
circuit *create_circuit() {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = 0;
    c->nodes = NULL;
    c->num_edges = 0;
    c->edges = NULL;
    return c;
}

// Add a node to the circuit
void add_node(circuit *c, node_type type, int num_inputs, int *inputs, int output) {
    // Create a new node
    node *n = malloc(sizeof(node));
    n->id = c->num_nodes++;
    n->type = type;
    n->num_inputs = num_inputs;
    n->inputs = inputs;
    n->output = output;

    // Add the node to the circuit
    c->nodes = realloc(c->nodes, c->num_nodes * sizeof(node));
    c->nodes[c->num_nodes - 1] = *n;
}

// Add an edge to the circuit
void add_edge(circuit *c, int from, int to) {
    // Create a new edge
    edge *e = malloc(sizeof(edge));
    e->id = c->num_edges++;
    e->from = from;
    e->to = to;

    // Add the edge to the circuit
    c->edges = realloc(c->edges, c->num_edges * sizeof(edge));
    c->edges[c->num_edges - 1] = *e;
}

// Free the memory allocated for the circuit
void free_circuit(circuit *c) {
    // Free the nodes
    for (int i = 0; i < c->num_nodes; i++) {
        free(c->nodes[i].inputs);
    }
    free(c->nodes);

    // Free the edges
    free(c->edges);

    // Free the circuit
    free(c);
}

// Simulate the circuit
void simulate_circuit(circuit *c) {
    // Initialize the node outputs to 0
    for (int i = 0; i < c->num_nodes; i++) {
        c->nodes[i].output = 0;
    }

    // Iterate over the edges in the circuit
    for (int i = 0; i < c->num_edges; i++) {
        edge *e = &c->edges[i];

        // Get the source and destination nodes
        node *src_node = &c->nodes[e->from];
        node *dst_node = &c->nodes[e->to];

        // Calculate the output of the source node
        int src_output = 0;
        switch (src_node->type) {
            case NODE_TYPE_INPUT:
                src_output = src_node->output;
                break;
            case NODE_TYPE_OUTPUT:
                src_output = dst_node->output;
                break;
            case NODE_TYPE_AND:
                for (int j = 0; j < src_node->num_inputs; j++) {
                    src_output &= c->nodes[src_node->inputs[j]].output;
                }
                break;
            case NODE_TYPE_OR:
                for (int j = 0; j < src_node->num_inputs; j++) {
                    src_output |= c->nodes[src_node->inputs[j]].output;
                }
                break;
            case NODE_TYPE_NOT:
                src_output = !src_node->output;
                break;
        }

        // Set the output of the destination node
        dst_node->output = src_output;
    }
}

// Print the circuit
void print_circuit(circuit *c) {
    // Print the nodes
    printf("Nodes:\n");
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = &c->nodes[i];
        printf("  Node %d: type %d, num_inputs %d, inputs ", n->id, n->type, n->num_inputs);
        for (int j = 0; j < n->num_inputs; j++) {
            printf("%d ", n->inputs[j]);
        }
        printf(", output %d\n", n->output);
    }

    // Print the edges
    printf("Edges:\n");
    for (int i = 0; i < c->num_edges; i++) {
        edge *e = &c->edges[i];
        printf("  Edge %d: from %d to %d\n", e->id, e->from, e->to);
    }
}

// Main function
int main() {
    // Create a new circuit
    circuit *c = create_circuit;

    // Add nodes to the circuit
    add_node(c, NODE_TYPE_INPUT, 0, NULL, 0);
    add_node(c, NODE_TYPE_INPUT, 0, NULL, 1);
    add_node(c, NODE_TYPE_AND, 2, (int[]){0, 1}, 2);
    add_node(c, NODE_TYPE_OUTPUT, 1, (int[]){2}, 3);
    add_node(c, NODE_TYPE_OR, 2, (int[]){0, 1}, 4);
    add_node(c, NODE_TYPE_NOT, 1, (int[]){4}, 5);
    add_node(c, NODE_TYPE_OUTPUT, 1, (int[]){5}, 6);

    // Add edges to the circuit
    add_edge(c, 0, 2);
    add_edge(c, 1, 2);
    add_edge(c, 2, 3);
    add_edge(c, 0, 4);
    add_edge(c, 1, 4);
    add_edge(c, 4, 5);
    add_edge(c, 5, 6);

    // Print the circuit
    print_circuit(c);

    // Simulate the circuit
    simulate_circuit(c);

    // Print the output of the circuit
    printf("Output:\n");
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = &c->nodes[i];
        if (n->type == NODE_TYPE_OUTPUT) {
            printf("  Node %d: output %d\n", n->id, n->output);
        }
    }

    // Free the memory allocated for the circuit
    free_circuit(c);

    return 0;
}