//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant for maximum components
#define MAX_COMPONENTS 100

// Enumeration for component types
typedef enum {
    RESISTOR,
    CAPACITOR,
    VOLTAGE_SOURCE
} ComponentType;

// Structure to represent a circuit component
typedef struct {
    ComponentType type;
    char name[10];
    double value; // Ohms for resistors, Farads for capacitors, Volts for voltage sources
} Component;

// Function prototypes
void addComponent(Component *components, int *count);
void calculateCircuitProperties(Component *components, int count);
void displayComponents(Component *components, int count);
void clearInputBuffer();

int main() {
    Component components[MAX_COMPONENTS];
    int componentCount = 0;
    int choice;

    while (1) {
        printf("\n=== Classical Circuit Simulator ===\n");
        printf("1. Add Component\n");
        printf("2. Calculate Circuit Properties\n");
        printf("3. Display Components\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            addComponent(components, &componentCount);
            break;
        case 2:
            calculateCircuitProperties(components, componentCount);
            break;
        case 3:
            displayComponents(components, componentCount);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addComponent(Component *components, int *count) {
    if (*count >= MAX_COMPONENTS) {
        printf("Circuit is full! Cannot add more components.\n");
        return;
    }

    Component newComponent;
    int type;

    printf("Enter component type (0 - Resistor, 1 - Capacitor, 2 - Voltage Source): ");
    scanf("%d", &type);
    clearInputBuffer();

    printf("Enter component name (e.g. R1, C1, V1): ");
    fgets(newComponent.name, sizeof(newComponent.name), stdin);
    newComponent.name[strcspn(newComponent.name, "\n")] = 0;  // Remove trailing newline

    printf("Enter component value: ");
    scanf("%lf", &newComponent.value);

    switch (type) {
    case 0:
        newComponent.type = RESISTOR;
        break;
    case 1:
        newComponent.type = CAPACITOR;
        break;
    case 2:
        newComponent.type = VOLTAGE_SOURCE;
        break;
    default:
        printf("Invalid component type! Component not added.\n");
        return;
    }
    
    components[*count] = newComponent;
    (*count)++;
    printf("Component %s added successfully!\n", newComponent.name);
}

void calculateCircuitProperties(Component *components, int count) {
    double totalResistance = 0.0;
    double totalCapacitance = 0.0;
    double totalVoltage = 0.0;

    for (int i = 0; i < count; i++) {
        switch (components[i].type) {
        case RESISTOR:
            totalResistance += components[i].value;
            break;
        case CAPACITOR:
            totalCapacitance += components[i].value;
            break;
        case VOLTAGE_SOURCE:
            totalVoltage += components[i].value;
            break;
        }
    }

    printf("Total Resistance (R): %.2f Ohms\n", totalResistance);
    printf("Total Capacitance (C): %.2f Farads\n", totalCapacitance);
    printf("Total Voltage (V): %.2f Volts\n", totalVoltage);
}

void displayComponents(Component *components, int count) {
    printf("\n=== Displaying Components ===\n");
    for (int i = 0; i < count; i++) {
        printf("Component Name: %s, Value: %.2f, Type: ", components[i].name, components[i].value);
        switch (components[i].type) {
        case RESISTOR:
            printf("Resistor\n");
            break;
        case CAPACITOR:
            printf("Capacitor\n");
            break;
        case VOLTAGE_SOURCE:
            printf("Voltage Source\n");
            break;
        }
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}