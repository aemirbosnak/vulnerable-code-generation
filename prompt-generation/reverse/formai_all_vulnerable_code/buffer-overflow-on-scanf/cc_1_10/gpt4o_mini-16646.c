//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    float value; // Value in ohms for resistors, farads for capacitors
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void addComponent(Circuit* circuit) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Circuit is full! Can't add more components.\n");
        return;
    }
    
    Component newComponent;
    printf("Enter component name (resistor/capacitor): ");
    scanf("%s", newComponent.name);
    
    printf("Enter component value: ");
    scanf("%f", &newComponent.value);
    
    circuit->components[circuit->count++] = newComponent;
    printf("Component added: %s, Value: %.2f\n", newComponent.name, newComponent.value);
}

void displayCircuit(Circuit* circuit) {
    printf("\nCurrent Circuit Configuration:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("Component %d - Name: %s, Value: %.2f\n", i + 1, circuit->components[i].name, circuit->components[i].value);
    }
}

float calculateImpedance(Circuit* circuit) {
    float totalImpedance = 0.0;
    // Assuming all components are in series for simplicity
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].name, "resistor") == 0) {
            totalImpedance += circuit->components[i].value;
        } else if (strcmp(circuit->components[i].name, "capacitor") == 0) {
            if (circuit->components[i].value > 0) {
                totalImpedance += 1.0 / (circuit->components[i].value); // Placeholder for capacitive reactance
            }
        }
    }
    return totalImpedance;
}

int main() {
    Circuit circuit;
    circuit.count = 0;

    int option;
    do {
        printf("\n--- Circuit Simulator ---\n");
        printf("1. Add Component\n");
        printf("2. Display Circuit\n");
        printf("3. Calculate Impedance\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addComponent(&circuit);
                break;
            case 2:
                displayCircuit(&circuit);
                break;
            case 3:
                {
                    float impedance = calculateImpedance(&circuit);
                    printf("Total Impedance: %.2f ohms\n", impedance);
                }
                break;
            case 4:
                printf("Exiting the simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);
    
    return 0;
}