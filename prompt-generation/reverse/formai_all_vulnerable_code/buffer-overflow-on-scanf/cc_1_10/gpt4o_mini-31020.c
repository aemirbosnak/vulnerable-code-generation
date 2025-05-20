//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char type; // 'R' for Resistor, 'C' for Capacitor, 'L' for Inductor
    double value; // ohms for resistors, farads for capacitors, henrys for inductors
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void addComponent(Circuit *circuit, const char *name, char type, double value) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Cannot add more components. Maximum limit reached.\n");
        return;
    }
    strcpy(circuit->components[circuit->count].name, name);
    circuit->components[circuit->count].type = type;
    circuit->components[circuit->count].value = value;
    circuit->count++;
    printf("Added component: %s (Type: %c, Value: %.2f)\n", name, type, value);
}

void displayCircuit(Circuit *circuit) {
    printf("\nCurrent Circuit Configuration:\n");
    printf("----------------------------------\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("Component %d: %s, Type: %c, Value: %.2f\n", 
               i + 1, 
               circuit->components[i].name, 
               circuit->components[i].type, 
               circuit->components[i].value);
    }
    printf("----------------------------------\n");
}

double calculateEquivalentResistance(Circuit *circuit) {
    double totalResistance = 0;
    double parallelResistance = 0;
    int resistorsCount = 0;

    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'R') {
            totalResistance += circuit->components[i].value;
            resistorsCount++;
        }
    }
    
    if (resistorsCount > 0) {
        return totalResistance; // Simple assumption: series resistance
    } else {
        return 0;
    }
}

void simulateCircuit(Circuit *circuit) {
    double equivalentResistance = calculateEquivalentResistance(circuit);
    if (equivalentResistance > 0) {
        printf("The equivalent resistance of the circuit is: %.2f ohms\n", equivalentResistance);
    } else {
        printf("No resistors present in the circuit.\n");
    }
}

int main() {
    Circuit circuit;
    circuit.count = 0;

    // Let's get curious about circuit components
    char input[MAX_NAME_LENGTH];
    char type;
    double value;
    int choice;

    while (1) {
        printf("Circuit Simulator Menu:\n");
        printf("1. Add a component\n");
        printf("2. Display circuit\n");
        printf("3. Simulate circuit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                // Curious minds want to know what component we're adding!
                printf("Enter component name: ");
                scanf("%s", input);
                printf("Enter component type (R for Resistor, C for Capacitor, L for Inductor): ");
                scanf(" %c", &type);
                printf("Enter component value: ");
                scanf("%lf", &value);
                addComponent(&circuit, input, type, value);
                break;

            case 2:
                displayCircuit(&circuit);
                break;

            case 3:
                simulateCircuit(&circuit);
                break;

            case 4:
                printf("Exiting circuit simulator. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}