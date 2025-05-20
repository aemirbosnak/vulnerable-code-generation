//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000 // Maximum number of elements in the circuit

// Node struct representing each circuit element
typedef struct {
    char type; // Type of circuit element - 'V' for voltage source, 'R' for resistor, 'C' for capacitor
    double value; // Value of the element - voltage in volts for voltage source, resistance in ohms for resistor, capacitance in farads for capacitor
    int src, dest; // Source and destination nodes of the element
} Node;

Node circuit[SIZE]; // Array representing the circuit
int numNodes = 0; // Number of nodes in the circuit

// Function to read the circuit from a file
void readCircuit(char* fileName) {
    FILE* file = fopen(fileName, "r");
    char type;
    double value;
    int src, dest;
    while (fscanf(file, "%c %lf %d %d\n", &type, &value, &src, &dest) == 4) {
        circuit[numNodes].type = type;
        circuit[numNodes].value = value;
        circuit[numNodes].src = src;
        circuit[numNodes].dest = dest;
        numNodes++;
    }
    fclose(file);
}

// Function to simulate the circuit
void simulate(double dt, double endTime) {
    double t = 0;
    double v[SIZE] = {0}; // Voltage at each node in the circuit
    double i[SIZE] = {0}; // Current through each element in the circuit
    double dv[SIZE] = {0}; // Change in voltage at each node in the circuit
    double di[SIZE] = {0}; // Change in current through each element in the circuit
    while (t < endTime) {
        for (int j = 0; j < numNodes; j++) {
            if (circuit[j].type == 'V') {
                v[circuit[j].dest] += circuit[j].value;
                v[circuit[j].src] -= circuit[j].value;
            }
            else if (circuit[j].type == 'R') {
                double r = circuit[j].value;
                double g = 1 / r;
                double vsrc = v[circuit[j].src];
                double vdest = v[circuit[j].dest];
                double isrc = g * (vsrc - vdest);
                double idest = -isrc;
                i[j] = isrc;
                di[j] = isrc - i[j];
                i[j] += di[j] * dt;
                v[circuit[j].src] -= isrc * dt;
                v[circuit[j].dest] -= idest * dt;
            }
            else if (circuit[j].type == 'C') {
                double c = circuit[j].value;
                double qsrc = 2 * c * v[circuit[j].src];
                double qdest = 2 * c * v[circuit[j].dest];
                double isrc = (qsrc - qdest) / dt;
                double idest = -isrc;
                i[j] = isrc;
                di[j] = isrc - i[j];
                i[j] += di[j] * dt;
                v[circuit[j].src] -= isrc * dt / (2 * c);
                v[circuit[j].dest] -= idest * dt / (2 * c);
            }
        }
        for (int j = 0; j < numNodes; j++) {
            v[j] += dv[j] * dt;
            dv[j] = 0;
            i[j] += di[j] * dt;
            di[j] = 0;
        }
        t += dt;
    }
}

int main() {
    readCircuit("circuit.txt");
    simulate(0.001, 0.1);
    printf("Simulation complete!\n");
    return 0;
}