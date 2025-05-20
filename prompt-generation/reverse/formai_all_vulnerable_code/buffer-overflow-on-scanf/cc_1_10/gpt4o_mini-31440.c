//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100

typedef struct {
    char type;
    double value;
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void addComponent(Circuit *circuit, char type, double value) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Cannot add more components. Maximum limit reached.\n");
        return;
    }
    circuit->components[circuit->count].type = type;
    circuit->components[circuit->count].value = value;
    circuit->count++;
}

void displayCircuit(Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("Component %d: Type = %c, Value = %.2f\n", i + 1, 
                circuit->components[i].type, circuit->components[i].value);
    }
}

double calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0.0;
    int resistorCount = 0;

    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'R') {
            totalResistance += circuit->components[i].value;
            resistorCount++;
        }
    }

    return (resistorCount > 0) ? totalResistance : -1; // -1 indicates no resistors
}

void simulateCircuit(Circuit *circuit, double voltage) {
    double totalResistance = calculateTotalResistance(circuit);

    if (totalResistance < 0) {
        printf("No resistors in the circuit to simulate.\n");
        return;
    }

    double current = voltage / totalResistance;
    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    printf("Applied Voltage: %.2f Volts\n", voltage);
    printf("Total Current: %.2f Amps\n", current);

    printf("Current through each resistor:\n");
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'R') {
            double currentThroughResistor = voltage / circuit->components[i].value;
            printf("Current through Resistor %d (%.2f Ohm): %.2f A\n", 
                   i + 1, circuit->components[i].value, currentThroughResistor);
        }
    }
}

int main() {
    Circuit circuit;
    circuit.count = 0;

    int choice;
    char type;
    double value;
    double voltage;

    while (1) {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Component\n");
        printf("2. Display Circuit\n");
        printf("3. Simulate Circuit\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter component type (R for Resistor, C for Capacitor, L for Inductor): ");
                scanf(" %c", &type);
                printf("Enter component value: ");
                scanf("%lf", &value);
                addComponent(&circuit, type, value);
                break;

            case 2:
                displayCircuit(&circuit);
                break;

            case 3:
                printf("Enter the applied voltage (in Volts): ");
                scanf("%lf", &voltage);
                simulateCircuit(&circuit, voltage);
                break;

            case 4:
                printf("Exiting the simulator.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}