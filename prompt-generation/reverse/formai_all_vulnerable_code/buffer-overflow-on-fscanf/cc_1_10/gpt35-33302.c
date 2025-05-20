//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100		// Maximum number of nodes in the circuit.
#define MAX_ELEMENTS 200	// Maximum number of elements (resistor, capacitor, etc.) in the circuit.

int nodes;					// Number of nodes in the circuit.
int elements;				// Number of elements in the circuit.

double resistance[MAX_ELEMENTS];	// An array to store the resistance values of each element.
double capacitance[MAX_ELEMENTS];	// An array to store the capacitance values of each element.
double inductance[MAX_ELEMENTS];	// An array to store the inductance values of each element.
double voltage[MAX_ELEMENTS];		// An array to store the voltage sources values of each element.
double current[MAX_ELEMENTS];		// An array to store the current sources values of each element.

int n[MAX_ELEMENTS];			// An array to store the nodes that each element is connected to.
int m[MAX_NODES][MAX_NODES];	// An array to store the connections between nodes.

// Function to read the circuit description from a file.
void read_circuit()
{
	FILE *fp;
	char filename[50], c;
	int i, j, n1, n2;

	printf("Enter the filename containing the circuit description:\n");
	scanf("%s", filename);

	fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("Error opening file!\n");
		exit(1);
	}

	fscanf(fp, "%d", &nodes);
	fscanf(fp, "%d", &elements);

	// Initialize the m[][] array to all zeros.
	for (i = 0; i < MAX_NODES; i++) {
		for (j = 0; j < MAX_NODES; j++) {
			m[i][j] = 0;
		}
	}

	// Read the resistance values and node connections of each element.
	for (i = 0; i < elements; i++) {
		fscanf(fp, "%lf %d %d", &resistance[i], &n1, &n2);
		n[i] = n1;
		m[n1][n2] = m[n2][n1] = 1;
	}

	// Read the capacitance values and node connections of each element.
	for (i = 0; i < elements; i++) {
		fscanf(fp, "%lf %d %d", &capacitance[i], &n1, &n2);
		if (n[i] == n1) {
			m[n1][n2] = 2;
		} else {
			m[n2][n1] = 2;
		}
	}

	// Read the inductance values and node connections of each element.
	for (i = 0; i < elements; i++) {
		fscanf(fp, "%lf %d %d", &inductance[i], &n1, &n2);
		if (n[i] == n1) {
			m[n1][n2] = 3;
		} else {
			m[n2][n1] = 3;
		}
	}

	// Read the voltage sources values and node connections of each element.
	for (i = 0; i < elements; i++) {
		fscanf(fp, "%lf %d %d", &voltage[i], &n1, &n2);
		if (n[i] == n1) {
			m[n1][n2] = 4;
		} else {
			m[n2][n1] = 4;
		}
	}

	// Read the current sources values and node connections of each element.
	for (i = 0; i < elements; i++) {
		fscanf(fp, "%lf %d %d", &current[i], &n1, &n2);
		if (n[i] == n1) {
			m[n1][n2] = 5;
		} else {
			m[n2][n1] = 5;
		}
	}

	fclose(fp);
}

// Function to print the circuit description.
void print_circuit()
{
	int i;

	printf("CIRCUIT:\n\n");

	printf("Nodes:\n");
	for (i = 1; i <= nodes; i++) {
		printf("  %d\n", i);
	}

	printf("\nElements:\n");
	for (i = 0; i < elements; i++) {
		switch (m[n[i]][n[(i+1)%elements]]) {
			case 1: printf("  Resistor : %d ─ %d\tResistance : %.2lf\n", n[i], n[(i+1)%elements], resistance[i]); break;
			case 2: printf("  Capacitor : %d ─ %d\tCapacitance : %.6lf\n", n[i], n[(i+1)%elements], capacitance[i]); break;
			case 3: printf("  Inductor : %d ─ %d\tInductance : %.2lf\n", n[i], n[(i+1)%elements], inductance[i]); break;
			case 4: printf("  Voltage Source : %d ─ %d\tVoltage : %.2lf\n", n[i], n[(i+1)%elements], voltage[i]); break;
			case 5: printf("  Current Source : %d ─ %d\tCurrent : %.2lf\n", n[i], n[(i+1)%elements], current[i]); break;
		}
	}

	printf("\n");
}

// Function to simulate the circuit
void simulate_circuit()
{
	printf("Simulation started...\n");

	// TODO: Add circuit simulation algorithm.

	printf("The circuit simulation is complete.\n");
}

int main()
{
	// Read the circuit description.
	read_circuit();

	// Print the circuit description.
	print_circuit();

	// Simulate the circuit.
	simulate_circuit();

	return 0;
}