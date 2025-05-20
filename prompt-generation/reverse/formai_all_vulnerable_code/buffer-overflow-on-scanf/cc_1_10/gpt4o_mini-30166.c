//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100

typedef enum { RESISTOR, CAPACITOR, VOLTAGE_SOURCE } ComponentType;

typedef struct {
    ComponentType type;
    char name[20];
    float value; // Resistance in Ohms or Capacitance in Farads, or Voltage in Volts
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int num_components;
} Circuit;

void addComponent(Circuit *circuit, ComponentType type, char *name, float value) {
    if (circuit->num_components < MAX_COMPONENTS) {
        circuit->components[circuit->num_components].type = type;
        snprintf(circuit->components[circuit->num_components].name, sizeof(circuit->components[circuit->num_components].name), "%s", name);
        circuit->components[circuit->num_components].value = value;
        circuit->num_components++;
    } else {
        printf("Maximum components reached!\n");
    }
}

void displayCircuit(Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->num_components; i++) {
        switch (circuit->components[i].type) {
            case RESISTOR:
                printf("Component %d: RESISTOR | Name: %s | Value: %.2f Ohm\n", i + 1, circuit->components[i].name, circuit->components[i].value);
                break;
            case CAPACITOR:
                printf("Component %d: CAPACITOR | Name: %s | Value: %.2f F\n", i + 1, circuit->components[i].name, circuit->components[i].value);
                break;
            case VOLTAGE_SOURCE:
                printf("Component %d: VOLTAGE SOURCE | Name: %s | Value: %.2f V\n", i + 1, circuit->components[i].name, circuit->components[i].value);
                break;
        }
    }
}

void calculateTotalResistance(Circuit *circuit) {
    float totalResistance = 0;
    int hasVoltage = 0;

    for (int i = 0; i < circuit->num_components; i++) {
        if (circuit->components[i].type == RESISTOR) {
            totalResistance += circuit->components[i].value;
        } else if (circuit->components[i].type == VOLTAGE_SOURCE) {
            hasVoltage = 1;
        }
    }

    if (hasVoltage) {
        printf("Total Resistance in the Circuit: %.2f Ohm\n", totalResistance);
    } else {
        printf("No Voltage Source found, unable to calculate resistance.\n");
    }
}

void freeResources(Circuit *circuit) {
    // Placeholder for resource cleanup if needed
}

int main() {
    Circuit circuit;
    circuit.num_components = 0;

    int choice;
    do {
        printf("\n--- Circuit Simulator Menu ---\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Add Voltage Source\n");
        printf("4. Display Circuit\n");
        printf("5. Calculate Total Resistance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        char name[20];
        float value;

        switch (choice) {
            case 1:
                printf("Enter Resistor Name: ");
                scanf("%s", name);
                printf("Enter Resistance Value (Ohms): ");
                scanf("%f", &value);
                addComponent(&circuit, RESISTOR, name, value);
                break;
            case 2:
                printf("Enter Capacitor Name: ");
                scanf("%s", name);
                printf("Enter Capacitance Value (Farads): ");
                scanf("%f", &value);
                addComponent(&circuit, CAPACITOR, name, value);
                break;
            case 3:
                printf("Enter Voltage Source Name: ");
                scanf("%s", name);
                printf("Enter Voltage Value (Volts): ");
                scanf("%f", &value);
                addComponent(&circuit, VOLTAGE_SOURCE, name, value);
                break;
            case 4:
                displayCircuit(&circuit);
                break;
            case 5:
                calculateTotalResistance(&circuit);
                break;
            case 6:
                printf("Exiting the simulator. Goodbye!\n");
                freeResources(&circuit);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}