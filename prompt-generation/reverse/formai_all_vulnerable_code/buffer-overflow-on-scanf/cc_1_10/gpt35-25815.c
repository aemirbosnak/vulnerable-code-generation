//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

/**
 * This is a simple classical circuit simulator written in C.
 * It simulates a circuit with multiple inputs and outputs.
 * The circuit consist of gates such as AND, OR and NOT.
 * 
 * The program reads a file describing a classical circuit and then simulates its behavior.
 * 
 * The file format is as follows:
 * - First line contains number of inputs, number of outputs and number of gates
 * - The next lines contain information about the gates:
 *   * AND gate: 0 input1 input2 output
 *   * OR gate: 1 input1 input2 output
 *   * NOT gate: 2 input output
 *   * INPUT gate: 3 index output
 *   * OUTPUT gate: 4 input index
 *
 * Example circuit file:
 * 2 1 2
 * 0 0 1 3
 * 1 1 2 3
 * 2 3 4
 * 3 0 1
 * 4 2 1
 */

// global variables
int inputs[MAX], outputs[MAX]; // input and output values
int ninputs, noutputs, ngates; // number of inputs, outputs and gates
int gate_type[MAX], gate_input1[MAX], gate_input2[MAX], gate_output[MAX]; // gate information
char* gate_type_name[] = {"AND", "OR", "NOT", "INPUT", "OUTPUT"}; // names for gate types

// boolean functions for gates
int AND(int a, int b) {
    return a & b;
}

int OR(int a, int b) {
    return a | b;
}

int NOT(int a) {
    return !a;
}

int simulate() {
    // simulate the circuit
    int i;
    for (i = 0; i < ninputs; i++) {
        outputs[i] = inputs[i]; // initial output values are same as input values
    }

    for (i = 0; i < ngates; i++) {
        int input1, input2, output;
        input1 = gate_input1[i];
        input2 = gate_input2[i];
        output = gate_output[i];

        switch (gate_type[i]) {
            case 0: // AND gate
                outputs[output] = AND(outputs[input1], outputs[input2]);
                break;
            case 1: // OR gate
                outputs[output] = OR(outputs[input1], outputs[input2]);
                break;
            case 2: // NOT gate
                outputs[output] = NOT(outputs[input1]);
                break;
            case 3: // INPUT gate
                // do nothing, since input values have already been set
                break;
            case 4: // OUTPUT gate
                outputs[output] = outputs[input1];
                break;
            default:
                printf("Error: gate %d has incorrect type %d\n", i, gate_type[i]);
                return 0;
        }
    }

    return 1;
}

void print_circuit() {
    // print information about the circuit
    int i;

    printf("Circuit information:\n");
    printf("Inputs: %d\n", ninputs);
    printf("Outputs: %d\n", noutputs);
    printf("Gates: %d\n", ngates);

    for (i = 0; i < ngates; i++) {
        printf("Gate %d: type=%s, input1=%d, input2=%d, output=%d\n",
               i, gate_type_name[gate_type[i]], gate_input1[i], gate_input2[i], gate_output[i]);
    }
}

void read_circuit(char* filename) {
    // read circuit from file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    int i;
    fscanf(file, "%d %d %d\n", &ninputs, &noutputs, &ngates);

    for (i = 0; i < ngates; i++) {
        int type, input1, input2, output;
        fscanf(file, "%d %d %d %d\n", &type, &input1, &input2, &output);

        gate_type[i] = type;
        gate_input1[i] = input1;
        gate_input2[i] = input2;
        gate_output[i] = output;
    }

    fclose(file);
}

void print_outputs() {
    // print output values
    int i;
    printf("Output values:\n");
    for (i = 0; i < noutputs; i++) {
        printf("%d ", outputs[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <circuit file>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    read_circuit(filename);
    print_circuit();
    // read input values
    int i;
    printf("Enter input values (separated by spaces):\n");
    for (i = 0; i < ninputs; i++) {
        scanf("%d", &inputs[i]);
    }

    if (simulate()) {
        // simulation successful
        print_outputs();
    } else {
        printf("Error: simulation failed\n");
    }

    return 0;
}