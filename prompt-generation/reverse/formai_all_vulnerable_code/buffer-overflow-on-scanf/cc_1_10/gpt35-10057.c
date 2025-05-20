//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
/*
Title: Decentralized Circuit Simulator
Description: A C program that simulates classical circuits in a decentralized way.
Version: 1.0
Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUTS 10
#define MAX_GATES 10

// Define a type for gates
typedef struct {
    char type[4];
    int input1;
    int input2;
    int output;
} Gate;

// Function to get the inputs from the user
void get_inputs(int inputs[], int num_inputs) {
    printf("Enter %d inputs (0 or 1):\n", num_inputs);
    for (int i = 0; i < num_inputs; i++) {
        scanf("%d", &inputs[i]);
    }
}

// Function to simulate the circuit
void simulate_circuit(Gate gates[], int num_gates, int inputs[], int num_inputs) {
    int outputs[MAX_INPUTS];
    for (int i = 0; i < num_inputs; i++) {
        outputs[i] = inputs[i];
    }
    for (int i = 0; i < num_gates; i++) {
        if (strcmp(gates[i].type, "NOT") == 0) {
            outputs[gates[i].output] = !outputs[gates[i].input1];
        }
        else if (strcmp(gates[i].type, "AND") == 0) {
            outputs[gates[i].output] = outputs[gates[i].input1] && outputs[gates[i].input2];
        }
        else if (strcmp(gates[i].type, "OR") == 0) {
            outputs[gates[i].output] = outputs[gates[i].input1] || outputs[gates[i].input2];
        }
    }
    printf("Outputs:\n");
    for (int i = 0; i < num_inputs; i++) {
        printf("%d ", outputs[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int num_inputs, num_gates;
    int inputs[MAX_INPUTS];
    Gate gates[MAX_GATES];

    printf("Enter the number of inputs: ");
    scanf("%d", &num_inputs);

    get_inputs(inputs, num_inputs);

    printf("Enter the number of gates: ");
    scanf("%d", &num_gates);

    for (int i = 0; i < num_gates; i++) {
        Gate gate;
        printf("Enter gate type (NOT, AND, OR): ");
        scanf("%s", gate.type);
        printf("Enter input 1: ");
        scanf("%d", &gate.input1);
        if (strcmp(gate.type, "NOT") != 0) {
            printf("Enter input 2: ");
            scanf("%d", &gate.input2);
        }
        printf("Enter output: ");
        scanf("%d", &gate.output);

        gates[i] = gate;
    }

    simulate_circuit(gates, num_gates, inputs, num_inputs);

    return 0;
}