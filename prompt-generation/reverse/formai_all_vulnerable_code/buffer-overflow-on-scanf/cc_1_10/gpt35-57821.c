//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
/*
 * This program is a Classical Circuit Simulator that allows the user to input their own circuit 
 * and simulate it. It uses a protected style to ensure the user does not enter inputs that could 
 * cause errors or crashes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRCUIT_SIZE 100  // Maximum size of the circuit
#define PI 3.14159265358979323846

// Struct representing an electrical component
typedef struct Component {
    char type;   // Type of component (R, C, L)
    double value;   // Value of the component in ohms, farads, or henries
} Component;

// Function prototypes
void getVoltage(Component* circuit, int size, double* voltage);
void getCurrent(Component* circuit, int size, double* current);
void printCircuit(Component* circuit, int size);

int main() {
    Component circuit[MAX_CIRCUIT_SIZE];
    int size;
    double voltage, current;

    // Get circuit size from user
    printf("Enter circuit size (max %d): ", MAX_CIRCUIT_SIZE);
    scanf("%d", &size);

    // Check circuit size is valid
    if (size <= 0 || size > MAX_CIRCUIT_SIZE) {
        printf("Invalid circuit size.\n");
        return 1;
    }

    // Get components from user
    for (int i = 0; i < size; i++) {
        printf("Enter component type %d (R, C, L): ", i+1);
        char type;
        scanf(" %c", &type);

        // Check component type is valid
        if (type != 'R' && type != 'C' && type != 'L') {
            printf("Invalid component type.\n");
            return 1;
        }

        printf("Enter component value %d: ", i+1);
        double value;
        scanf("%lf", &value);

        // Check component value is valid
        if (value < 0) {
            printf("Invalid component value.\n");
            return 1;
        }

        circuit[i].type = type;
        circuit[i].value = value;
    }

    // Get voltage from user
    getVoltage(circuit, size, &voltage);

    // Get current in circuit
    getCurrent(circuit, size, &current);

    // Print circuit components and values
    printf("\nCircuit components and values:\n");
    printCircuit(circuit, size);

    // Print voltage and current
    printf("\nCircuit voltage: %lf V\n", voltage);
    printf("Circuit current: %lf A\n", current);
    
    return 0;
}

// Function to get voltage from user
void getVoltage(Component* circuit, int size, double* voltage) {
    printf("Enter voltage: ");
    scanf("%lf", voltage);

    // Check voltage is valid
    if (*voltage < 0) {
        printf("Invalid voltage.\n");
        exit(1);
    }
}

// Function to calculate current in circuit
void getCurrent(Component* circuit, int size, double* current) {
    *current = 0;
    for (int i = 0; i < size; i++) {
        switch(circuit[i].type) {
            case 'R':   // calculate current for resistor
                *current += *current * circuit[i].value;
                break;
            case 'C':   // calculate current for capacitor
                *current += *current * cos(PI/2);
                break;
            case 'L':   // calculate current for inductor
                *current += *current * sin(PI/2);
                break;
        }
    }

    // Check current is valid
    if (*current < 0) {
        printf("Invalid current.\n");
        exit(1);
    }
}

// Function to print circuit components and values
void printCircuit(Component* circuit, int size) {
    for (int i = 0; i < size; i++) {
        printf("Component %d: %c %lf\n", i+1, circuit[i].type, circuit[i].value);
    }
}