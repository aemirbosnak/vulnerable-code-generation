//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Node structure
typedef struct node {
    double value;
    struct node *next;
} Node;

// Circuit structure
typedef struct circuit {
    Node *nodes;
    int num_nodes;
} Circuit;

// Function prototypes
void add_node(Circuit *circuit);
void connect_nodes(Circuit *circuit, int node1, int node2);
void simulate_circuit(Circuit *circuit, double input);

// Main function
int main() {
    Circuit circuit;
    circuit.nodes = NULL;
    circuit.num_nodes = 0;

    // Add nodes
    add_node(&circuit);
    add_node(&circuit);
    add_node(&circuit);
    add_node(&circuit);

    // Connect nodes
    connect_nodes(&circuit, 0, 1);
    connect_nodes(&circuit, 1, 2);
    connect_nodes(&circuit, 2, 3);

    // Simulate circuit
    simulate_circuit(&circuit, 1.0);

    return 0;
}

// Add a node to the circuit
void add_node(Circuit *circuit) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = 0.0;
    node->next = NULL;

    if (circuit->nodes == NULL) {
        circuit->nodes = node;
    } else {
        Node *temp = circuit->nodes;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }

    circuit->num_nodes++;
}

// Connect two nodes in the circuit
void connect_nodes(Circuit *circuit, int node1, int node2) {
    Node *node1_ptr = circuit->nodes;
    Node *node2_ptr = circuit->nodes;

    for (int i = 0; i < node1; i++) {
        node1_ptr = node1_ptr->next;
    }

    for (int i = 0; i < node2; i++) {
        node2_ptr = node2_ptr->next;
    }

    node1_ptr->next = node2_ptr;
}

// Simulate the circuit given an input voltage
void simulate_circuit(Circuit *circuit, double input) {
    Node *node = circuit->nodes;

    while (node!= NULL) {
        node->value = input;
        node = node->next;
    }
}