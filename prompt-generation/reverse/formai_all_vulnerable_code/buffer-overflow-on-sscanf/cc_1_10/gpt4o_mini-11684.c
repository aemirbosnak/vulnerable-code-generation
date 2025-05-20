//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define constants for circuit components
#define RESISTOR 0
#define CAPACITOR 1
#define INDUCTOR 2

typedef struct {
    int type; // Type of the component (Resistor, Capacitor, Inductor)
    double value; // Value of the component (Resistance in Ohms, Capacitance in Farads, Inductance in Henries)
} Component;

typedef struct {
    Component* components; // Dynamic array of components
    int size; // Current number of components
    int capacity; // Maximum capacity of the component array
} Circuit;

Circuit* createCircuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->size = 0;
    circuit->capacity = 4; // Initial capacity
    circuit->components = (Component*)malloc(circuit->capacity * sizeof(Component));
    return circuit;
}

void addComponent(Circuit* circuit, int type, double value) {
    if (circuit->size >= circuit->capacity) {
        circuit->capacity *= 2; // Double the capacity
        circuit->components = (Component*)realloc(circuit->components, circuit->capacity * sizeof(Component));
    }
    circuit->components[circuit->size].type = type;
    circuit->components[circuit->size].value = value;
    circuit->size++;
}

void simulateCircuit(const Circuit* circuit) {
    double impedance = 0.0;
    double phaseAngle = 0.0;

    for (int i = 0; i < circuit->size; i++) {
        Component comp = circuit->components[i];
        if (comp.type == RESISTOR) {
            impedance += comp.value; // Simply add resistance
        } else if (comp.type == CAPACITOR) {
            impedance += 1.0 / (2 * M_PI * 60 * comp.value); // Capacitive reactance
            phaseAngle -= 90.0; // Phase lag for capacitor
        } else if (comp.type == INDUCTOR) {
            impedance += 2 * M_PI * 60 * comp.value; // Inductive reactance
            phaseAngle += 90.0; // Phase lead for inductor
        }
    }

    printf("Total Impedance: %.2f Ohms\n", impedance);
    printf("Phase Angle: %.2f degrees\n", phaseAngle);
}

void freeCircuit(Circuit* circuit) {
    free(circuit->components);
    free(circuit);
}

int main() {
    printf("Welcome to the Energetic Circuit Simulator!\n\n");
    
    Circuit* myCircuit = createCircuit();
    
    // User interaction for circuit creation
    char command[50];
    printf("Add components to the circuit:\n");
    printf("Type 'resistor X' to add a resistor of value X Ohms.\n");
    printf("Type 'capacitor X' to add a capacitor of value X Farads.\n");
    printf("Type 'inductor X' to add an inductor of value X Henries.\n");
    printf("Type 'simulate' to simulate the circuit and 'exit' to exit.\n");

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove the new line character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the simulator. Goodbye!\n");
            break;
        } else if (strcmp(command, "simulate") == 0) {
            simulateCircuit(myCircuit);
        } else {
            char type[20];
            double value;
            if (sscanf(command, "%s %lf", type, &value) == 2) {
                if (strcmp(type, "resistor") == 0) {
                    addComponent(myCircuit, RESISTOR, value);
                    printf("Added a resistor of %.2f Ohms!\n", value);
                } else if (strcmp(type, "capacitor") == 0) {
                    addComponent(myCircuit, CAPACITOR, value);
                    printf("Added a capacitor of %.5e Farads!\n", value);
                } else if (strcmp(type, "inductor") == 0) {
                    addComponent(myCircuit, INDUCTOR, value);
                    printf("Added an inductor of %.5e Henries!\n", value);
                } else {
                    printf("Unknown component type. Please try again!\n");
                }
            } else {
                printf("Invalid command format. Please try again!\n");
            }
        }
    }
    
    freeCircuit(myCircuit);
    return 0;
}