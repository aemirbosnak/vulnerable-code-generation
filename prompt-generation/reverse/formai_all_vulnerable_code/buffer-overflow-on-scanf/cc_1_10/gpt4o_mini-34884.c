//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100

typedef struct {
    char type[10]; // "resistor" or "capacitor"
    double value;  // ohms for resistors, farads for capacitors
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

// Function prototypes
void addComponent(Circuit *circuit, const char *type, double value);
void displayCircuit(const Circuit *circuit);
double calculateTotalResistance(const Circuit *circuit);
double calculateTotalCapacitance(const Circuit *circuit);

int main() {
    Circuit circuit;
    circuit.count = 0;

    printf("🎉 Welcome to the Circuit Simulator! 🎉\n");
    printf("You can create a circuit by adding resistors and capacitors!\n");

    while (1) {
        char type[10];
        double value;

        printf("\nEnter component type (resistor/capacitor) or 'exit' to quit: ");
        scanf("%s", type);

        if (strcmp(type, "exit") == 0) {
            printf("🌟 Thank you for using the Circuit Simulator! 🌟\n");
            break;
        }

        printf("Enter the value of the %s: ", type);
        scanf("%lf", &value);

        addComponent(&circuit, type, value);
        displayCircuit(&circuit);
    }

    return 0;
}

void addComponent(Circuit *circuit, const char *type, double value) {
    if (circuit->count < MAX_COMPONENTS) {
        strcpy(circuit->components[circuit->count].type, type);
        circuit->components[circuit->count].value = value;
        circuit->count++;
        printf("✨ Added %s with value: %.2f\n", type, value);
    } else {
        printf("🚫 Cannot add more components! Max limit reached.\n");
    }
}

void displayCircuit(const Circuit *circuit) {
    printf("\n🛠️ Current Circuit Components 🛠️\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("%d. %s: %.2f\n", i + 1, circuit->components[i].type, circuit->components[i].value);
    }
    double totalResistance = calculateTotalResistance(circuit);
    double totalCapacitance = calculateTotalCapacitance(circuit);
    printf("🌈 Total Resistance: %.2f ohms\n", totalResistance);
    printf("🌈 Total Capacitance: %.2f farads\n", totalCapacitance);
}

double calculateTotalResistance(const Circuit *circuit) {
    double totalR = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "resistor") == 0) {
            totalR += circuit->components[i].value;
        }
    }
    return totalR;
}

double calculateTotalCapacitance(const Circuit *circuit) {
    double totalC = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "capacitor") == 0) {
            totalC += circuit->components[i].value;
        }
    }
    return totalC;
}