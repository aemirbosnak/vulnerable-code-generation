//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 200

typedef struct {
    int numNodes;
    double resistance;
} Component;

typedef struct {
    int numComponents;
    Component *components;
} Circuit;

void createComponent(Component *component, int numNodes, double resistance) {
    component->numNodes = numNodes;
    component->resistance = resistance;
}

void createCircuit(Circuit *circuit, int numComponents) {
    circuit->numComponents = numComponents;
    circuit->components = malloc(sizeof(Component) * numComponents);
}

void addComponent(Circuit *circuit, Component component) {
    circuit->components[circuit->numComponents - 1] = component;
}

void simulateCircuit(Circuit *circuit, double *voltages, int numNodes) {
    int i, j;
    double sum;

    for (i = 0; i < circuit->numComponents; i++) {
        for (j = 0; j < circuit->components[i].numNodes; j++) {
            sum = 0;
            if (j == 0) {
                sum += voltages[circuit->components[i].numNodes - 1];
            } else if (j == circuit->components[i].numNodes - 1) {
                sum -= voltages[0];
            } else {
                sum += voltages[j - 1] - voltages[j + 1];
            }
            voltages[circuit->components[i].numNodes - 1 - j] += sum * circuit->components[i].resistance;
        }
    }
}

int main() {
    Circuit circuit;
    Component component1, component2;
    double voltages[MAX_NODES];

    createCircuit(&circuit, 2);
    createComponent(&component1, 2, 100);
    createComponent(&component2, 2, 200);
    addComponent(&circuit, component1);
    addComponent(&circuit, component2);

    voltages[0] = 5;
    voltages[1] = 0;

    simulateCircuit(&circuit, voltages, 2);

    printf("Voltage at node 0: %lf\n", voltages[0]);
    printf("Voltage at node 1: %lf\n", voltages[1]);

    return 0;
}