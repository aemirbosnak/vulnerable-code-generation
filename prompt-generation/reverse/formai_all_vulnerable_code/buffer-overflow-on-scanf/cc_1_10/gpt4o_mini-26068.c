//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100

typedef enum { RESISTOR, CAPACITOR } ComponentType;

typedef struct {
    ComponentType type;
    char name[20];
    double value; // in ohms for resistor, farads for capacitor
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void addComponent(Circuit *circuit) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Cannot add more components, circuit is full.\n");
        return;
    }

    Component newComponent;
    printf("Enter component type (resistor/capacitor): ");
    char type[20];
    scanf("%s", type);
    if (strcmp(type, "resistor") == 0) {
        newComponent.type = RESISTOR;
    } else if (strcmp(type, "capacitor") == 0) {
        newComponent.type = CAPACITOR;
    } else {
        printf("Invalid component type!\n");
        return;
    }

    printf("Enter component name: ");
    scanf("%s", newComponent.name);
    printf("Enter component value: ");
    scanf("%lf", &newComponent.value);

    circuit->components[circuit->count++] = newComponent;
    printf("Component added: %s (%s: %.2f)\n", newComponent.name,
           newComponent.type == RESISTOR ? "Resistor" : "Capacitor", newComponent.value);
}

double calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == RESISTOR) {
            totalResistance += circuit->components[i].value;
        }
    }
    return totalResistance;
}

void simulateCharge(Circuit *circuit, double voltage, double time, double timeStep) {
    printf("\nSimulating charge over a period of %.2f seconds with an input voltage of %.2fV:\n", time, voltage);
    printf("Time (s)\tCharge (C)\n");

    for (double t = 0; t <= time; t += timeStep) {
        double totalCapacitance = 0.0;
        for (int i = 0; i < circuit->count; i++) {
            if (circuit->components[i].type == CAPACITOR) {
                totalCapacitance += circuit->components[i].value;
            }
        }
        
        // Charge (Q = C * V)
        double charge = totalCapacitance * voltage;
        printf("%.2f\t\t%.2f\n", t, charge);
    }
}

void displayCircuit(Circuit *circuit) {
    printf("\nCircuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        const char *typeName = circuit->components[i].type == RESISTOR ? "Resistor" : "Capacitor";
        printf("%s: %s - %.2f\n", typeName, circuit->components[i].name, circuit->components[i].value);
    }
}

int main() {
    Circuit circuit;
    circuit.count = 0;
    int choice;
    
    do {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Component\n");
        printf("2. Display Circuit\n");
        printf("3. Calculate Total Resistance\n");
        printf("4. Simulate Charge\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addComponent(&circuit);
                break;
            case 2:
                displayCircuit(&circuit);
                break;
            case 3: {
                double totalResistance = calculateTotalResistance(&circuit);
                printf("\nTotal Resistance: %.2f ohms\n", totalResistance);
                break;
            }
            case 4: {
                double voltage, time, timeStep;
                printf("Enter input voltage (V): ");
                scanf("%lf", &voltage);
                printf("Enter total simulation time (s): ");
                scanf("%lf", &time);
                printf("Enter time step (s): ");
                scanf("%lf", &timeStep);
                simulateCharge(&circuit, voltage, time, timeStep);
                break;
            }
            case 5:
                printf("Exiting simulator.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}