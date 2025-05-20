//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 10

typedef struct {
    char type;  // 'R' for resistor
    float value; // resistance in ohms
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void addResistor(Circuit *circuit, float resistance) {
    if (circuit->count < MAX_COMPONENTS) {
        circuit->components[circuit->count].type = 'R';
        circuit->components[circuit->count].value = resistance;
        circuit->count++;
        printf("Added Resistor: %.2f Ohms\n", resistance);
    } else {
        printf("Circuit is full! Cannot add more components.\n");
    }
}

float calculateEquivalentResistance(Circuit *circuit) {
    float totalResistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        totalResistance += circuit->components[i].value;
    }
    return totalResistance;
}

void displayCircuit(Circuit *circuit) {
    printf("Current Circuit Configuration:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("Component %d: Type = %c, Value = %.2f Ohms\n", i + 1,
               circuit->components[i].type, circuit->components[i].value);
    }
}

void clearCircuit(Circuit *circuit) {
    circuit->count = 0;
    printf("Circuit cleared!\n");
}

int main() {
    Circuit myCircuit;
    myCircuit.count = 0;

    int choice;
    float resistance;

    while (1) {
        printf("\n===== Retro Circuit Simulator =====\n");
        printf("1. Add Resistor\n");
        printf("2. Calculate Equivalent Resistance\n");
        printf("3. Display Circuit\n");
        printf("4. Clear Circuit\n");
        printf("5. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Resistance Value (in Ohms): ");
                scanf("%f", &resistance);
                addResistor(&myCircuit, resistance);
                break;

            case 2:
                if (myCircuit.count == 0) {
                    printf("No components in the circuit!\n");
                } else {
                    float equivalentResistance = calculateEquivalentResistance(&myCircuit);
                    printf("Equivalent Resistance of the Circuit: %.2f Ohms\n", equivalentResistance);
                }
                break;

            case 3:
                if (myCircuit.count == 0) {
                    printf("No components to display!\n");
                } else {
                    displayCircuit(&myCircuit);
                }
                break;

            case 4:
                clearCircuit(&myCircuit);
                break;

            case 5:
                printf("Exiting... Thank you for using the Retro Circuit Simulator!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
                break;
        }
    }
    
    return 0;
}