//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100     // Maximum number of nodes in the circuit
#define MAX_RES 100       // Maximum number of resistors in the circuit
#define MAX_VSOURCE 100   // Maximum number of voltage sources in the circuit
#define MAX_ISOURCE 100   // Maximum number of current sources in the circuit

// Structure to hold resistor information
typedef struct Resistor {
    int node1, node2;
    double resistance;
} Resistor;

// Structure to hold voltage source information
typedef struct VoltageSource {
    int node1, node2;
    double voltage;
} VoltageSource;

// Structure to hold current source information
typedef struct CurrentSource {
    int node1, node2;
    double current;
} CurrentSource;

// Function prototypes
void enterCircuit();
void enterResistors();
void enterVoltageSources();
void enterCurrentSources();
void solveCircuit();
void printResults();

Resistor resistors[MAX_RES];              // Array of resistors in the circuit
VoltageSource voltageSources[MAX_VSOURCE]; // Array of voltage sources in the circuit
CurrentSource currentSources[MAX_ISOURCE]; // Array of current sources in the circuit
double conductance[MAX_NODES][MAX_NODES];  // Matrix to hold conductance values
double currents[MAX_NODES];                // Array to hold current values
int numNodes = 0;                          // Total number of nodes in the circuit

int main() {
    enterCircuit();
    solveCircuit();
    printResults();
    return 0;
}

// Function to enter the circuit information
void enterCircuit() {
    int numResistors, numVoltageSources, numCurrentSources;
    printf("Enter the number of resistors: ");
    scanf("%d", &numResistors);
    enterResistors(numResistors);
    printf("Enter the number of voltage sources: ");
    scanf("%d", &numVoltageSources);
    enterVoltageSources(numVoltageSources);
    printf("Enter the number of current sources: ");
    scanf("%d", &numCurrentSources);
    enterCurrentSources(numCurrentSources);
}

// Function to enter resistor information
void enterResistors(int numResistors) {
    int i;
    for (i = 0; i < numResistors; i++) {
        printf("Enter information for resistor %d:\n", i+1);
        printf("  Node 1: ");
        scanf("%d", &resistors[i].node1);
        printf("  Node 2: ");
        scanf("%d", &resistors[i].node2);
        printf("  Resistance (in ohms): ");
        scanf("%lf", &resistors[i].resistance);
        // Update the number of nodes if a new one is encountered
        if (resistors[i].node1 > numNodes) numNodes = resistors[i].node1;
        if (resistors[i].node2 > numNodes) numNodes = resistors[i].node2;
    }
}

// Function to enter voltage source information
void enterVoltageSources(int numVoltageSources) {
    int i;
    for (i = 0; i < numVoltageSources; i++) {
        printf("Enter information for voltage source %d:\n", i+1);
        printf("  Node 1: ");
        scanf("%d", &voltageSources[i].node1);
        printf("  Node 2: ");
        scanf("%d", &voltageSources[i].node2);
        printf("  Voltage (in volts): ");
        scanf("%lf", &voltageSources[i].voltage);
        // Update the number of nodes if a new one is encountered
        if (voltageSources[i].node1 > numNodes) numNodes = voltageSources[i].node1;
        if (voltageSources[i].node2 > numNodes) numNodes = voltageSources[i].node2;
    }
}

// Function to enter current source information
void enterCurrentSources(int numCurrentSources) {
    int i;
    for (i = 0; i < numCurrentSources; i++) {
        printf("Enter information for current source %d:\n", i+1);
        printf("  Node 1: ");
        scanf("%d", &currentSources[i].node1);
        printf("  Node 2: ");
        scanf("%d", &currentSources[i].node2);
        printf("  Current (in amperes): ");
        scanf("%lf", &currentSources[i].current);
        // Update the number of nodes if a new one is encountered
        if (currentSources[i].node1 > numNodes) numNodes = currentSources[i].node1;
        if (currentSources[i].node2 > numNodes) numNodes = currentSources[i].node2;
    }
}

// Function to calculate the conductance matrix and current vector
void solveCircuit() {
    int i, j, k;
    // Initialize the conductance matrix with zeros
    for (i = 1; i <= numNodes; i++) {
        for (j = 1; j <= numNodes; j++) {
            conductance[i][j] = 0;
        }
        currents[i] = 0;
    }
    // Populate the conductance matrix for resistors
    for (i = 0; i < MAX_RES && resistors[i].resistance != 0; i++) {
        double r = 1 / resistors[i].resistance;
        conductance[resistors[i].node1][resistors[i].node1] += r;
        conductance[resistors[i].node2][resistors[i].node2] += r;
        conductance[resistors[i].node1][resistors[i].node2] -= r;
        conductance[resistors[i].node2][resistors[i].node1] -= r;
    }
    // Populate the conductance matrix and current vector for voltage sources
    for (i = 0; i < MAX_VSOURCE && voltageSources[i].voltage != 0; i++) {
        int n1 = voltageSources[i].node1;
        int n2 = voltageSources[i].node2;
        double v = voltageSources[i].voltage;
        conductance[n1][n1] += 1;
        conductance[n2][n2] += 1;
        conductance[n1][n2] -= 1;
        conductance[n2][n1] -= 1;
        currents[n1] -= v;
        currents[n2] += v;
    }
    // Populate the current vector for current sources
    for (i = 0; i < MAX_ISOURCE && currentSources[i].current != 0; i++) {
        currents[currentSources[i].node1] -= currentSources[i].current;
        currents[currentSources[i].node2] += currentSources[i].current;
    }
    // Solve the system of equations using Gaussian elimination
    for (i = 1; i <= numNodes; i++) {
        double pivot = conductance[i][i];
        for (j = i; j <= numNodes; j++) {
            conductance[i][j] /= pivot;
        }
        currents[i] /= pivot;
        for (j = i+1; j <= numNodes; j++) {
            double factor = conductance[j][i] / conductance[i][i];
            for (k = i; k <= numNodes; k++) {
                conductance[j][k] -= factor * conductance[i][k];
            }
            currents[j] -= factor * currents[i];
        }
    }
    // Solve the system of equations using back substitution
    for (i = numNodes; i >= 1; i--) {
        double sum = currents[i];
        for (j = i+1; j <= numNodes; j++) {
            sum -= conductance[i][j] * currents[j];
        }
        currents[i] = sum;
    }
}

// Function to print the results
void printResults() {
    int i;
    printf("\nResults:\n");
    printf("  Node   Voltage (V)\n");
    for (i = 1; i <= numNodes; i++) {
        printf("    %d     %lf\n", i, currents[i]);
    }
}