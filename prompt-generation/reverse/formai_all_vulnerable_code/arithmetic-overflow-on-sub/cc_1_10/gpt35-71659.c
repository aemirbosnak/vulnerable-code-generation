//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdlib.h>
#include <stdio.h>

#define MAX_NODES 100

/* Define a node structure */
typedef struct node {
    int id;
    int type;
    double value;
    struct node* next;
} Node;

/* Define a circuit structure */
typedef struct circuit {
    Node* node_list[MAX_NODES];
    int num_nodes;
} Circuit;

/* Function to create a new node */
Node* create_node(int id, int type, double value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->id = id;
    node->type = type;
    node->value = value;
    node->next = NULL;
    return node;
}

/* Function to add a node to the circuit */
void add_node(Circuit* circuit, Node* node) {
    if (circuit->num_nodes == MAX_NODES) {
        printf("Error: Maximum number of nodes exceeded.\n");
        return;
    }
    circuit->node_list[circuit->num_nodes++] = node;
}

/* Function to simulate the circuit */
void simulate(Circuit* circuit) {
    double time = 0.0;
    double step = 0.01;
    while (time < 10.0) {
        /* Update node values */
        Node* node = circuit->node_list[0];
        while (node != NULL) {
            switch (node->type) {
                case 0: /* Resistor */
                    /* Calculate current from voltage and resistance */
                    node->value = circuit->node_list[node->id - 1]->value / 10;
                    break;
                case 1: /* Capacitor */
                    /* Calculate voltage from current and capacitance */
                    node->value += (circuit->node_list[node->id - 1]->value - node->value) / 10;
                    break;
                case 2: /* Voltage Source */
                    /* Set voltage to 5V */
                    node->value = 5.0;
                    break;
            }
            node = node->next;
        }
        /* Print node voltages */
        printf("t = %f: V1 = %f, V2 = %f\n",
                time, circuit->node_list[0]->value, circuit->node_list[1]->value);
        time += step;
    }
}

int main() {
    /* Create circuit */
    Circuit circuit;
    circuit.num_nodes = 0;
    /* Add nodes */
    add_node(&circuit, create_node(0, 2, 0.0)); /* Voltage Source */
    add_node(&circuit, create_node(1, 0, 0.0)); /* Resistor */
    add_node(&circuit, create_node(2, 1, 0.0)); /* Capacitor */
    /* Connect nodes */
    circuit.node_list[0]->next = circuit.node_list[1];
    circuit.node_list[1]->next = circuit.node_list[2];
    /* Simulate circuit */
    simulate(&circuit);
    /* Free memory */
    Node* node = circuit.node_list[0];
    while (node != NULL) {
        Node* next = node->next;
        free(node);
        node = next;
    }
    return 0;
}