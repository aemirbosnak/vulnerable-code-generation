//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>

// Define the maximum number of nodes allowed in the circuit
#define MAX_NODES 100

// Define the maximum number of elements allowed in the circuit
#define MAX_ELEMENTS 200

// Define the circuit node struct
typedef struct node {
    int number;
    double voltage;
    double current;
} Node;

// Define the circuit element struct
typedef struct element {
    int node1;
    int node2;
    double resistance;
    double capacitance;
    double inductance;
} Element;

int main() {
    // Define the circuit
    Node circuitNodes[MAX_NODES];
    Element circuitElements[MAX_ELEMENTS];
    int numberOfNodes = 0;
    int numberOfElements = 0;

    // Prompt the user for the number of nodes in the circuit
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &numberOfNodes);

    // Initialize the nodes
    for(int i = 0; i < numberOfNodes; i++) {
        circuitNodes[i].number = i;
        circuitNodes[i].voltage = 0.0;
        circuitNodes[i].current = 0.0;
    }

    // Prompt the user for the number of elements in the circuit
    printf("Enter the number of elements in the circuit: ");
    scanf("%d", &numberOfElements);

    // Initialize the elements
    for(int i = 0; i < numberOfElements; i++) {
        int node1, node2;
        double resistance, capacitance, inductance;
        
        // Prompt the user for the element properties
        printf("Enter the properties of element %d:\n", i+1);
        printf("Node 1: ");
        scanf("%d", &node1);
        printf("Node 2: ");
        scanf("%d", &node2);
        printf("Resistance: ");
        scanf("%lf", &resistance);
        printf("Capacitance: ");
        scanf("%lf", &capacitance);
        printf("Inductance: ");
        scanf("%lf", &inductance);

        // Store the element in the circuit
        circuitElements[i].node1 = node1;
        circuitElements[i].node2 = node2;
        circuitElements[i].resistance = resistance;
        circuitElements[i].capacitance = capacitance;
        circuitElements[i].inductance = inductance;
    }

    // Simulate the circuit
    for(int i = 0; i < numberOfElements; i++) {
        int node1 = circuitElements[i].node1;
        int node2 = circuitElements[i].node2;
        double resistance = circuitElements[i].resistance;
        double capacitance = circuitElements[i].capacitance;
        double inductance = circuitElements[i].inductance;

        double voltageDrop = circuitNodes[node1].voltage - circuitNodes[node2].voltage;
        double current = voltageDrop / resistance;
        double capacitanceCurrent = circuitNodes[node1].current - circuitNodes[node2].current;
        capacitanceCurrent += capacitance * current;
        double inductanceCurrent = circuitNodes[node1].current - circuitNodes[node2].current;
        inductanceCurrent += inductance * current;

        circuitNodes[node1].current = capacitanceCurrent + inductanceCurrent;
        circuitNodes[node2].current = -1 * circuitNodes[node1].current;
    }

    // Print the circuit node voltages and currents
    printf("Node Voltages:\n");
    for(int i = 0; i < numberOfNodes; i++) {
        Node node = circuitNodes[i];
        printf("Node %d: %f\n", node.number, node.voltage);
    }

    printf("Node Currents:\n");
    for(int i = 0; i < numberOfNodes; i++) {
        Node node = circuitNodes[i];
        printf("Node %d: %f\n", node.number, node.current);
    }

    return 0;
}