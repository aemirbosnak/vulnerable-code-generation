//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define constants for the happy circuit simulator
#define MAX_COMPONENTS 50
#define MAX_NAME_LEN 20

// Enum for component types
enum ComponentType {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
};

// Struct to hold component details
typedef struct Component {
    char name[MAX_NAME_LEN];
    enum ComponentType type;
    union {
        double resistance; // for RESISTOR
        double capacitance; // for CAPACITOR
        double inductance; // for INDUCTOR
        double voltage; // for VOLTAGE_SOURCE
        double current; // for CURRENT_SOURCE
    } value;
} Component;

// List to store components
Component components[MAX_COMPONENTS];
int componentCount = 0;

// Function to add a component
void addComponent() {
    if (componentCount >= MAX_COMPONENTS) {
        printf("Cannot add more components! The circuit is full!\n");
        return;
    }

    Component comp;
    printf("Enter component name: ");
    scanf("%s", comp.name);
    
    printf("Select component type (0: Resistor, 1: Capacitor, 2: Inductor, 3: Voltage Source, 4: Current Source): ");
    int choice;
    scanf("%d", &choice);
    comp.type = (enum ComponentType) choice;

    switch(comp.type) {
        case RESISTOR:
            printf("Enter resistance (Ohms): ");
            scanf("%lf", &comp.value.resistance);
            break;
        case CAPACITOR:
            printf("Enter capacitance (Farads): ");
            scanf("%lf", &comp.value.capacitance);
            break;
        case INDUCTOR:
            printf("Enter inductance (Henrys): ");
            scanf("%lf", &comp.value.inductance);
            break;
        case VOLTAGE_SOURCE:
            printf("Enter voltage (Volts): ");
            scanf("%lf", &comp.value.voltage);
            break;
        case CURRENT_SOURCE:
            printf("Enter current (Amperes): ");
            scanf("%lf", &comp.value.current);
            break;
        default:
            printf("Unknown component type!\n");
            return;
    }

    components[componentCount++] = comp;
    printf("Component '%s' added successfully!\n", comp.name);
}

// Function to display all components
void displayComponents() {
    if (componentCount == 0) {
        printf("The circuit is empty! Let's add some components!\n");
        return;
    }

    printf("Current Circuit Components:\n");
    for (int i = 0; i < componentCount; i++) {
        Component* comp = &components[i];
        printf("Name: %s, Type: ", comp->name);
        switch(comp->type) {
            case RESISTOR:
                printf("Resistor, Value: %.2f Ohms\n", comp->value.resistance);
                break;
            case CAPACITOR:
                printf("Capacitor, Value: %.2f Farads\n", comp->value.capacitance);
                break;
            case INDUCTOR:
                printf("Inductor, Value: %.2f Henrys\n", comp->value.inductance);
                break;
            case VOLTAGE_SOURCE:
                printf("Voltage Source, Value: %.2f Volts\n", comp->value.voltage);
                break;
            case CURRENT_SOURCE:
                printf("Current Source, Value: %.2f Amperes\n", comp->value.current);
                break;
            default:
                printf("Unknown component type!\n");
                break;
        }
    }
}

// Function to simulate the circuit
void simulateCircuit() {
    if (componentCount == 0) {
        printf("The circuit is empty! Please add some components to simulate.\n");
        return;
    }

    printf("Simulating the circuit...\n");
    
    double totalResistance = 0;
    double totalCapacitance = 0;
    double totalInductance = 0;
    double totalVoltage = 0;
    double totalCurrent = 0;

    for (int i = 0; i < componentCount; i++) {
        Component* comp = &components[i];
        switch(comp->type) {
            case RESISTOR:
                totalResistance += comp->value.resistance;
                break;
            case CAPACITOR:
                totalCapacitance += comp->value.capacitance;
                break;
            case INDUCTOR:
                totalInductance += comp->value.inductance;
                break;
            case VOLTAGE_SOURCE:
                totalVoltage += comp->value.voltage;
                break;
            case CURRENT_SOURCE:
                totalCurrent += comp->value.current;
                break;
            default:
                break;
        }
    }

    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    printf("Total Capacitance: %.2f Farads\n", totalCapacitance);
    printf("Total Inductance: %.2f Henrys\n", totalInductance);
    printf("Total Voltage: %.2f Volts\n", totalVoltage);
    printf("Total Current: %.2f Amperes\n", totalCurrent);
}

int main() {
    int choice;
    printf("Welcome to the Happy Circuit Simulator!\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add Component\n2. Display Components\n3. Simulate Circuit\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addComponent();
                break;
            case 2:
                displayComponents();
                break;
            case 3:
                simulateCircuit();
                break;
            case 4:
                printf("Thank you for using the Happy Circuit Simulator! Have a sunny day!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}