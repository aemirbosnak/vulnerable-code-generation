//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_RESISTORS 2000

typedef struct {
    int node1, node2;
    double resistance;
} Resistor;

Resistor resistors[MAX_RESISTORS];
int numResistors = 0;
int numNodes = 0; // number of nodes
double nodeVoltages[MAX_NODES] = {0};

// function to parse the input file
void parseFile(FILE* file) {
    while (!feof(file)) {
        int node1, node2;
        double resistance;
        int itemsRead = fscanf(file, "%d %d %lf", &node1, &node2, &resistance);
        if (itemsRead == 3) {
            // add resistor to array
            resistors[numResistors].node1 = node1;
            resistors[numResistors].node2 = node2;
            resistors[numResistors].resistance = resistance;
            numResistors++;
            
            // keep track of number of nodes
            if (node1 > numNodes) {
                numNodes = node1;
            }
            if (node2 > numNodes) {
                numNodes = node2;
            }
        }
    }
}

// function to solve the system of equations
void solve() {
    for (int i = 1; i <= numNodes; i++) {
        int numConnections = 0;
        double resistanceSum = 0;
        for (int j = 0; j < numResistors; j++) {
            if (resistors[j].node1 == i || resistors[j].node2 == i) {
                numConnections++;
                resistanceSum += resistors[j].resistance;
            }
        }
        
        if (numConnections == 0) {
            // set voltage to 0 if node is not connected
            nodeVoltages[i] = 0;
        } else {
            // calculate voltage using Kirchhoff's voltage law
            double currentSum = 0;
            for (int j = 0; j < numResistors; j++) {
                if (resistors[j].node1 == i) {
                    currentSum += nodeVoltages[resistors[j].node2] / resistors[j].resistance;
                } else if (resistors[j].node2 == i) {
                    currentSum += nodeVoltages[resistors[j].node1] / resistors[j].resistance;
                }
            }
            double voltage = currentSum / (1 / resistanceSum);
            nodeVoltages[i] = voltage;
        }
    }
}

// main function
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    // open input file
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // parse input file
    parseFile(file);
    fclose(file);
    
    // print input
    printf("Input:\n");
    printf("Number of nodes: %d\n", numNodes);
    printf("Number of resistors: %d\n", numResistors);
    for (int i = 0; i < numResistors; i++) {
        printf("Resistor %d: nodes %d and %d, resistance %.2lf\n", i+1, resistors[i].node1, resistors[i].node2, resistors[i].resistance);
    }
    
    // solve system of equations
    solve();
    
    // print output
    printf("\nOutput:\n");
    for (int i = 1; i <= numNodes; i++) {
        printf("Node %d voltage: %.2lf V\n", i, nodeVoltages[i]);
    }
    
    return 0;
}