//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define MAX_NODES 50

int numNodes = 0;
int numVoltageSources = 0;
int numResistors = 0;

typedef struct {
    int node1;
    int node2;
    double value;
} Resistor;

typedef struct {
    int node1;
    int node2;
    double value;
} VoltageSource;

Resistor resistors[MAX_NODES];
VoltageSource voltageSources[MAX_NODES];

double admittanceMatrix[MAX_NODES][MAX_NODES];
double voltageVector[MAX_NODES];

void addResistor(int node1, int node2, double value) {
    resistors[numResistors].node1 = node1;
    resistors[numResistors].node2 = node2;
    resistors[numResistors].value = value;
    numResistors++;
}

void addVoltageSource(int node1, int node2, double value) {
    voltageSources[numVoltageSources].node1 = node1;
    voltageSources[numVoltageSources].node2 = node2;
    voltageSources[numVoltageSources].value = value;
    numVoltageSources++;
}

void printMatrix(double matrix[MAX_NODES][MAX_NODES], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void printVector(double vector[MAX_NODES], int n) {
    for(int i = 0; i < n; i++) {
        printf("%.2f\t", vector[i]);
    }
    printf("\n");
}

void buildAdmittanceMatrix() {
    for(int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            admittanceMatrix[i][j] = 0;
        }
    }
    for(int i = 0; i < numResistors; i++) {
        int node1 = resistors[i].node1;
        int node2 = resistors[i].node2;
        double value = resistors[i].value;
        admittanceMatrix[node1][node1] += 1.0/value; 
        admittanceMatrix[node2][node2] += 1.0/value;
        admittanceMatrix[node1][node2] -= 1.0/value;
        admittanceMatrix[node2][node1] -= 1.0/value;
    }
    for(int i = 0; i < numVoltageSources; i++) {
        int node1 = voltageSources[i].node1;
        int node2 = voltageSources[i].node2;
        double value = voltageSources[i].value;
        if(node1 != -1) {
            admittanceMatrix[node1][numNodes+1+i] += 1.0;
            admittanceMatrix[numNodes+1+i][node1] += 1.0;
        }
        if(node2 != -1) {
            admittanceMatrix[node2][numNodes+1+i] -= 1.0;
            admittanceMatrix[numNodes+1+i][node2] -= 1.0;
        }
        admittanceMatrix[numNodes+1+i][numNodes+1+i] -= value;
    }
}

void solveMatrix(double matrix[MAX_NODES][MAX_NODES], double vector[MAX_NODES], int n) {
    for(int i = 0; i < n; i++) {
        double maxElement = fabs(matrix[i][i]);
        int maxRow = i;
        for(int j = i+1; j < n; j++) {
            if(fabs(matrix[j][i]) > maxElement) {
                maxElement = fabs(matrix[j][i]);
                maxRow = j;
            }
        }
        for(int j = i; j < n; j++) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[maxRow][j];
            matrix[maxRow][j] = temp;
        }
        double temp = vector[i];
        vector[i] = vector[maxRow];
        vector[maxRow] = temp;
        for(int j = i+1; j < n; j++) {
            double f = matrix[j][i]/matrix[i][i];
            vector[j] -= f * vector[i];
            for(int k = i; k < n; k++) {
                matrix[j][k] -= f * matrix[i][k];
            }
        }
    }
    for(int i = n-1; i >= 0; i--) {
        vector[i] /= matrix[i][i];
        for(int j = i-1; j >= 0; j--) {
            vector[j] -= vector[i] * matrix[j][i];
        }
    }
}

void solveCircuit() {
    double b[MAX_NODES];
    for(int i = 0; i < numNodes; i++) {
        b[i] = 0;
    }
    for(int i = 0; i < numVoltageSources; i++) {
        b[numNodes+1+i] = voltageSources[i].value;
    }
    solveMatrix(admittanceMatrix, b, numNodes+numVoltageSources+1);
    printf("Node Voltages:\n");
    for(int i = 0; i < numNodes; i++) {
        printf("Node %d: %.2f\n", i, b[i]);
    }
}

int main() {
    int choice;
    do {
        printf("Select an option:\n");
        printf("1. Add a resistor\n");
        printf("2. Add a voltage source\n");
        printf("3. Solve circuit\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int node1, node2;
                double value;
                printf("Enter the first node: ");
                scanf("%d", &node1);
                printf("Enter the second node: ");
                scanf("%d", &node2);
                printf("Enter the resistance in ohms: ");
                scanf("%lf", &value);
                addResistor(node1, node2, value);
                numNodes = fmax(numNodes, fmax(node1, node2)+1);
                break;
            }
            case 2: {
                int node1, node2;
                double value;
                printf("Enter the first node (-1 for ground): ");
                scanf("%d", &node1);
                printf("Enter the second node (-1 for ground): ");
                scanf("%d", &node2);
                printf("Enter the voltage in volts: ");
                scanf("%lf", &value);
                addVoltageSource(node1, node2, value);
                numNodes = fmax(numNodes, fmax(node1, node2)+1);
                break;
            }
            case 3: {
                buildAdmittanceMatrix();
                solveCircuit();
                break;
            }
            case 4: {
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while(choice != 4);
    return 0;
}