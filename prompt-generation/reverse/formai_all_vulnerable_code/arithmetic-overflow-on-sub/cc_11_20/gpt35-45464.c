//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

double resistance[SIZE][SIZE]; // resistance matrix
double voltage[SIZE]; // voltage matrix
double current[SIZE]; // current matrix

int main() {
    int n, m; // number of nodes and branches respectively
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int node1, node2;
        scanf("%d%d", &node1, &node2);

        double r;
        scanf("%lf", &r);

        resistance[node1][node1] += 1.0 / r;
        resistance[node1][node2] -= 1.0 / r;
        resistance[node2][node1] -= 1.0 / r;
        resistance[node2][node2] += 1.0 / r;
    }

    for (int i = 0; i < n; i++) {
        scanf("%lf", &voltage[i]);
    }

    // Solve the circuit using Gaussian elimination
    for (int k = 0; k < n; k++) {
        int max = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(resistance[i][k]) > fabs(resistance[max][k])) {
                max = i;
            }
        }

        for (int j = 0; j <= n; j++) {
            double temp = resistance[k][j];
            resistance[k][j] = resistance[max][j];
            resistance[max][j] = temp;
        }
        double temp = voltage[k];
        voltage[k] = voltage[max];
        voltage[max] = temp;

        for (int i = k + 1; i < n; i++) {
            double factor = resistance[i][k] / resistance[k][k];
            voltage[i] -= factor * voltage[k];
            for (int j = k; j <= n; j++) {
                resistance[i][j] -= factor * resistance[k][j];
            }
        }
    }

    // Back-substitution to find the currents
    for (int i = n - 1; i >= 0; i--) {
        current[i] = voltage[i];
        for (int j = i + 1; j < n; j++) {
            current[i] -= resistance[i][j] * current[j];
        }
        current[i] /= resistance[i][i];
    }

    // Print the results
    for (int i = 0; i < n; i++) {
        printf("Node %d: %lf A\n", i, current[i]);
    }

    return 0;
}