//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

/* "Protected" style with encapsulation */
typedef struct {
    int node1;
    int node2;
    double value;
} Component;

typedef struct {
    int num_nodes;
    Component components[MAX_NODES];
} Circuit;

/* Function declarations */
Circuit* createCircuit(int num_nodes);
void addComponent(Circuit* circuit, int node1, int node2, double value);
void printCircuit(Circuit* circuit);
double simulateCircuit(Circuit* circuit);

int main() {
    int num_nodes;
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &num_nodes);

    Circuit* circuit = createCircuit(num_nodes);

    // Add components to the circuit
    addComponent(circuit, 1, 2, 100.0);
    addComponent(circuit, 1, 3, 50.0);
    addComponent(circuit, 2, 3, 75.0);

    // Print the circuit details
    printf("Circuit Details:\n");
    printCircuit(circuit);

    // Simulate the circuit and print the output
    printf("Output of the circuit: %.2f\n", simulateCircuit(circuit));

    free(circuit);

    return 0;
}

Circuit* createCircuit(int num_nodes) {
    Circuit* circuit = (Circuit*) malloc(sizeof(Circuit));
    circuit->num_nodes = num_nodes;
    return circuit;
}

void addComponent(Circuit* circuit, int node1, int node2, double value) {
    Component component = { node1, node2, value };
    circuit->components[circuit->num_nodes++] = component;
}

void printCircuit(Circuit* circuit) {
    printf("Number of nodes: %d\n", circuit->num_nodes);
    printf("Components:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node1: %d, Node2: %d, Value: %.2f\n", circuit->components[i].node1, circuit->components[i].node2, circuit->components[i].value);
    }
}

double simulateCircuit(Circuit* circuit) {
    double output = 0.0;
    for (int i = 0; i < circuit->num_nodes; i++) {
        if (circuit->components[i].node1 == 1 && circuit->components[i].node2 == 2) {
            output += circuit->components[i].value;
        } else if (circuit->components[i].node1 == 1 && circuit->components[i].node2 == 3) {
            output += circuit->components[i].value / 2.0;
        } else if (circuit->components[i].node1 == 2 && circuit->components[i].node2 == 3) {
            output += circuit->components[i].value / 1.5;
        }
    }
    return output;
}