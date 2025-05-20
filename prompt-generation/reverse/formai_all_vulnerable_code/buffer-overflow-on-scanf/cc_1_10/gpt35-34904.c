//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 50    // maximum number of nodes in the circuit

// structure to represent a circuit element
struct element {
    int node1;
    int node2;
    double value;
};

// global variable declarations
int num_nodes, num_elements;
double G[MAX_NODES][MAX_NODES], B[MAX_NODES][MAX_NODES], C[MAX_NODES];
struct element elements[MAX_NODES];

int read_circuit() {
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of circuit elements: ");
    scanf("%d", &num_elements);

    printf("Enter the circuit elements in the format <node1> <node2> <value>:\n");
    for(int i=0; i<num_elements; i++) {
        scanf("%d %d %lf", &elements[i].node1, &elements[i].node2, &elements[i].value);
    }

    return 0;
}

int build_matrices() {
    for(int i=0; i<num_elements; i++) {
        int m = elements[i].node1 - 1;
        int n = elements[i].node2 - 1;
        double value = elements[i].value;

        G[m][n] += 1/value;  // conductance matrix
        G[n][m] += 1/value;
        G[m][m] += 1/value;
        G[n][n] += 1/value;

        B[m][n] -= 1/value * sin(value);  // susceptance matrix
        B[n][m] -= 1/value * sin(value);
        B[m][m] += 1/value * sin(value);
        B[n][n] += 1/value * sin(value);

        C[m] -= value * cos(value);     // current matrix
        C[n] += value * cos(value);
    }

    return 0;
}

int solve_matrices() {
    double V[MAX_NODES], I[MAX_NODES];

    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_nodes; j++) {
            double angle = (rand() % 360) * M_PI / 180;  // random phase angle
            V[j] = cos(angle) + sin(angle) * I[j];       // initial voltage
            I[j] = 0;                                     // initial current
        }

        for(int k=0; k<num_nodes; k++) {
            for(int j=0; j<num_nodes; j++) {
                C[k] += G[k][j] * V[j];
                I[k] += B[k][j] * V[j];
            }
        }

        printf("Node voltages for node %d:\n", i+1);
        for(int j=0; j<num_nodes; j++) {
            printf("%lf\n", V[j]);
        }
        printf("\n");
    }

    return 0;
}

int main() {
    read_circuit();
    build_matrices();
    solve_matrices();

    return 0;
}