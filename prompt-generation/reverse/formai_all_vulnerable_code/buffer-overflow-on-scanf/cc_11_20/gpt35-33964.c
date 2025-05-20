//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>

// Define maximum number of circuit elements
#define MAX_ELEMENTS 100

// Enable/disable debug messages
#define DEBUG 1

// Define circuit node and element structs
typedef struct {
    double voltage;
    double current;
} Node;

typedef struct {
    int node1;
    int node2;
    double resistance;
    double current;
} Resistor;

typedef struct {
    int node1;
    int node2;
    double capacitance;
    double charge;
} Capacitor;

// Define global variables
int numNodes;
int numResistors = 0;
int numCapacitors = 0;
Node nodes[MAX_ELEMENTS];
Resistor resistors[MAX_ELEMENTS];
Capacitor capacitors[MAX_ELEMENTS];

// Function to add a resistor to the circuit
void addResistor(int node1, int node2, double resistance) {
    // Check if nodes exist
    if ((node1 > numNodes) || (node2 > numNodes) || (node1 <= 0) || (node2 <= 0)) {
        printf("Error: Invalid node numbers!\n");
        return;
    }
    // Check if resistor already exists
    for (int i = 0; i < numResistors; i++) {
        if ((resistors[i].node1 == node1 && resistors[i].node2 == node2) ||
            (resistors[i].node1 == node2 && resistors[i].node2 == node1)) {
            printf("Error: Resistor already exists!\n");
            return;
        }
    }
    // Add resistor to circuit
    resistors[numResistors].node1 = node1;
    resistors[numResistors].node2 = node2;
    resistors[numResistors].resistance = resistance;
    resistors[numResistors].current = 0.0;
    numResistors++;
    if (DEBUG) {
        printf("Resistor added: Node1=%d, Node2=%d, Resistance=%.2lf\n", node1, node2, resistance);
    }
}

// Function to add a capacitor to the circuit
void addCapacitor(int node1, int node2, double capacitance) {
    // Check if nodes exist
    if ((node1 > numNodes) || (node2 > numNodes) || (node1 <= 0) || (node2 <= 0)) {
        printf("Error: Invalid node numbers!\n");
        return;
    }
    // Check if capacitor already exists
    for (int i = 0; i < numCapacitors; i++) {
        if ((capacitors[i].node1 == node1 && capacitors[i].node2 == node2) ||
            (capacitors[i].node1 == node2 && capacitors[i].node2 == node1)) {
            printf("Error: Capacitor already exists!\n");
            return;
        }
    }
    // Add capacitor to circuit
    capacitors[numCapacitors].node1 = node1;
    capacitors[numCapacitors].node2 = node2;
    capacitors[numCapacitors].capacitance = capacitance;
    capacitors[numCapacitors].charge = 0.0;
    numCapacitors++;
    if (DEBUG) {
        printf("Capacitor added: Node1=%d, Node2=%d, Capacitance=%.2lf\n", node1, node2, capacitance);
    }
}

// Main function to simulate circuit
int main() {
    // Prompt user for number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);
    if (numNodes <= 0) {
        printf("Error: Number of nodes must be greater than 0!\n");
        return -1;
    }
    // Initialize nodes
    for (int i = 0; i <= numNodes; i++) {
        nodes[i].voltage = 0.0;
        nodes[i].current = 0.0;
    }
    // Prompt user for circuit elements
    char element;
    int node1, node2;
    double value;
    while (1) {
        printf("Enter circuit element (R/C), nodes (1-%d), and value: ", numNodes);
        scanf("%c%d%d%lf", &element, &node1, &node2, &value);
        // Skip leading whitespace
        while (getchar() != '\n');
        // Add resistor or capacitor based on user input
        switch (element) {
            case 'R':
            case 'r':
                addResistor(node1, node2, value);
                break;
            case 'C':
            case 'c':
                addCapacitor(node1, node2, value);
                break;
            default:
                printf("Error: Invalid element!\n");
                break;
        }
        // Check if user wants to stop adding elements
        char stop;
        printf("Add another element? (Y/N): ");
        scanf("%c", &stop);
        if ((stop == 'N') || (stop == 'n')) {
            break;
        }
        // Skip leading whitespace
        while (getchar() != '\n');
    }
    // Simulate circuit for 10 seconds
    double timeStep = 0.001;
    int numSteps = 10000;
    for (int i = 0; i < numSteps; i++) {
        // Calculate currents for resistors
        for (int j = 0; j < numResistors; j++) {
            int node1 = resistors[j].node1;
            int node2 = resistors[j].node2;
            double resistance = resistors[j].resistance;
            double voltageDiff = nodes[node1].voltage - nodes[node2].voltage;
            resistors[j].current = voltageDiff / resistance;
            nodes[node1].current += resistors[j].current;
            nodes[node2].current -= resistors[j].current;
        }
        // Calculate charges for capacitors
        for (int j = 0; j < numCapacitors; j++) {
            int node1 = capacitors[j].node1;
            int node2 = capacitors[j].node2;
            double capacitance = capacitors[j].capacitance;
            double voltageDiff = nodes[node1].voltage - nodes[node2].voltage;
            capacitors[j].charge += capacitance * voltageDiff * timeStep;
        }
        // Update voltages for nodes
        for (int j = 1; j <= numNodes; j++) {
            nodes[j].voltage += nodes[j].current * timeStep;
        }
    }
    // Print final node voltages and capacitor charges
    for (int i = 1; i <= numNodes; i++) {
        printf("Node %d voltage: %.2lf\n", i, nodes[i].voltage);
    }
    for (int i = 0; i < numCapacitors; i++) {
        printf("Capacitor %d charge: %.2lf\n", i+1, capacitors[i].charge);
    }
    return 0;
}