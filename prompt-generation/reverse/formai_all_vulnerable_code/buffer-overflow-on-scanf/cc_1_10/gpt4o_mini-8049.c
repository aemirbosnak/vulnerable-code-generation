//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 10

typedef struct {
    char name[20];
    float resistance; // in ohms
} Resistor;

typedef struct {
    Resistor resistors[MAX_COMPONENTS];
    int count;
    float voltage; // in volts
} Circuit;

void add_resistor(Circuit *circuit, const char *name, float resistance) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Cannot add more resistors. Maximum limit reached.\n");
        return;
    }
    strncpy(circuit->resistors[circuit->count].name, name, 20);
    circuit->resistors[circuit->count].resistance = resistance;
    circuit->count++;
    printf("Added resistor: %s with resistance: %.2f Ohms\n", name, resistance);
}

float calculate_total_resistance(Circuit *circuit) {
    float total_resistance = 0;
    for (int i = 0; i < circuit->count; i++) {
        total_resistance += circuit->resistors[i].resistance;
    }
    return total_resistance;
}

float calculate_current(Circuit *circuit) {
    float total_resistance = calculate_total_resistance(circuit);
    if (total_resistance == 0) {
        printf("Total resistance is zero! Infinite current flow.\n");
        return 0;
    }
    return circuit->voltage / total_resistance;
}

void display_circuit_info(Circuit *circuit) {
    printf("\n--- Circuit Information ---\n");
    printf("Voltage Source: %.2f Volts\n", circuit->voltage);
    printf("Resistors in the circuit:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf(" - %s: %.2f Ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
    printf("Total Resistance: %.2f Ohms\n", calculate_total_resistance(circuit));
    printf("Current (I = V/R): %.2f Amps\n", calculate_current(circuit));
}

int main() {
    Circuit circuit;
    circuit.count = 0;
    circuit.voltage = 0;

    printf("Welcome to the Classical Circuit Simulator!\n");
    printf("Please enter the voltage source (in Volts): ");
    scanf("%f", &circuit.voltage);

    char command[50];
    
    while (1) {
        printf("\nEnter command (add_resistor <name> <resistance> / show / exit): ");
        scanf(" %[^\n]", command);

        if (strncmp(command, "add_resistor", 13) == 0) {
            char name[20];
            float resistance;
            sscanf(command + 14, "%s %f", name, &resistance);
            add_resistor(&circuit, name, resistance);
        } else if (strcmp(command, "show") == 0) {
            display_circuit_info(&circuit);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the simulator. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}