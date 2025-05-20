//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for the circuit simulation
#define MAX_NODES 50
#define MAX_STEPS 10000
#define MAX_VOLTAGE 5
#define RESISTANCE 1000
#define CAPACITANCE 10e-6

// Define variables for the circuit simulation
int num_nodes;
double time_step;
double voltage[MAX_NODES][MAX_STEPS];
double current[MAX_STEPS];
double resistance[MAX_NODES];
double capacitance[MAX_NODES];

// Function for initializing the circuit
void init_circuit() {
    // Initialize number of nodes
    printf("Enter Number of Nodes: ");
    scanf("%d", &num_nodes);

    // Initialize time step
    printf("Enter Time Step: ");
    scanf("%lf", &time_step);

    // Initialize resistance and capacitance values for each node
    for(int i=0; i<num_nodes; i++) {
        resistance[i] = RESISTANCE;
        capacitance[i] = CAPACITANCE;
    }

    // Initialize initial voltage values for each node
    for(int i=0; i<num_nodes; i++) {
        printf("Enter Initial Voltage for Node %d: ", i);
        scanf("%lf", &voltage[i][0]);
    }
}

// Function for simulating the circuit
void simulate_circuit() {
    // Compute voltage and current values for each time step
    for(int t=0; t<MAX_STEPS-1; t++) {
        for(int i=0; i<num_nodes; i++) {
            double prev_voltage = voltage[i][t];
            double next_voltage = voltage[i][t+1];
            double prev_current = current[t];

            // Compute current for this node
            double current_i = (prev_voltage - next_voltage) / resistance[i];

            // Update current
            current[t+1] = prev_current + current_i * time_step;

            // Update voltage for this node
            double voltage_i = prev_voltage + current_i * time_step / capacitance[i];
            voltage[i][t+1] = fmin(fmax(voltage_i, -MAX_VOLTAGE), MAX_VOLTAGE);
        }
    }
}

// Function for printing the results of the circuit simulation
void print_results() {
    // Print voltage values for each node
    printf("Node Voltages:\n");
    for(int i=0; i<num_nodes; i++) {
        printf("Node %d: ", i);
        for(int t=0; t<MAX_STEPS; t++) {
            printf("%lf ", voltage[i][t]);
        }
        printf("\n");
    }

    // Print current values for each time step
    printf("Current Values:\n");
    for(int t=0; t<MAX_STEPS; t++) {
        printf("%lf ", current[t]);
    }
    printf("\n");
}

// Function for freeing memory used by the circuit simulation
void cleanup_circuit() {
    // Free memory used by voltage array
    for(int i=0; i<num_nodes; i++) {
        free(voltage[i]);
    }
}

// Main function
int main() {
    // Initialize circuit
    init_circuit();

    // Simulate circuit
    simulate_circuit();

    // Print results
    print_results();

    // Free memory used by circuit simulation
    cleanup_circuit();

    return 0;
}