//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Sherlock Holmes
/* The Case of the Circuit Conundrum */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constants */

#define MAX_NODES 50
#define MAX_RESISTORS 100
#define NODES_UNSET -1

/* Structs */

struct circuit {
    double voltages[MAX_NODES];
    double resistors[MAX_RESISTORS];
    int connections[MAX_RESISTORS][2];
    int numNodes;
    int numResistors;
};

/* Function Prototypes */

void parseInput(FILE *fp, struct circuit *ckt);
void printCircuit(struct circuit *ckt);
void solveCircuit(struct circuit *ckt);
double calculateNodeVoltage(struct circuit *ckt, int node);
double calculateResistance(struct circuit *ckt, int rIndex);

/* Main Function */

int main(int argc, char *argv[]) {
    /* Parse Input */
    if (argc < 2) {
        printf("No input file specified.\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Could not open file: %s\n", argv[1]);
        exit(1);
    }

    struct circuit ckt;
    parseInput(fp, &ckt);
    fclose(fp);

    /* Print Circuit */
    printf("Initial Circuit:\n");
    printCircuit(&ckt);

    /* Solve Circuit */
    solveCircuit(&ckt);

    /* Print Solved Circuit */
    printf("Solved Circuit:\n");
    printCircuit(&ckt);

    return 0;
}

/* Function Definitions */

/* Reads input from file */
void parseInput(FILE *fp, struct circuit *ckt) {
    int i;
    int nodeA, nodeB;
    double resistance;
    
    fscanf(fp, "%d %d", &ckt->numNodes, &ckt->numResistors);
    for (i = 0; i < ckt->numResistors; i++) {
        fscanf(fp, "%d %d %lf", &nodeA, &nodeB, &resistance);
        ckt->connections[i][0] = nodeA;
        ckt->connections[i][1] = nodeB;
        ckt->resistors[i] = resistance;
    }

    /* Initialize all node voltages to zero */
    for (i = 0; i < ckt->numNodes; i++) {
        ckt->voltages[i] = 0.0;
    }
}

/* Prints circuit */
void printCircuit(struct circuit *ckt) {
    int i;

    printf("Nodes: %d, Resistors: %d\n", ckt->numNodes, ckt->numResistors);
    for (i = 0; i < ckt->numResistors; i++) {
        printf("R%d: %d -> %d [%.2lf ohms]\n", i, ckt->connections[i][0], ckt->connections[i][1], ckt->resistors[i]);
    }
    for (i = 0; i < ckt->numNodes; i++) {
        printf("Node %d: %.2lf Volts\n", i, ckt->voltages[i]);
    }
}

/* Solves circuit using nodal analysis */
void solveCircuit(struct circuit *ckt) {
    int i;
    int nodeA, nodeB;
    double current;
    
    for (i = 0; i < ckt->numResistors; i++) {
        nodeA = ckt->connections[i][0];
        nodeB = ckt->connections[i][1];

        /* Calculate current flowing through resistor */
        current = (calculateNodeVoltage(ckt, nodeA) - calculateNodeVoltage(ckt, nodeB)) / calculateResistance(ckt, i);

        /* Update node voltages */
        ckt->voltages[nodeA] -= current;
        ckt->voltages[nodeB] += current;
    }
}

/* Calculates voltage at given node using nodal analysis */
double calculateNodeVoltage(struct circuit *ckt, int node) {
    int i;
    int nodeA, nodeB;
    double resistance;
    double voltage = 0.0;

    for (i = 0; i < ckt->numResistors; i++) {
        nodeA = ckt->connections[i][0];
        nodeB = ckt->connections[i][1];
        resistance = calculateResistance(ckt, i);

        if (nodeA == node) {
            voltage += (ckt->voltages[nodeB] - ckt->voltages[nodeA]) / resistance;
        } else if (nodeB == node) {
            voltage += (ckt->voltages[nodeA] - ckt->voltages[nodeB]) / resistance;
        }
    }

    return voltage;
}

/* Calculates resistance of resistor */
double calculateResistance(struct circuit *ckt, int rIndex) {
    return ckt->resistors[rIndex];
}