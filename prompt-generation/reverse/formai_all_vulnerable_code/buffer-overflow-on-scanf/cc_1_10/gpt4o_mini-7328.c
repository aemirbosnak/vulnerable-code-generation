//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float resistValue;  // Ohms, only for resistors
} Resistor;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float capacValue;  // Farads, only for capacitors
} Capacitor;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float voltValue;   // Volts, only for voltage sources
} VoltageSource;

typedef struct {
    Resistor resistors[MAX_COMPONENTS];
    Capacitor capacitors[MAX_COMPONENTS];
    VoltageSource voltageSources[MAX_COMPONENTS];
    int resistorCount;
    int capacitorCount;
    int voltageSourceCount;
} Circuit;

void addResistor(Circuit* circuit) {
    if (circuit->resistorCount >= MAX_COMPONENTS) {
        printf("Maximum number of resistors reached.\n");
        return;
    }
    Resistor r;
    printf("Enter resistor name: ");
    scanf("%s", r.name);
    printf("Enter resistor value (in Ohms): ");
    scanf("%f", &r.resistValue);
    circuit->resistors[circuit->resistorCount++] = r;
    printf("Resistor %s added.\n", r.name);
}

void addCapacitor(Circuit* circuit) {
    if (circuit->capacitorCount >= MAX_COMPONENTS) {
        printf("Maximum number of capacitors reached.\n");
        return;
    }
    Capacitor c;
    printf("Enter capacitor name: ");
    scanf("%s", c.name);
    printf("Enter capacitor value (in Farads): ");
    scanf("%f", &c.capacValue);
    circuit->capacitors[circuit->capacitorCount++] = c;
    printf("Capacitor %s added.\n", c.name);
}

void addVoltageSource(Circuit* circuit) {
    if (circuit->voltageSourceCount >= MAX_COMPONENTS) {
        printf("Maximum number of voltage sources reached.\n");
        return;
    }
    VoltageSource v;
    printf("Enter voltage source name: ");
    scanf("%s", v.name);
    printf("Enter voltage value (in Volts): ");
    scanf("%f", &v.voltValue);
    circuit->voltageSources[circuit->voltageSourceCount++] = v;
    printf("Voltage source %s added.\n", v.name);
}

float calculateTotalResistance(Circuit* circuit) {
    float totalResistance = 0.0;
    for (int i = 0; i < circuit->resistorCount; i++) {
        totalResistance += circuit->resistors[i].resistValue;
    }
    return totalResistance;
}

float calculateTotalCapacitance(Circuit* circuit) {
    float totalCapacitance = 0.0;
    for (int i = 0; i < circuit->capacitorCount; i++) {
        totalCapacitance += circuit->capacitors[i].capacValue;
    }
    return totalCapacitance;
}

void displayCircuitInfo(Circuit* circuit) {
    printf("\nCircuit Information:\n");

    printf("Resistors:\n");
    for (int i = 0; i < circuit->resistorCount; i++) {
        printf(" - %s: %.2f Ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistValue);
    }

    printf("\nCapacitors:\n");
    for (int i = 0; i < circuit->capacitorCount; i++) {
        printf(" - %s: %.6f Farads\n", circuit->capacitors[i].name, circuit->capacitors[i].capacValue);
    }

    printf("\nVoltage Sources:\n");
    for (int i = 0; i < circuit->voltageSourceCount; i++) {
        printf(" - %s: %.2f Volts\n", circuit->voltageSources[i].name, circuit->voltageSources[i].voltValue);
    }

    float totalResistance = calculateTotalResistance(circuit);
    float totalCapacitance = calculateTotalCapacitance(circuit);
    printf("\nTotal Resistance: %.2f Ohms\n", totalResistance);
    printf("Total Capacitance: %.6f Farads\n", totalCapacitance);
}

int main() {
    Circuit circuit = {0}; // Initialize circuit with 0 components
    int choice;

    while (1) {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Add Voltage Source\n");
        printf("4. Display Circuit Information\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addResistor(&circuit);
                break;
            case 2:
                addCapacitor(&circuit);
                break;
            case 3:
                addVoltageSource(&circuit);
                break;
            case 4:
                displayCircuitInfo(&circuit);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}