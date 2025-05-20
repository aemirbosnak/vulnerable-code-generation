//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double value;  // Value can be resistance (ohms), capacitance (farads), or inductance (henries)
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int componentCount;
} Circuit;

void initCircuit(Circuit* circuit) {
    circuit->componentCount = 0;
}

void addComponent(Circuit* circuit, const char* name, double value) {
    if (circuit->componentCount < MAX_COMPONENTS) {
        strncpy(circuit->components[circuit->componentCount].name, name, MAX_NAME_LENGTH);
        circuit->components[circuit->componentCount].value = value;
        circuit->componentCount++;
    } else {
        printf("Circuit can hold a maximum of %d components.\n", MAX_COMPONENTS);
    }
}

void showComponents(const Circuit* circuit) {
    for (int i = 0; i < circuit->componentCount; i++) {
        printf("Component %d: %s, Value: %.2f\n", i + 1, circuit->components[i].name, circuit->components[i].value);
    }
}

double calculateTotalResistance(const Circuit* circuit) {
    double totalResistance = 0;
    for (int i = 0; i < circuit->componentCount; i++) {
        totalResistance += circuit->components[i].value;  // Assumes series configuration
    }
    return totalResistance;
}

double calculateTotalCapacitance(const Circuit* circuit) {
    double totalCapacitance = 0;
    for (int i = 0; i < circuit->componentCount; i++) {
        totalCapacitance += 1 / circuit->components[i].value; // Assumes parallel configuration
    }
    return totalCapacitance > 0 ? 1 / totalCapacitance : 0; // returns in farads
}

void displayMenu() {
    printf("\n=== Circuit Simulator ===\n");
    printf("1. Add Component\n");
    printf("2. Show Components\n");
    printf("3. Calculate Total Resistance\n");
    printf("4. Calculate Total Capacitance\n");
    printf("5. Exit\n");
    printf("=========================\n");
}

int main() {
    Circuit circuit;
    initCircuit(&circuit);
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        char name[MAX_NAME_LENGTH];
        double value;
        
        switch (choice) {
            case 1:
                printf("Enter component name: ");
                scanf("%s", name);
                printf("Enter component value: ");
                scanf("%lf", &value);
                addComponent(&circuit, name, value);
                break;
            case 2:
                if (circuit.componentCount > 0) {
                    showComponents(&circuit);
                } else {
                    printf("No components in the circuit yet.\n");
                }
                break;
            case 3:
                if (circuit.componentCount > 0) {
                    double totalResistance = calculateTotalResistance(&circuit);
                    printf("Total Resistance (Series): %.2f ohms\n", totalResistance);
                } else {
                    printf("No components to calculate resistance from.\n");
                }
                break;
            case 4:
                if (circuit.componentCount > 0) {
                    double totalCapacitance = calculateTotalCapacitance(&circuit);
                    printf("Total Capacitance (Parallel): %.6f farads\n", totalCapacitance);
                } else {
                    printf("No components to calculate capacitance from.\n");
                }
                break;
            case 5:
                printf("Exiting the Circuit Simulator.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}