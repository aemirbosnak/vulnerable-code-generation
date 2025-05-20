//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 1000
#define NUM_INPUTS 2
#define NUM_OUTPUTS 1

struct Circuit {
    double *input1;
    double *input2;
    double *output;
};

struct Circuit *createCircuit() {
    struct Circuit *circuit = (struct Circuit *)malloc(sizeof(struct Circuit));
    circuit->input1 = (double *)malloc(NUM_SAMPLES * sizeof(double));
    circuit->input2 = (double *)malloc(NUM_SAMPLES * sizeof(double));
    circuit->output = (double *)malloc(NUM_SAMPLES * sizeof(double));
    return circuit;
}

void destroyCircuit(struct Circuit *circuit) {
    free(circuit->input1);
    free(circuit->input2);
    free(circuit->output);
    free(circuit);
}

void generateRandomInputs(struct Circuit *circuit) {
    srand(time(NULL));
    for (int i = 0; i < NUM_SAMPLES; i++) {
        circuit->input1[i] = rand() % 100;
        circuit->input2[i] = rand() % 100;
    }
}

void simulateCircuit(struct Circuit *circuit) {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        circuit->output[i] = circuit->input1[i] + circuit->input2[i];
    }
}

void printCircuit(struct Circuit *circuit) {
    printf("Input 1: ");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%lf ", circuit->input1[i]);
    }
    printf("\n");

    printf("Input 2: ");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%lf ", circuit->input2[i]);
    }
    printf("\n");

    printf("Output: ");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%lf ", circuit->output[i]);
    }
    printf("\n");
}

int main() {
    struct Circuit *circuit = createCircuit();
    generateRandomInputs(circuit);
    simulateCircuit(circuit);
    printCircuit(circuit);
    destroyCircuit(circuit);
    return 0;
}