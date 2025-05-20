//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of circuits and circuit elements allowed
#define MAX_NUM_CIRCUITS 10
#define MAX_NUM_ELEMENTS 100

// Define the circuit element struct
typedef struct CircuitElement {
    int fromNode;
    int toNode;
    float resistance;
    float capacitance;
    float inductance;
} CircuitElement;

// Define the circuit struct
typedef struct Circuit {
    int numElements;
    CircuitElement elements[MAX_NUM_ELEMENTS];
} Circuit;

int main() {
    Circuit circuits[MAX_NUM_CIRCUITS];
    int numCircuits = 0;

    // Take input for the circuit
    printf("Enter the number of circuits you want to simulate: ");
    scanf("%d", &numCircuits);

    // Take input for each circuit's element values
    for (int i = 0; i < numCircuits; i++) {
        printf("Enter the number of elements for circuit %d: ", i+1);
        scanf("%d", &circuits[i].numElements);

        for (int j = 0; j < circuits[i].numElements; j++) {
            printf("Enter values for element %d\n", j+1);

            printf("From node: ");
            scanf("%d", &circuits[i].elements[j].fromNode);

            printf("To node: ");
            scanf("%d", &circuits[i].elements[j].toNode);

            printf("Resistance: ");
            scanf("%f", &circuits[i].elements[j].resistance);

            printf("Capacitance: ");
            scanf("%f", &circuits[i].elements[j].capacitance);

            printf("Inductance: ");
            scanf("%f", &circuits[i].elements[j].inductance);
        }

        printf("Circuit %d input ended.\n", i+1);
    }

    // Print the circuit information
    for (int i = 0; i < numCircuits; i++) {
        printf("Circuit %d:\n", i+1);

        for (int j = 0; j < circuits[i].numElements; j++) {
            printf("Element %d: From Node=%d To Node=%d Resistance=%f Capacitance=%f Inductance=%f\n", 
                j+1, circuits[i].elements[j].fromNode, circuits[i].elements[j].toNode,
                circuits[i].elements[j].resistance, circuits[i].elements[j].capacitance, circuits[i].elements[j].inductance);
        }
    }

    return 0;
}