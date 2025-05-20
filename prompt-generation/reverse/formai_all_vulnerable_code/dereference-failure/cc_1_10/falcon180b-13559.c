//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int value;
    int num_inputs;
    struct node **inputs;
} Node;

// Function prototypes
Node *create_node(int value);
void delete_node(Node *node);
void connect_nodes(Node *node1, Node *node2);
void simulate_circuit(Node *output_node);

int main() {
    Node *input1 = create_node(1);
    Node *input2 = create_node(2);
    Node *and_gate = create_node(0);
    Node *or_gate = create_node(0);

    connect_nodes(input1, and_gate);
    connect_nodes(input2, and_gate);
    connect_nodes(and_gate, or_gate);

    simulate_circuit(or_gate);

    delete_node(input1);
    delete_node(input2);
    delete_node(and_gate);
    delete_node(or_gate);

    return 0;
}

// Create a new node with the given value
Node *create_node(int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->num_inputs = 0;
    new_node->inputs = NULL;

    return new_node;
}

// Delete a node and all its connections
void delete_node(Node *node) {
    if (node == NULL) {
        return;
    }

    if (node->inputs!= NULL) {
        int i;
        for (i = 0; i < node->num_inputs; i++) {
            delete_node(node->inputs[i]);
        }
        free(node->inputs);
    }

    free(node);
}

// Connect two nodes
void connect_nodes(Node *node1, Node *node2) {
    if (node1 == NULL || node2 == NULL) {
        return;
    }

    if (node1->inputs == NULL) {
        node1->inputs = (Node **) malloc(sizeof(Node *));
        node1->num_inputs = 1;
    } else {
        node1->inputs = (Node **) realloc(node1->inputs, sizeof(Node *) * (node1->num_inputs + 1));
        node1->num_inputs++;
    }

    node1->inputs[node1->num_inputs - 1] = node2;
}

// Simulate the circuit starting from the given node
void simulate_circuit(Node *node) {
    if (node == NULL) {
        return;
    }

    int i;
    for (i = 0; i < node->num_inputs; i++) {
        simulate_circuit(node->inputs[i]);
    }

    node->value = 0;
}