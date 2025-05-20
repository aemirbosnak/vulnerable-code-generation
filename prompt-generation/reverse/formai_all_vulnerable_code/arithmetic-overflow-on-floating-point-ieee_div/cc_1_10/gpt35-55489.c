//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdio.h>

// Define maximum number of nodes in the circuit
#define MAX_NODES 50

void simulate_circuit(int node_count, double resistance[], double conductance[], double voltage[]) {
    // Define a matrix to store node voltages
    double node_voltages[MAX_NODES][MAX_NODES+1];

    // Initialize node voltages to 0
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j <= MAX_NODES; j++) {
            node_voltages[i][j] = 0;
        }
    }

    // Set up the matrix of node equations
    for (int i = 0; i < node_count; i++) {
        for (int j = 0; j < node_count; j++) {
            if (i == j) {
                double sum_resistance = 0;
                double sum_conductance = 0;
                for (int k = 0; k < node_count; k++) {
                    if (k != i) {
                        sum_resistance += resistance[i*node_count + k];
                        sum_conductance += conductance[i*node_count + k];
                    }
                }
                node_voltages[i][j] = sum_conductance + sum_resistance;
                node_voltages[i][node_count] = voltage[i];
            } else {
                node_voltages[i][j] = -conductance[i*node_count+j];
            }
        }
    }

    // Solve the matrix of node equations using Gauss Jordan elimination
    for (int i = 0; i < node_count; i++) {
        // Find the row with maximum value in the current column
        int max_row = i;
        for (int j = i+1; j < node_count; j++) {
            if (node_voltages[j][i] > node_voltages[max_row][i]) {
                max_row = j;
            }
        }

        // Swap the rows to put the maximum value at the top
        for (int k = i; k <= node_count; k++) {
            double temp = node_voltages[i][k];
            node_voltages[i][k] = node_voltages[max_row][k];
            node_voltages[max_row][k] = temp;
        }

        // Divide the pivot row to make the pivot element 1
        double pivot = node_voltages[i][i];
        for (int k = i; k <= node_count; k++) {
            node_voltages[i][k] /= pivot;
        }

        // Subtract the pivot row from all the other rows to make the rest of the elements 0
        for (int j = 0; j < node_count; j++) {
            if (j != i) {
                double factor = node_voltages[j][i];
                for (int k = i; k <= node_count; k++) {
                    node_voltages[j][k] -= factor * node_voltages[i][k];
                }
            }
        }
    }

    // Print the node voltages
    printf("Node Voltages:\n");
    for (int i = 0; i < node_count; i++) {
        printf("Node %d: %.4f\n", i+1, node_voltages[i][node_count]);
    }
}

int main() {
    double resistance[16] = {1, 2, 0, 0, 2, 4, 3, 0, 0, 3, 5, 2, 0, 0, 2, 4};
    double conductance[16];
    double voltage[4] = {5, 0, 0, -5};

    // Calculate the conductance matrix from the resistance matrix
    for (int i = 0; i < 16; i++) {
        conductance[i] = 1 / resistance[i];
    }

    simulate_circuit(4, resistance, conductance, voltage);

    return 0;
}