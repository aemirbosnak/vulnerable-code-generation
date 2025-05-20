//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Define the types of gates
typedef enum { AND, OR, NOT } GateType;

// Define the structure of a gate
typedef struct {
    GateType type;
    int num_inputs;
    int *inputs;
    int output;
} Gate;

// Define the structure of a circuit
typedef struct {
    int num_gates;
    Gate *gates;
} Circuit;

// Create a new gate
Gate *create_gate(GateType type, int num_inputs) {
    Gate *gate = malloc(sizeof(Gate));
    gate->type = type;
    gate->num_inputs = num_inputs;
    gate->inputs = malloc(sizeof(int) * num_inputs);
    gate->output = -1;
    return gate;
}

// Create a new circuit
Circuit *create_circuit(int num_gates) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->num_gates = num_gates;
    circuit->gates = malloc(sizeof(Gate) * num_gates);
    return circuit;
}

// Connect the output of one gate to the input of another gate
void connect_gates(Gate *gate1, int output_index, Gate *gate2, int input_index) {
    gate2->inputs[input_index] = gate1->output;
}

// Evaluate the output of a gate
int evaluate_gate(Gate *gate) {
    switch (gate->type) {
        case AND:
            gate->output = 1;
            for (int i = 0; i < gate->num_inputs; i++) {
                if (gate->inputs[i] == 0) {
                    gate->output = 0;
                    break;
                }
            }
            break;
        case OR:
            gate->output = 0;
            for (int i = 0; i < gate->num_inputs; i++) {
                if (gate->inputs[i] == 1) {
                    gate->output = 1;
                    break;
                }
            }
            break;
        case NOT:
            gate->output = !gate->inputs[0];
            break;
    }
    return gate->output;
}

// Evaluate the output of a circuit
int evaluate_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_gates; i++) {
        evaluate_gate(&circuit->gates[i]);
    }
    return circuit->gates[circuit->num_gates - 1].output;
}

// Print the truth table of a circuit
void print_truth_table(Circuit *circuit) {
    int num_inputs = circuit->gates[0].num_inputs;
    int num_rows = 1 << num_inputs;
    int *inputs = malloc(sizeof(int) * num_inputs);
    for (int i = 0; i < num_rows; i++) {
        // Set the input values
        for (int j = 0; j < num_inputs; j++) {
            inputs[j] = (i >> j) & 1;
        }
        // Evaluate the circuit
        int output = evaluate_circuit(circuit);
        // Print the input and output values
        printf("%d", inputs[0]);
        for (int j = 1; j < num_inputs; j++) {
            printf(", %d", inputs[j]);
        }
        printf(" -> %d\n", output);
    }
    free(inputs);
}

int main() {
    // Create a circuit
    Circuit *circuit = create_circuit(4);

    // Create the gates
    Gate *gate1 = create_gate(AND, 2);
    Gate *gate2 = create_gate(OR, 2);
    Gate *gate3 = create_gate(NOT, 1);
    Gate *gate4 = create_gate(AND, 2);

    // Connect the gates
    connect_gates(gate1, 0, gate4, 0);
    connect_gates(gate2, 0, gate4, 1);
    connect_gates(gate3, 0, gate2, 1);

    // Print the truth table
    print_truth_table(circuit);

    // Free the memory
    free(circuit->gates);
    free(circuit);
    free(gate1);
    free(gate2);
    free(gate3);
    free(gate4);

    return 0;
}