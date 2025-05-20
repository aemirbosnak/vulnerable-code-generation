//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: authentic
#include <stdio.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_DEVICES 100

typedef struct {
    int node1, node2;
    double value;
} Device;

typedef struct {
    int type;
    double value;
    int nodes[3];
} Element;

int numNodes = 0, numDevices = 0;
Device devices[MAX_DEVICES];
Element circuit[MAX_DEVICES + MAX_NODES];

void addDevice(int node1, int node2, double value) {
    devices[numDevices].node1 = node1;
    devices[numDevices].node2 = node2;
    devices[numDevices].value = value;
    numDevices++;
}

void addElement(int type, double value, int node1, int node2, int node3) {
    circuit[numNodes].type = type;
    circuit[numNodes].value = value;
    circuit[numNodes].nodes[0] = node1;
    circuit[numNodes].nodes[1] = node2;
    circuit[numNodes].nodes[2] = node3;
    numNodes++;
}

void createCircuit() {
    // Add resistor devices
    addDevice(1, 2, 1);
    addDevice(2, 3, 2);
    addDevice(3, 0, 3);

    // Add capacitor elements
    addElement(1, 1e-6, 1, 2, 0);
    addElement(1, 2e-6, 2, 3, 0);
}

int main() {
    createCircuit();
    printf("Circuit simulation\n");

    // Solve circuit using nodal analysis
    double A[numNodes][numNodes];
    double b[numNodes];

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            A[i][j] = 0.0;
        }
        b[i] = 0.0;
    }

    // Add device equations to nodal analysis matrix
    for (int i = 0; i < numDevices; i++) {
        int node1 = devices[i].node1;
        int node2 = devices[i].node2;
        double value = devices[i].value;

        if (node1 > 0) {
            A[node1-1][node1-1] += 1.0 / value;
        }
        if (node2 > 0) {
            A[node2-1][node2-1] += 1.0 / value;
        }
        if (node1 > 0 && node2 > 0) {
            A[node1-1][node2-1] -= 1.0 / value;
            A[node2-1][node1-1] -= 1.0 / value;
        }
    }

    // Add element equations to nodal analysis matrix
    for (int i = 0; i < numNodes; i++) {
        Element e = circuit[i];
        int node1 = e.nodes[0];
        int node2 = e.nodes[1];
        int node3 = e.nodes[2];
        double value = e.value;

        switch (e.type) {
            case 1:
                if (node1 > 0) {
                    A[node1-1][i] += 1.0;
                    A[i][node1-1] -= 1.0;
                }
                if (node2 > 0) {
                    A[node2-1][i] -= 1.0;
                    A[i][node2-1] += 1.0;
                }
                break;
        }
    }

    // Solve nodal analysis matrix
    double x[numNodes];
    for (int i = 0; i < numNodes; i++) {
        x[i] = 0.0;
    }

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%f ", A[i][j]); // For debugging only
        }
        printf("\n"); // For debugging only
    }

    return 0;
}