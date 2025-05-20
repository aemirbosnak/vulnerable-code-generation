//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NODES 10
#define ELEMENTS 20
#define MAX_DEGREE 3
#define MAX_ELEMENTS 1000

typedef struct {
    int degree;
    int *connections;
    double *values;
} Circuit;

Circuit *createCircuit(int n) {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->degree = n;
    circuit->connections = (int *)malloc(n * sizeof(int));
    circuit->values = (double *)malloc(n * sizeof(double));
    return circuit;
}

void addConnection(Circuit *circuit, int i, int j) {
    circuit->connections[i] = j;
}

void setValue(Circuit *circuit, int i, double v) {
    circuit->values[i] = v;
}

void printCircuit(Circuit *circuit) {
    printf("Circuit:\n");
    for (int i = 0; i < circuit->degree; i++) {
        printf("Node %d connected to node %d with value %f\n", i, circuit->connections[i], circuit->values[i]);
    }
}

void calculateValues(Circuit *circuit) {
    for (int i = 0; i < circuit->degree; i++) {
        for (int j = 0; j < circuit->degree; j++) {
            if (i!= j) {
                double v = circuit->values[i] * circuit->values[j];
                if (v < 0) {
                    printf("Error: Negative value encountered\n");
                    exit(1);
                }
                circuit->values[j] += v;
            }
        }
    }
}

int main() {
    Circuit *circuit = createCircuit(NODES);
    for (int i = 0; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            double r = rand() / (double)RAND_MAX;
            if (r < 0.5) {
                addConnection(circuit, i, j);
                setValue(circuit, i, rand() / (double)RAND_MAX);
            }
        }
    }
    printCircuit(circuit);
    calculateValues(circuit);
    printf("Values:\n");
    for (int i = 0; i < circuit->degree; i++) {
        printf("Node %d has value %f\n", i, circuit->values[i]);
    }
    return 0;
}