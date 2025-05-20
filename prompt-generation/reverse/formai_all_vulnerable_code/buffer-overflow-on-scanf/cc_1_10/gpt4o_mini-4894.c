//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double value;  // If resistor (in Ohms), capacitor (in Farads), etc.
} Component;

typedef struct {
    Component *components[MAX_COMPONENTS];
    int count;
} Circuit;

// Function prototypes
Circuit *createCircuit();
void addComponent(Circuit *circuit, char *name, double value);
void displayCircuit(Circuit *circuit);
double calculateTotalResistance(Circuit *circuit);
void freeCircuit(Circuit *circuit);

// Entry point
int main() {
    Circuit *circuit = createCircuit();
    int choice;
    char name[MAX_NAME_LENGTH];
    double value;

    while (1) {
        printf("\n--- Circuit Simulator ---\n");
        printf("1. Add Resistor\n");
        printf("2. Display Circuit\n");
        printf("3. Calculate Total Resistance\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Resistor Name: ");
                scanf("%s", name);
                printf("Enter Resistor Value (Ohms): ");
                scanf("%lf", &value);
                addComponent(circuit, name, value);
                break;
            case 2:
                displayCircuit(circuit);
                break;
            case 3:
                printf("Total Resistance: %.2f Ohms\n", calculateTotalResistance(circuit));
                break;
            case 4:
                freeCircuit(circuit);
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
}

Circuit *createCircuit() {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->count = 0;
    return circuit;
}

void addComponent(Circuit *circuit, char *name, double value) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Circuit is full! Cannot add more components.\n");
        return;
    }
    Component *component = (Component *)malloc(sizeof(Component));
    strncpy(component->name, name, MAX_NAME_LENGTH);
    component->value = value;
    circuit->components[circuit->count++] = component;
    printf("Added: %s, Value: %.2f Ohms\n", name, value);
}

void displayCircuit(Circuit *circuit) {
    printf("\n--- Circuit Components ---\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("Component %d: Name: %s, Value: %.2f Ohms\n", i + 1, 
               circuit->components[i]->name, circuit->components[i]->value);
    }
}

double calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        totalResistance += circuit->components[i]->value;
    }
    return totalResistance;
}

void freeCircuit(Circuit *circuit) {
    for (int i = 0; i < circuit->count; i++) {
        free(circuit->components[i]);
    }
    free(circuit);
}