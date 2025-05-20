//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Linus Torvalds
/* 
 * Classical Circuit Simulator in C
 * Author: Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GATE_ARGS 3

// gate type identification
enum GATE_TYPE {
    AND, OR, NOT, XOR
};

// logic gate structure
typedef struct {
    enum GATE_TYPE type;
    int numInputs;
    int* inputIds; // array of input gate IDs
    bool output;
} LogicGate;

int main() {
    int numGates; // number of logic gates
    LogicGate** gates; // array of pointers to LogicGates

    printf("Enter number of logic gates: ");
    scanf("%d", &numGates);
    gates = (LogicGate**) malloc(numGates * sizeof(LogicGate*)); // allocate memory for the gates

    for(int i = 0; i < numGates; i++) {
        printf("\nEnter gate type for gate %d:\n1. AND\n2. OR\n3. NOT\n4. XOR\n>", i+1);
        int gateType;
        scanf("%d", &gateType);
        gates[i] = (LogicGate*) malloc(sizeof(LogicGate)); // allocate memory for the current gate
        gates[i]->type = gateType-1; // adjust for 0-indexing
        gates[i]->numInputs = 0;
        gates[i]->inputIds = (int*) malloc(MAX_GATE_ARGS * sizeof(int)); // allocate memory for input IDs

        printf("\nEnter IDs of up to %d input gates for gate %d, separated by spaces:\n>", MAX_GATE_ARGS, i+1);
        int inputId;
        while(scanf("%d", &inputId) && inputId != -1) { // stop when -1 is entered
            gates[i]->inputIds[gates[i]->numInputs++] = inputId-1; // adjust for 0-indexing
        }
    }

    // simulate
    for(int i = 0; i < numGates; i++) {
        LogicGate* gate = gates[i];
        switch(gate->type) {
            case AND:
                gate->output = true;
                for(int j = 0; j < gate->numInputs; j++) {
                    LogicGate* inputGate = gates[gate->inputIds[j]];
                    gate->output = gate->output && inputGate->output;
                }
                break;
            case OR:
                gate->output = false;
                for(int j = 0; j < gate->numInputs; j++) {
                    LogicGate* inputGate = gates[gate->inputIds[j]];
                    gate->output = gate->output || inputGate->output;
                }
                break;
            case NOT:
                gate->output = !(gates[gate->inputIds[0]]->output);
                break;
            case XOR:
                gate->output = false;
                for(int j = 0; j < gate->numInputs; j++) {
                    LogicGate* inputGate = gates[gate->inputIds[j]];
                    gate->output ^= inputGate->output; // XOR with each input gate's output
                }
                break;
            default:
                printf("\nInvalid gate type.\n");
        }
    }

    // print outputs
    printf("\nOutputs:\n");
    for(int i = 0; i < numGates; i++) {
        printf("Gate[%d] output: %d\n", i+1, gates[i]->output);
    }

    // deallocate memory
    for(int i = 0; i < numGates; i++) {
        free(gates[i]->inputIds);
        free(gates[i]);
    }
    free(gates);

    return 0;
}