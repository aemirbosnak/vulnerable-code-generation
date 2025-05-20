//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000

int numRes, numVol, numCur, numNodes;
double rVal[MAX_NODES][MAX_NODES], vVal[MAX_NODES];
char nodeNames[MAX_NODES][5], node1[5], node2[5];

void getResistors() {
    printf("Enter the number of resistors: ");
    scanf("%d", &numRes);
    printf("\nEnter the resistance values (in ohms):\n");
    for (int i = 1; i <= numRes; i++) {
        printf("R%d: ", i);
        double r;
        scanf("%lf", &r);
        printf("\n");
        rVal[i][i] = 1 / r;
    }
}

void getVoltages() {
    printf("Enter the number of voltage sources: ");
    scanf("%d", &numVol);
    printf("\nEnter the voltage values (in volts):\n");
    for (int i = 1; i <= numVol; i++) {
        printf("V%d: ", i);
        double v;
        scanf("%lf", &v);
        printf("\n");
        printf("Enter the node names (in the format 'n1 n2'):\n");
        scanf("%s %s", node1, node2);
        for (int j = 1; j <= numNodes; j++) {
            if (strcmp(nodeNames[j], node1) == 0) {
                vVal[j] += v;
                rVal[numNodes + i][j] = 1;
            } else if (strcmp(nodeNames[j], node2) == 0) {
                vVal[j] -= v;
                rVal[numNodes + i][j] = -1;
            }
        }
        strcpy(nodeNames[numNodes + i], node1);
    }
}

void getCurrents() {
    printf("Enter the number of current sources: ");
    scanf("%d", &numCur);
    printf("\nEnter the current values (in amperes):\n");
    for (int i = 1; i <= numCur; i++) {
        printf("I%d: ", i);
        double cur;
        scanf("%lf", &cur);
        printf("\n");
        printf("Enter the node names (in the format 'n1 n2'):\n");
        scanf("%s %s", node1, node2);
        for (int j = 1; j <= numNodes; j++) {
            if (strcmp(nodeNames[j], node1) == 0) {
                rVal[j][numNodes + i] = -1;
            } else if (strcmp(nodeNames[j], node2) == 0) {
                rVal[j][numNodes + i] = 1;
            }
        }
        rVal[numNodes + i][numNodes + i] = -cur;
    }
}

void printMatrix(double A[][MAX_NODES], int n) {
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            printf("%10.5f ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("--- Welcome to the Brave C Classical Circuit Simulator! ---\n");

    printf("Enter the total number of nodes: ");
    scanf("%d", &numNodes);
    printf("\nEnter the node names (one per line):\n");
    for (int i = 1; i <= numNodes; i++) {
        scanf("%s", nodeNames[i]);
    }

    getResistors();
    getVoltages();
    getCurrents();

    printf("\n--- Matrix A ---\n");
    double A[MAX_NODES][MAX_NODES + 1];
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            A[i][j] = rVal[i][j];
        }
        A[i][numNodes + 1] = vVal[i];
    }
    printMatrix(A, numNodes);

    printf("\n--- Gauss-Jordan Elimination ---\n");
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            if (i == j) continue;
            double ratio = A[j][i] / A[i][i];
            for (int k = 1; k <= numNodes + 1; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }
    printMatrix(A, numNodes);

    printf("\n--- Solution ---\n");
    for (int i = 1; i <= numNodes; i++) {
        printf("%s = %10.5f\n", nodeNames[i], A[i][numNodes + 1] / A[i][i]);
    }

    printf("\n--- End of Simulation ---\n");

    return 0;
}