//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

/* Circuit node structure */
typedef struct circuit_node {
    int id; /* Node id */
    int type; /* Node type: 0 for not gate, 1 for and gate */
    int inputs[2]; /* Input nodes */
    int output; /* Output node */
} CircuitNode;

/* Function to simulate a not gate */
int not_gate(int input) {
    return !input;
}

/* Function to simulate an and gate */
int and_gate(int input1, int input2) {
    return input1 && input2;
}

/* Function to simulate the circuit */
int simulate_circuit(CircuitNode* circuit, int num_nodes, int* input_values) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        CircuitNode node = circuit[i];
        if (node.type == 0) {
            /* Not gate */
            circuit[node.output].output = not_gate(input_values[node.inputs[0]]);
        } else {
            /* And gate */
            circuit[node.output].output = and_gate(input_values[node.inputs[0]], input_values[node.inputs[1]]);
        }
    }
    /* Return the output of the last node in the circuit */
    return circuit[num_nodes-1].output;
}

int main() {
    /* Define the circuit */
    CircuitNode circuit[5];
    circuit[0].id = 0;
    circuit[0].type = 0;
    circuit[0].inputs[0] = 1;
    circuit[0].output = 2;
    circuit[1].id = 1;
    circuit[1].type = 1;
    circuit[1].inputs[0] = 3;
    circuit[1].inputs[1] = 4;
    circuit[1].output = 2;
    circuit[2].id = 2;
    circuit[2].type = 0;
    circuit[2].inputs[0] = 1;
    circuit[2].output = 5;
    circuit[3].id = 3;
    circuit[3].type = 0;
    circuit[3].inputs[0] = 0;
    circuit[3].output = 4;
    circuit[4].id = 4;
    circuit[4].type = 0;
    circuit[4].inputs[0] = 1;
    circuit[4].output = 5;
    circuit[5].id = 5;
    circuit[5].type = 1;
    circuit[5].inputs[0] = 2;
    circuit[5].inputs[1] = 4;
    circuit[5].output = 6;
    /* Define input values */
    int input_values[2];
    input_values[0] = 1;
    input_values[1] = 0;
    /* Simulate circuit with inputs */
    int output = simulate_circuit(circuit, 6, input_values);
    /* Print output */
    printf("Output of circuit with inputs %d and %d is %d\n", input_values[0], input_values[1], output);
    return 0;
}