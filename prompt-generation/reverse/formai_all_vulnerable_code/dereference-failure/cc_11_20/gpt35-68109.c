//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GATES 10 // Maximum number of gates in the circuit
#define BUF_SIZE 1024 // Maximum length of input string

// Structure for a gate
typedef struct {
    char type; // Type of gate (I for input, O for output, A for AND, O for OR, X for XOR)
    int input1; // Index of first input wire (-1 for input gates and output gates)
    int input2; // Index of second input wire (-1 for input gates and output gates)
    int output; // Index of output wire (-1 for output gates)
    int delay; // Propagation delay of the gate
} gate;

// Global variables
int num_inputs, num_outputs, num_gates, max_delay;
int output_wires[MAX_GATES];
int input_wires[MAX_GATES];
gate gates[MAX_GATES];

// Function to simulate the circuit
void simulate(int input_values[]) {
    int i, j, k;
    int values[MAX_GATES]; // Current values on the wires
    int new_values[MAX_GATES]; // Updated values on the wires

    for (i = 0; i < num_inputs; i++) {
        values[input_wires[i]] = input_values[i];
    }

    for (i = 0; i <= max_delay; i++) {
        for (j = 0; j < num_gates; j++) {
            if (gates[j].delay == i) {
                // Evaluate the gate
                switch (gates[j].type) {
                    case 'A':
                        new_values[gates[j].output] = values[gates[j].input1] && values[gates[j].input2];
                        break;
                    case 'O':
                        new_values[gates[j].output] = values[gates[j].input1] || values[gates[j].input2];
                        break;
                    case 'X':
                        new_values[gates[j].output] = values[gates[j].input1] ^ values[gates[j].input2];
                        break;
                }
            }
        }

        // Update the wire values
        for (k = 0; k < num_gates; k++) {
            if (gates[k].delay == i) {
                values[gates[k].output] = new_values[gates[k].output];
            }
        }
    }

    // Print the output values
    for (i = 0; i < num_outputs; i++) {
        printf("%d ", values[output_wires[i]]);
    }
    printf("\n");
}

int main() {
    int i, j;
    char buf[BUF_SIZE];
    char *tok;

    // Read in the input
    fgets(buf, BUF_SIZE, stdin);
    sscanf(buf, "%d %d %d", &num_inputs, &num_outputs, &num_gates);

    fgets(buf, BUF_SIZE, stdin);
    tok = strtok(buf, " ");
    for (i = 0; i < num_inputs; i++) {
        input_wires[i] = atoi(tok);
        tok = strtok(NULL, " ");
    }

    fgets(buf, BUF_SIZE, stdin);
    tok = strtok(buf, " ");
    for (i = 0; i < num_outputs; i++) {
        output_wires[i] = atoi(tok);
        tok = strtok(NULL, " ");
    }

    max_delay = 0;
    for (i = 0; i < num_gates; i++) {
        fgets(buf, BUF_SIZE, stdin);
        tok = strtok(buf, " ");
        gates[i].type = tok[0];

        tok = strtok(NULL, " ");
        gates[i].input1 = atoi(tok);

        tok = strtok(NULL, " ");
        if (tok != NULL) {
            gates[i].input2 = atoi(tok);
        } else {
            gates[i].input2 = -1;
        }

        tok = strtok(NULL, " ");
        gates[i].output = atoi(tok);

        tok = strtok(NULL, " ");
        gates[i].delay = atoi(tok);

        if (gates[i].delay > max_delay) {
            max_delay = gates[i].delay;
        }
    }

    // Simulate the circuit for all possible input values
    int num_simulations = 1 << num_inputs;
    for (i = 0; i < num_simulations; i++) {
        int input_values[num_inputs];

        for (j = 0; j < num_inputs; j++) {
            if ((i >> j) & 1) {
                input_values[j] = 1;
            } else {
                input_values[j] = 0;
            }
        }

        simulate(input_values);
    }

    return 0;
}