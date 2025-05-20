//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: grateful
#include <stdio.h>

#define MAX_COMPONENTS 10

typedef struct {
    char name[20];
    float resistance; // in Ohms
} Resistor;

typedef struct {
    char name[20];
    float voltage; // in Volts
} VoltageSource;

typedef struct {
    Resistor resistors[MAX_COMPONENTS];
    VoltageSource voltageSource;
    int resistorCount;
} Circuit;

void addResistor(Circuit* circuit, const char* name, float resistance) {
    if (circuit->resistorCount < MAX_COMPONENTS) {
        Resistor resistor;
        snprintf(resistor.name, sizeof(resistor.name), "%s", name);
        resistor.resistance = resistance;
        circuit->resistors[circuit->resistorCount++] = resistor;
    } else {
        printf("Cannot add more resistors to the circuit!\n");
    }
}

void setVoltageSource(Circuit* circuit, const char* name, float voltage) {
    snprintf(circuit->voltageSource.name, sizeof(circuit->voltageSource.name), "%s", name);
    circuit->voltageSource.voltage = voltage;
}

float calculateTotalResistance(Circuit* circuit) {
    float totalResistance = 0.0;
    for (int i = 0; i < circuit->resistorCount; ++i) {
        totalResistance += circuit->resistors[i].resistance;
    }
    return totalResistance;
}

float calculateCurrent(Circuit* circuit) {
    float totalResistance = calculateTotalResistance(circuit);
    if (totalResistance != 0) {
        return circuit->voltageSource.voltage / totalResistance;
    } else {
        printf("Total resistance is zero. Cannot calculate current.\n");
        return 0;
    }
}

void displayCircuitInfo(Circuit* circuit) {
    printf("\n--- Circuit Information ---\n");
    printf("Voltage Source: %s (%.2f V)\n", circuit->voltageSource.name, circuit->voltageSource.voltage);
    printf("Resistors in the circuit:\n");
    for (int i = 0; i < circuit->resistorCount; ++i) {
        printf(" - %s: %.2f Ohm\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
    printf("--------------------------\n");
    float totalResistance = calculateTotalResistance(circuit);
    printf("Total Resistance: %.2f Ohm\n", totalResistance);
    float current = calculateCurrent(circuit);
    printf("Calculated Current: %.2f A\n", current);
    printf("--------------------------\n");
}

int main() {
    Circuit myCircuit;
    myCircuit.resistorCount = 0;

    printf("Creating a circuit...\n");

    setVoltageSource(&myCircuit, "Battery 1", 12.0);
    
    printf("Adding resistors to the circuit...\n");
    addResistor(&myCircuit, "R1", 220.0);
    addResistor(&myCircuit, "R2", 330.0);
    addResistor(&myCircuit, "R3", 470.0);
    
    displayCircuitInfo(&myCircuit);

    printf("\nThank you for simulating this circuit!\n");
    return 0;
}