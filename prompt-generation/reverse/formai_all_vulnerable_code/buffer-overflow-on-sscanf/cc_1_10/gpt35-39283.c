//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 20
#define MAX_VALUES 50

int rowCount = 0;
int columnCount = 0;

// Define structure for circuit elements
typedef struct circuitElement {
    char name[10];
    int node1;
    int node2;
    double value;
} circuitElement;

circuitElement circuit[MAX_VALUES];

// Function to read circuit elements from input file
void readCircuitElements(FILE *file) {
    char buffer[100];

    while(fgets(buffer, sizeof(buffer), file)) {
        sscanf(buffer, "%s %d %d %lf", circuit[rowCount].name,
               &circuit[rowCount].node1,
               &circuit[rowCount].node2,
               &circuit[rowCount].value);

        rowCount++;
    }
}

// Function to print the circuit elements
void printCircuitElements() {
    printf("\nCircuit Elements:\n");
    printf("+----------+------+------+--------+\n");
    printf("|   Name   | Node1| Node2|  Value |\n");
    printf("+----------+------+------+--------+\n");
    
    for(int i = 0; i < rowCount; i++) {
        printf("|%9s|%6d|%6d|%8.2lf|\n", circuit[i].name, circuit[i].node1,
                                            circuit[i].node2, circuit[i].value);
    }
    
    printf("+----------+------+------+--------+\n\n");
}

// Function to get the count of nodes in the circuit
int getNodeCount() {
    int nodeCount = -1;

    for(int i = 0; i < rowCount; i++) {
        if(circuit[i].node1 > nodeCount) {
            nodeCount = circuit[i].node1;
        }
        if(circuit[i].node2 > nodeCount) {
            nodeCount = circuit[i].node2;
        }
    }

    return nodeCount;
}

// Function to solve the circuit using nodal analysis
void solveCircuit() {
    int nodeCount = getNodeCount();
    double matrix[MAX_NODES][MAX_NODES] = {0};
    double rhs[MAX_NODES] = {0};

    for(int i = 0; i < rowCount; i++) {
        int n1 = circuit[i].node1;
        int n2 = circuit[i].node2;
        double y = circuit[i].value;

        if (n1 != 0) {
            matrix[n1-1][n1-1] += 1 / y;
        }

        if (n2 != 0) {
            matrix[n2-1][n2-1] += 1 / y;
        }

        if (n1 != 0 && n2 != 0) {
            matrix[n1-1][n2-1] -= 1 / y;
            matrix[n2-1][n1-1] -= 1 / y;
        }
    }

    for(int i = 0; i < rowCount; i++) {
        if(strcmp(circuit[i].name, "V") == 0) {
            int n1 = circuit[i].node1;
            int n2 = circuit[i].node2;
            double v = circuit[i].value;

            if(n1 != 0) {
                rhs[n1-1] -= v;
            }

            if(n2 != 0) {
                rhs[n2-1] += v;
            }
        }
    }

    for(int i = 1; i < nodeCount; i++) {
        matrix[i][nodeCount] = rhs[i-1];
    }

    for(int i = 1; i < nodeCount; i++) {
        for(int j = 1; j < nodeCount+1; j++) {
            printf("%+0.2lf ", matrix[i][j]);
        }
        printf("\n");
    }

}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");

    // Read in circuit elements
    readCircuitElements(file);

    // Print circuit elements
    printCircuitElements();

    // Solve the circuit
    solveCircuit();

    fclose(file);

    return 0;
}