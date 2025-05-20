//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_VALUE 999999999

typedef struct resistorInfo {
    int nodeOne;
    int nodeTwo;
    double resistance;
} Resistor;

typedef struct voltageSourceInfo {
    int positiveNode;
    int negativeNode;
    double voltage;
} VoltageSource;

typedef struct currentSourceInfo {
    int positiveNode;
    int negativeNode;
    double current;
} CurrentSource;

int numberOfNodes;
int numberOfResistors;
int numberOfVoltageSources;
int numberOfCurrentSources;
Resistor resistors[MAX_NODES];
VoltageSource voltageSources[MAX_NODES];
CurrentSource currentSources[MAX_NODES];
double nodeMatrix[MAX_NODES][MAX_NODES + 1];
double voltageVector[MAX_NODES];
int nodeVisited[MAX_NODES];

void readInput() {
    scanf("%d %d %d %d", &numberOfNodes, &numberOfResistors, &numberOfVoltageSources, &numberOfCurrentSources);
    for (int i = 0; i < numberOfResistors; i++) {
        scanf("%d %d %lf", &resistors[i].nodeOne, &resistors[i].nodeTwo, &resistors[i].resistance);
    }
    for (int i = 0; i < numberOfVoltageSources; i++) {
        scanf("%d %d %lf", &voltageSources[i].positiveNode, &voltageSources[i].negativeNode, &voltageSources[i].voltage);
    }
    for (int i = 0; i < numberOfCurrentSources; i++) {
        scanf("%d %d %lf", &currentSources[i].positiveNode, &currentSources[i].negativeNode, &currentSources[i].current);
    }
}

void initNodeMatrix() {
    for (int i = 0; i < numberOfNodes; i++) {
        for (int j = 0; j <= numberOfNodes; j++) {
            nodeMatrix[i][j] = 0;
        }
        nodeVisited[i] = 0;
        voltageVector[i] = 0;
    }
}

void addResistorToMatrix(Resistor resistor) {
    int nodeOne = resistor.nodeOne - 1;
    int nodeTwo = resistor.nodeTwo - 1;
    double resistance = resistor.resistance;
    // If neither node is the ground node then add the conductance value to the matrix
    if (nodeOne != 0 && nodeTwo != 0) {
        nodeMatrix[nodeOne][nodeOne] += (1.0 / resistance);
        nodeMatrix[nodeTwo][nodeTwo] += (1.0 / resistance);
        nodeMatrix[nodeOne][nodeTwo] += (-1.0 / resistance);
        nodeMatrix[nodeTwo][nodeOne] += (-1.0 / resistance);
    }
    // If one of the nodes is the ground node then add the voltage value to the appropriate position in the vector
    else if (nodeOne == 0) {
        nodeMatrix[nodeTwo][nodeTwo] += (1.0 / resistance);
        voltageVector[nodeTwo] += (1.0 / resistance);
    }
    else if (nodeTwo == 0) {
        nodeMatrix[nodeOne][nodeOne] += (1.0 / resistance);
        voltageVector[nodeOne] += (1.0 / resistance);
    }
}

void addVoltageSourceToMatrix(VoltageSource voltageSource) {
    int positiveNode = voltageSource.positiveNode - 1;
    int negativeNode = voltageSource.negativeNode - 1;
    double voltage = voltageSource.voltage;
    if (positiveNode != 0 && negativeNode != 0) {
        nodeMatrix[positiveNode][numberOfNodes] += -voltage;
        nodeMatrix[negativeNode][numberOfNodes] += voltage;
        nodeMatrix[positiveNode][positiveNode] += 1;
        nodeMatrix[negativeNode][negativeNode] += 1;
        nodeMatrix[positiveNode][negativeNode] += -1;
        nodeMatrix[negativeNode][positiveNode] += -1;
    }
    else if (positiveNode == 0) {
        nodeMatrix[negativeNode][numberOfNodes] += voltage;
    }
    else if (negativeNode == 0) {
        nodeMatrix[positiveNode][numberOfNodes] += -voltage;
    }
}

void addCurrentSourceToMatrix(CurrentSource currentSource) {
    int positiveNode = currentSource.positiveNode - 1;
    int negativeNode = currentSource.negativeNode - 1;
    double current = currentSource.current;
    if (positiveNode != 0 && negativeNode != 0) {
        nodeMatrix[positiveNode][numberOfNodes] += -current;
        nodeMatrix[negativeNode][numberOfNodes] += current;
    }
    else if (positiveNode == 0) {
        nodeMatrix[negativeNode][numberOfNodes] += current;
    }
    else if (negativeNode == 0) {
        nodeMatrix[positiveNode][numberOfNodes] += -current;
    }
}

int findUnvisitedNode() {
    for (int i = 0; i < numberOfNodes; i++) {
        if (!nodeVisited[i]) {
            return i;
        }
    }
    return MAX_VALUE;
}

void solveMatrix() {
    int unvisitedNode = findUnvisitedNode();
    while (unvisitedNode != MAX_VALUE) {
        nodeVisited[unvisitedNode] = 1;
        double diagonalValue = nodeMatrix[unvisitedNode][unvisitedNode];
        if (diagonalValue != 0) {
            for (int i = 0; i <= numberOfNodes; i++) {
                nodeMatrix[unvisitedNode][i] /= diagonalValue;
            }
            for (int i = 0; i < numberOfNodes; i++) {
                if (i != unvisitedNode) {
                    double coefficient = nodeMatrix[i][unvisitedNode];
                    for (int j = 0; j <= numberOfNodes; j++) {
                        nodeMatrix[i][j] -= (coefficient * nodeMatrix[unvisitedNode][j]);
                    }
                }
            }
        }
        else {
            printf(" ERROR ");
            exit(0);
        }
        unvisitedNode = findUnvisitedNode();
    }
    for (int i = 0; i < numberOfNodes; i++) {
        printf(" V%d = %.3lf Volts\n", i + 1, voltageVector[i]);
    }
}

int main() {
    readInput();
    initNodeMatrix();
    for (int i = 0; i < numberOfResistors; i++) {
        addResistorToMatrix(resistors[i]);
    }
    for (int i = 0; i < numberOfVoltageSources; i++) {
        addVoltageSourceToMatrix(voltageSources[i]);
    }
    for (int i = 0; i < numberOfCurrentSources; i++) {
        addCurrentSourceToMatrix(currentSources[i]);
    }
    solveMatrix();
    return 0;
}