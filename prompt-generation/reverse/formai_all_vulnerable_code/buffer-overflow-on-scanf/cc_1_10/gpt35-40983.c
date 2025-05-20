//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int num_nodes;
double capacitances[MAX_NODES];
double inductances[MAX_NODES];
double resistances[MAX_NODES];
double conductances[MAX_NODES];
double voltages[MAX_NODES];
double currents[MAX_NODES];
double prev_voltages[MAX_NODES];

// Initialize the capacitances, inductances, and resistances arrays
void initialize_vars(){
    int i;
    for(i=0; i<num_nodes; i++){
        capacitances[i] = 0.0;
        inductances[i] = 0.0;
        resistances[i] = 0.0;
        conductances[i] = 0.0;
        voltages[i] = 0.0;
        currents[i] = 0.0;
        prev_voltages[i] = 0.0;
    }
}

// Calculate the conductance of a given node
double calculate_conductance(int node){
    if (resistances[node] == 0) return 0.0;
    return 1.0 / resistances[node];
}

// Calculate the capacitance of a given node
double calculate_capacitance(int node){
    return capacitances[node];
}

// Calculate the inductance of a given node
double calculate_inductance(int node){
    return inductances[node];
}

// Calculate the current flowing into a given node
double calculate_current(int node){
    double capacitance = calculate_capacitance(node);
    double inductance = calculate_inductance(node);
    double conductance = calculate_conductance(node);

    double prev_voltage = prev_voltages[node];
    double voltage = voltages[node];

    currents[node] = (voltage - prev_voltage) * conductance + capacitance * (voltage - prev_voltage) / 0.001
                        + inductance * (voltage - 2.0 * prev_voltage + prev_voltages[node]) / 0.001;

    return currents[node];
}

// Update the voltage on a given node
void update_voltage(int node){
    double capacitance = calculate_capacitance(node);
    double inductance = calculate_inductance(node);
    double conductance = calculate_conductance(node);

    double prev_voltage = prev_voltages[node];
    double voltage = voltages[node];
    double current = currents[node];

    double next_voltage = ((current / capacitance) + (voltage - prev_voltage) * conductance 
                        + (2.0 * prev_voltage - voltage) / inductance) 
                        * (0.5 / ((1.0 / capacitance) + (1.0 / inductance)));

    prev_voltages[node] = voltage;
    voltages[node] = next_voltage;
}

int main(){
    int i;
    int num_steps;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    initialize_vars();

    for(i=0; i<num_nodes; i++){
        printf("\nEnter the capacitance (in Farads) for node %d: ", i+1);
        scanf("%lf", &capacitances[i]);
        printf("\nEnter the inductance (in Henrys) for node %d: ", i+1);
        scanf("%lf", &inductances[i]);
        printf("\nEnter the resistance (in Ohms) for node %d: ", i+1);
        scanf("%lf", &resistances[i]);
    }

    printf("\nEnter the number of steps to simulate: ");
    scanf("%d", &num_steps);

    for(i=0; i<num_steps; i++){
        int j;
        for(j=0; j<num_nodes; j++){
            double current = calculate_current(j);
            update_voltage(j);
        }
        printf("\nStep %d: ", i+1);
        printf("\nVoltages: ");
        for(j=0; j<num_nodes; j++){
            printf("%.3lf V ", voltages[j]);
        }
        printf("\nCurrents: ");
        for(j=0; j<num_nodes; j++){
            printf("%.3lf A ", currents[j]);
        }
        printf("\n");
    }

    return 0;
}