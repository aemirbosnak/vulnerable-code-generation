//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define CIRCUIT_SIZE 10

typedef struct {
    int input1;
    int input2;
    int output;
} Gate;

void simulate(Gate circuit[CIRCUIT_SIZE], int *inputs) {
    int outputs[CIRCUIT_SIZE] = {0};

    for (int i = 0; i < CIRCUIT_SIZE; i++) {
        Gate gate = circuit[i];

        int output = 0;
        switch (gate.input1) {
            case -1:
            case 0:
                break;
            case 1:
                output = 1;
                break;
            default:
                output |= inputs[gate.input1 - 2];
                break;
        }
        switch (gate.input2) {
            case -1:
            case 0:
                break;
            case 1:
                output = 1;
                break;
            default:
                output |= inputs[gate.input2 - 2];
                break;
        }

        int previousOutput = outputs[i - 1];
        if (i == 0) {
            previousOutput = inputs[0];
        }

        switch (output) {
            case 0:
                outputs[i] = 0;
                break;
            case 1:
                outputs[i] = previousOutput;
                break;
            case 2:
                outputs[i] = !previousOutput;
                break;
            case 3:
                outputs[i] = 1;
                break;
        }
    }

    for (int i = 0; i < CIRCUIT_SIZE; i++) {
        circuit[i].output = outputs[i];
    }
}

int main() {
    Gate circuit[CIRCUIT_SIZE] = {
        {0, 0, -1},
        {1, 0, -1},
        {2, 0, -1},
        {3, 0, -1},
        {4, 0, -1},
        {5, 0, -1},
        {6, 0, -1},
        {7, 0, -1},
        {8, 0, -1},
        {9, 0, -1},
    };

    int inputs[] = {0, 1, 1, 0, 0, 1, 1, 1};

    simulate(circuit, inputs);

    for (int i = 0; i < CIRCUIT_SIZE; i++) {
        printf("Gate %d output: %d\n", i + 1, circuit[i].output);
    }

    return 0;
}