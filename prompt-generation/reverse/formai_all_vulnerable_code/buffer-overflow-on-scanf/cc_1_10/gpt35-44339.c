//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_RESISTORS 2000

typedef struct {
    int node1;
    int node2;
    double resistance;
} Resistor;

Resistor resistorArray[MAX_RESISTORS];
int numResistors = 0;
double nodeVoltage[MAX_NODES];

void readCircuit() {
    int nodeID1, nodeID2;
    double resistance;

    printf("Enter circuit information (-1 -1 to terminate)\n");
    while (1) {
        printf("Enter resistor info: ");
        scanf("%d %d %lf", &nodeID1, &nodeID2, &resistance);

        if (nodeID1 == -1 && nodeID2 == -1)
            break;

        resistorArray[numResistors].node1 = nodeID1;
        resistorArray[numResistors].node2 = nodeID2;
        resistorArray[numResistors].resistance = resistance;

        numResistors++;
    }
}

void calculateVoltages(int numNodes) {
    int i, j, k;
    double delta, maxDelta;
    const double epsilon = 1e-9;

    for (i = 0; i < numNodes; i++)
        nodeVoltage[i] = 0;

    for (k = 0; k < 1000; k++) {
        maxDelta = 0;

        // Iterate through all nodes except the ground node
        for (i = 0; i < numNodes - 1; i++) {
            delta = 0;

            // Iterate through all resistors connected to the current node
            for (j = 0; j < numResistors; j++) {
                if (resistorArray[j].node1 == i)
                    delta += (nodeVoltage[i] - nodeVoltage[resistorArray[j].node2])
                        / resistorArray[j].resistance;
                else if (resistorArray[j].node2 == i)
                    delta += (nodeVoltage[i] - nodeVoltage[resistorArray[j].node1])
                        / resistorArray[j].resistance;
            }

            delta *= 0.5;
            if (fabs(delta) > maxDelta)
                maxDelta = fabs(delta);
            nodeVoltage[i] -= delta;
        }

        if (maxDelta < epsilon)
            break;
    }
}

int main() {
    int numNodes;
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &numNodes);
    readCircuit();
    calculateVoltages(numNodes);

    printf("\nVoltages at each node in the circuit:\n");
    for (int i = 0; i < numNodes; i++)
        printf("Node %d: %.2lfV\n", i, nodeVoltage[i]);

    return 0;
}