//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include <stdio.h>
#include <math.h>

// Define the circuit components
#define CAPACITOR 0
#define INDUCTOR 1
#define RESISTOR 2
#define SWITCH 3

// Define the circuit variables
int num_components;
int component_type[5];
double component_value[5];
double component_voltage[5];

// Define the circuit equations
double circuit_voltage[5];
double circuit_current[5];
double circuit_time;

// Define the circuit simulation functions
void initialize_circuit(void);
void update_circuit(double dt);
void print_circuit_status(void);

// Main function
int main(void) {
    // Initialize the circuit
    initialize_circuit();
    
    // Simulate the circuit
    for (circuit_time = 0; circuit_time < 1; circuit_time += 0.01) {
        update_circuit(0.01);
        print_circuit_status();
    }
    
    // Finalize the circuit
    initialize_circuit();
    
    return 0;
}

// Initialize the circuit
void initialize_circuit(void) {
    // Read the component types and values from input
    printf("Enter the number of components (1-5): ");
    scanf("%d", &num_components);
    
    for (int i = 0; i < num_components; i++) {
        printf("Enter the component type (0-3): ");
        scanf("%d", &component_type[i]);
        
        if (component_type[i] == CAPACITOR) {
            printf("Enter the capacitance value: ");
            scanf("%lf", &component_value[i]);
        } else if (component_type[i] == INDUCTOR) {
            printf("Enter the inductance value: ");
            scanf("%lf", &component_value[i]);
        } else if (component_type[i] == RESISTOR) {
            printf("Enter the resistance value: ");
            scanf("%lf", &component_value[i]);
        } else if (component_type[i] == SWITCH) {
            printf("Enter the switch state (0/1): ");
            scanf("%d", &component_value[i]);
        } else {
            printf("Invalid component type.\n");
        }
    }
    
    // Initialize the circuit variables
    for (int i = 0; i < num_components; i++) {
        component_voltage[i] = 0.0;
        circuit_voltage[i] = 0.0;
        circuit_current[i] = 0.0;
    }
    
    // Initialize the circuit equations
    for (int i = 0; i < num_components; i++) {
        if (component_type[i] == CAPACITOR) {
            circuit_voltage[i] = component_voltage[i] / component_value[i];
        } else if (component_type[i] == INDUCTOR) {
            circuit_voltage[i] = -1.0 / component_value[i] * circuit_current[i];
        } else if (component_type[i] == RESISTOR) {
            circuit_voltage[i] = component_voltage[i] / component_value[i];
        } else if (component_type[i] == SWITCH) {
            circuit_voltage[i] = component_voltage[i];
        } else {
            printf("Invalid component type.\n");
        }
    }
    
    // Initialize the circuit simulation variables
    circuit_current[0] = 0.0;
    circuit_time = 0.0;
}

// Update the circuit
void update_circuit(double dt) {
    // Calculate the new circuit voltage and current
    for (int i = 0; i < num_components; i++) {
        if (component_type[i] == CAPACITOR) {
            circuit_voltage[i] = component_voltage[i] + (dt * component_voltage[i]);
        } else if (component_type[i] == INDUCTOR) {
            circuit_voltage[i] = circuit_voltage[i] + (dt * circuit_current[i]);
        } else if (component_type[i] == RESISTOR) {
            circuit_voltage[i] = circuit_voltage[i] + (dt * circuit_current[i]);
        } else if (component_type[i] == SWITCH) {
            circuit_voltage[i] = component_voltage[i];
        } else {
            printf("Invalid component type.\n");
        }
    }
    
    // Calculate the new circuit current
    for (int i = 0; i < num_components; i++) {
        circuit_current[i] = circuit_voltage[i] / component_value[i];
    }
}

// Print the circuit status
void print_circuit_status(void) {
    printf("Time: %lf\n", circuit_time);
    printf("Voltage: ");
    for (int i = 0; i < num_components; i++) {
        printf("%.2lf ", circuit_voltage[i]);
    }
    printf("\n");
    printf("Current: ");
    for (int i = 0; i < num_components; i++) {
        printf("%.2lf ", circuit_current[i]);
    }
    printf("\n");
}