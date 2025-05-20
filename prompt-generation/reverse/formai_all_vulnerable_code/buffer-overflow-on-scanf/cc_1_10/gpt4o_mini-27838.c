//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMPONENTS 10

typedef struct {
    char name[20];
    double resistance; // in ohms
} Resistor;

typedef struct {
    Resistor resistors[MAX_COMPONENTS];
    int count;
} Circuit;

void initializeCircuit(Circuit *circuit) {
    circuit->count = 0;
    printf("Circuit initialized. Ready to add components!\n");
}

void addResistor(Circuit *circuit, const char *name, double resistance) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Error: Maximum number of components reached!\n");
        return;
    }
    strcpy(circuit->resistors[circuit->count].name, name);
    circuit->resistors[circuit->count].resistance = resistance;
    circuit->count++;
    printf("Resistor %s with resistance %.2f ohms added to the circuit.\n", name, resistance);
}

double calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        totalResistance += circuit->resistors[i].resistance;
    }
    return totalResistance;
}

void displayCircuit(Circuit *circuit) {
    printf("\nCircuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("  %s: %.2f ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
    printf("Total Resistance: %.2f ohms\n\n", calculateTotalResistance(circuit));
}

void clearCircuit(Circuit *circuit) {
    circuit->count = 0;
    printf("Circuit cleared. You can add new components!\n");
}

int main() {
    Circuit myCircuit;
    char name[20];
    double resistance;
    int choice;

    initializeCircuit(&myCircuit);

    while (1) {
        printf("Retro Circuit Simulator\n");
        printf("========================\n");
        printf("1. Add Resistor\n");
        printf("2. Calculate Total Resistance\n");
        printf("3. Display Circuit\n");
        printf("4. Clear Circuit\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistor name: ");
                scanf("%s", name);
                printf("Enter resistance value (ohms): ");
                scanf("%lf", &resistance);
                addResistor(&myCircuit, name, resistance);
                break;
            case 2:
                printf("Total Resistance: %.2f ohms\n\n", calculateTotalResistance(&myCircuit));
                sleep(1);
                break;
            case 3:
                displayCircuit(&myCircuit);
                sleep(2);
                break;
            case 4:
                clearCircuit(&myCircuit);
                break;
            case 5:
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please select again.\n");
                sleep(1);
                break;
        }
    }
    return 0;
}