//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include<stdio.h>

#define MAX_GATES 20
#define MAX_INPUTS 3

// Struct to hold circuit information
typedef struct {
    char type;
    int num_inputs;
    int inputs[MAX_INPUTS];
    int output;
} Gate;

int num_gates;
Gate gates[MAX_GATES];

// Function to simulate circuit
int simulate(int input) {
    int values[MAX_GATES];
    values[0] = input;
    for(int i=1; i<num_gates; i++) {
        Gate g = gates[i];
        int num_inputs = g.num_inputs;
        int output = 0;
        for(int j=0; j<num_inputs; j++) {
            int input = values[g.inputs[j]];
            if(g.type == 'N') { // Invert input if gate is NOT
                input = !input;
            }
            output += input;
        }
        if(g.type == 'A') { // Check if gate is AND
            if(output == num_inputs) {
                values[i] = 1;
            } else {
                values[i] = 0;
            }
        } else { // Gate is OR
            if(output == 0) {
                values[i] = 0;
            } else {
                values[i] = 1;
            }
        }
    }
    // Return output of last gate
    return values[gates[num_gates-1].output];
}

int main() {
    char type;
    int num_inputs, input;
    printf("Enter number of gates: ");
    scanf("%d", &num_gates);
    printf("Enter circuit information:\n");
    for(int i=1; i<num_gates; i++) {
        printf("Gate #%d type: ", i);
        scanf(" %c", &type);
        printf("Number of inputs: ");
        scanf("%d", &num_inputs);
        printf("Input gate numbers (separated by spaces): ");
        for(int j=0; j<num_inputs; j++) {
            scanf("%d", &gates[i].inputs[j]);
        }
        printf("Output gate number: ");
        scanf("%d", &gates[i].output);
        gates[i].type = type;
        gates[i].num_inputs = num_inputs;
    }
    printf("Enter input to simulate: ");
    scanf("%d", &input);
    int output = simulate(input);
    printf("Circuit output: %d\n", output);
    return 0;
}