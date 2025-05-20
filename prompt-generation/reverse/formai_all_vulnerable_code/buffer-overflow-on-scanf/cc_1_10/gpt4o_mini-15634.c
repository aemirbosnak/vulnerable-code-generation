//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_RESISTORS 10
#define MAX_VOLTAGES 10

typedef struct {
    double voltage; // Voltage of the power source
    double resistance[MAX_RESISTORS]; // Array to hold resistor values
    int num_resistors; 
} Circuit;

void add_resistor(Circuit *circuit, double resistance) {
    if (circuit->num_resistors < MAX_RESISTORS) {
        circuit->resistance[circuit->num_resistors] = resistance;
        circuit->num_resistors++;
        printf("Resistor added: %.2f Ohms\n", resistance);
    } else {
        printf("Max resistor limit reached!\n");
    }
}

void calculate_current(Circuit *circuit) {
    if (circuit->num_resistors == 0) {
        printf("No resistors in circuit to calculate current!\n");
        return;
    }

    double total_resistance = 0.0;
    for (int i = 0; i < circuit->num_resistors; i++) {
        total_resistance += circuit->resistance[i];
    }

    double current = circuit->voltage / total_resistance;
    printf("Total Resistance: %.2f Ohms\n", total_resistance);
    printf("Circuit Current: %.2f Amps\n", current);
}

void display_circuit(Circuit *circuit) {
    printf("Circuit Voltage: %.2f Volts\n", circuit->voltage);
    printf("Resistors in Circuit:\n");
    for (int i = 0; i < circuit->num_resistors; i++) {
        printf(" - Resistor #%d: %.2f Ohms\n", i + 1, circuit->resistance[i]);
    }
}

void init_circuit(Circuit *circuit, double voltage) {
    circuit->voltage = voltage;
    circuit->num_resistors = 0;
    printf("Circuit initialized with voltage: %.2f Volts\n", voltage);
}

int main() {
    Circuit myCircuit;
    double voltage;

    printf("Welcome to the Simple Circuit Simulator! Prepare to be SHOCKED!\n");
    
    printf("Enter the voltage of the circuit: ");
    if (scanf("%lf", &voltage) != 1 || voltage <= 0) {
        printf("Error: Please enter a valid positive voltage.\n");
        return 1;
    }
    
    init_circuit(&myCircuit, voltage);

    while (1) {
        char command[20];
        double resistance;

        printf("\nEnter command (add, calculate, display, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter the resistance value to add: ");
            if (scanf("%lf", &resistance) != 1 || resistance <= 0) {
                printf("Error: Please enter a valid positive resistance value.\n");
                continue;
            }
            add_resistor(&myCircuit, resistance);
        } else if (strcmp(command, "calculate") == 0) {
            calculate_current(&myCircuit);
        } else if (strcmp(command, "display") == 0) {
            display_circuit(&myCircuit);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Circuit Simulator. SHOCKED to see you go!\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    return 0;
}