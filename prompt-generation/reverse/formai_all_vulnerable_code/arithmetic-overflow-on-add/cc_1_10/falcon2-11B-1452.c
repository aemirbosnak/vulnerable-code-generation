//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUTS 10
#define MAX_OUTPUTS 5

typedef struct {
    int inputs[MAX_INPUTS];
    int outputs[MAX_OUTPUTS];
} Circuit;

void initialize_circuit(Circuit* circuit, int num_inputs, int num_outputs) {
    srand(time(NULL));
    
    for (int i = 0; i < num_inputs; i++) {
        circuit->inputs[i] = rand() % 2;
    }
    
    for (int i = 0; i < num_outputs; i++) {
        circuit->outputs[i] = rand() % 2;
    }
}

void print_circuit(Circuit* circuit) {
    printf("Inputs: ");
    for (int i = 0; i < MAX_INPUTS; i++) {
        printf("%d ", circuit->inputs[i]);
    }
    printf("\nOutputs: ");
    for (int i = 0; i < MAX_OUTPUTS; i++) {
        printf("%d ", circuit->outputs[i]);
    }
    printf("\n");
}

void simulate_circuit(Circuit* circuit) {
    int i, j;
    for (i = 0; i < MAX_INPUTS; i++) {
        for (j = 0; j < MAX_OUTPUTS; j++) {
            if (circuit->inputs[i] == 1) {
                circuit->outputs[j] = circuit->outputs[j] + 1;
            }
        }
    }
}

int main() {
    Circuit circuit;
    initialize_circuit(&circuit, 5, 3);
    print_circuit(&circuit);
    simulate_circuit(&circuit);
    print_circuit(&circuit);
    
    return 0;
}