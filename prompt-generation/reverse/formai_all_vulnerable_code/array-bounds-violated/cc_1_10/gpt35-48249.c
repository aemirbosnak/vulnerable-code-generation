//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 50
#define MAX_PROBES 10
#define MAX_DEVICES 20

// Device Types
#define RESISTOR 'R'
#define CAPACITOR 'C'
#define INDUCTOR 'L'

// Simulation Parameters
#define MAX_TIME 100.0 // Maximum simulation time (in seconds)
#define TIME_STEP 0.001 // Simulation time step (in seconds)

// Circuit Elements
typedef struct CircuitElement {
    char type;
    int node1;
    int node2;
    double value;
    double* currentPtr;
} CircuitElement;

// Main Circuit
CircuitElement circuit[MAX_DEVICES];
int numDevices = 0;

// Probes
double probes[MAX_PROBES][MAX_NODES];
int numProbes = 0;
int probeNodes[MAX_PROBES][2];

// Device Currents
double deviceCurrents[MAX_DEVICES];

// Utility Functions
void addDevice(char type, int node1, int node2, double value);
void addProbe(int node1, int node2);
void simulate(void);

int main() {

    // Add Circuit Elements
    addDevice(RESISTOR, 1, 2, 1000.0);
    addDevice(CAPACITOR, 2, 0, 1.0E-6);
    addDevice(RESISTOR, 2, 3, 2000.0);
    addDevice(INDUCTOR, 3, 0, 10.0E-3);

    // Add Probes
    addProbe(1, 0);
    addProbe(2, 0);
    addProbe(3, 0);

    // Simulate the Circuit
    simulate();

    // Print the Results to the Terminal
    printf("Time\tProbe 1\tProbe 2\tProbe 3\n");
    for (int i = 0; i < (int)(MAX_TIME/TIME_STEP); i++) {
        printf("%f\t", i*TIME_STEP);
        for (int j = 0; j < numProbes; j++) {
            printf("%f\t", probes[j][i]);
        }
        printf("\n");
    }

    return 0;
}

void addDevice(char type, int node1, int node2, double value) {

    if (numDevices == MAX_DEVICES) {
        printf("Error: Maximum number of devices exceeded.\n");
        exit(EXIT_FAILURE);
    }

    CircuitElement newDevice;

    newDevice.type = type;
    newDevice.node1 = node1;
    newDevice.node2 = node2;
    newDevice.value = value;
    newDevice.currentPtr = &deviceCurrents[numDevices];

    circuit[numDevices] = newDevice;

    numDevices++;
}

void addProbe(int node1, int node2) {

    if (numProbes == MAX_PROBES) {
        printf("Error: Maximum number of probes exceeded.\n");
        exit(EXIT_FAILURE);
    }

    probeNodes[numProbes][0] = node1;
    probeNodes[numProbes][1] = node2;

    numProbes++;
}

void simulate(void) {

    double currentNode = 0.0;
    double conductance = 0.0;
    double capacitance = 0.0;
    double inductance = 0.0;
    double voltage = 0.0;
    double prevVoltage = 0.0;
    double deltaT = TIME_STEP;

    for (int i = 0; i < (int)(MAX_TIME/TIME_STEP); i++) {

        // Update Device Currents
        currentNode = 0.0;
        for (int j = 0; j < numDevices; j++) {
            voltage = probes[circuit[j].node1][i] - probes[circuit[j].node2][i];
            prevVoltage = probes[circuit[j].node1][i-1] - probes[circuit[j].node2][i-1];
            switch (circuit[j].type) {
                case RESISTOR:
                    conductance = circuit[j].value;
                    break;
                case CAPACITOR:
                    capacitance = circuit[j].value;
                    conductance = deltaT/capacitance;
                    circuit[j].value = capacitance * (voltage - prevVoltage) / deltaT;
                    break;
                case INDUCTOR:
                    inductance = circuit[j].value;
                    conductance = inductance / deltaT;
                    circuit[j].value = inductance * (voltage - prevVoltage) / deltaT;
                    break;
            }
            currentNode += conductance * voltage;
            *(circuit[j].currentPtr) = conductance * voltage;
        }

        // Update Probe Voltages
        for (int j = 0; j < numProbes; j++) {
            probes[probeNodes[j][0]][i+1] = probes[probeNodes[j][0]][i] + (currentNode * deltaT);
            probes[probeNodes[j][1]][i+1] = probes[probeNodes[j][1]][i] - (currentNode * deltaT);
        }
    }
}