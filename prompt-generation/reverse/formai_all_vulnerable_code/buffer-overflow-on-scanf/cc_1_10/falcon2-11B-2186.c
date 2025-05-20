//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    int i;
    float x, y, z;

    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &n);

    int nodes[n][3];
    for (i = 0; i < n; i++) {
        printf("Enter the coordinates of node %d: ", i+1);
        scanf("%f%f%f", &x, &y, &z);
        nodes[i][0] = x;
        nodes[i][1] = y;
        nodes[i][2] = z;
    }

    float potential[n];
    float current[n];
    float voltage[n];
    float resistance[n];
    float conductance[n];

    for (i = 0; i < n; i++) {
        potential[i] = 0;
        current[i] = 0;
        voltage[i] = 0;
        resistance[i] = 1;
        conductance[i] = 1;
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            potential[i] = 1;
            voltage[i] = potential[i];
            resistance[i] = 0;
            conductance[i] = 0;
        } else if (i == n-1) {
            potential[i] = 0;
            voltage[i] = potential[i];
            resistance[i] = 0;
            conductance[i] = 0;
        } else {
            potential[i] = potential[i-1] - potential[i+1];
            voltage[i] = potential[i] - voltage[i+1];
            resistance[i] = resistance[i+1];
            conductance[i] = conductance[i+1];
        }
    }

    for (i = 0; i < n; i++) {
        current[i] = voltage[i] / resistance[i];
        if (current[i] < 0) {
            current[i] = -current[i];
        }
    }

    for (i = 0; i < n; i++) {
        voltage[i] = potential[i] - current[i] * resistance[i];
    }

    for (i = 0; i < n; i++) {
        printf("Node %d: %f %f %f\n", i+1, nodes[i][0], nodes[i][1], nodes[i][2]);
        printf("Voltage: %f\n", voltage[i]);
    }

    return 0;
}