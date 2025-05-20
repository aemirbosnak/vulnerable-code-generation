//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 10

typedef struct {
    char name[20];
    double resistance; // in Ohms
    double capacitance; // in Farads
    double inductance; // in Henrys
    double voltage; // in Volts
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void addComponent(Circuit *circuit, const char *name, double resistance, double capacitance, double inductance, double voltage) {
    if (circuit->count < MAX_COMPONENTS) {
        Component newComponent;
        snprintf(newComponent.name, sizeof(newComponent.name), "%s", name);
        newComponent.resistance = resistance;
        newComponent.capacitance = capacitance;
        newComponent.inductance = inductance;
        newComponent.voltage = voltage;
        
        circuit->components[circuit->count] = newComponent;
        circuit->count++;
    } else {
        printf("Alas! The circuit can endure no more components...\n");
    }
}

void displayCircuit(const Circuit *circuit) {
    printf("O! What a piece of work is this Circuit!\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("Component %d: %s\n", i + 1, circuit->components[i].name);
        printf("\tResistance: %.2f Ohms\n", circuit->components[i].resistance);
        printf("\tCapacitance: %.2f Farads\n", circuit->components[i].capacitance);
        printf("\tInductance: %.2f Henrys\n", circuit->components[i].inductance);
        printf("\tVoltage: %.2f Volts\n", circuit->components[i].voltage);
    }
}

double calculateTotalResistance(const Circuit *circuit) {
    double totalResistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        totalResistance += circuit->components[i].resistance;
    }
    return totalResistance;
}

double calculateVoltageDrop(const Circuit *circuit, double totalResistance) {
    double totalVoltage = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        totalVoltage += circuit->components[i].voltage;
    }
    return totalVoltage * (totalResistance / totalVoltage);
}

void tragicEnd() {
    printf("Alas! The noble circuit hath met its fate.\n");
    printf("May the currents rest in peace.\n");
}

int main() {
    Circuit myCircuit;
    myCircuit.count = 0;
    
    addComponent(&myCircuit, "Romeo", 100.0, 0.001, 0.0, 5.0);
    addComponent(&myCircuit, "Juliet", 150.0, 0.002, 0.0, 10.0);
    addComponent(&myCircuit, "Mercutio", 200.0, 0.0015, 0.0, 4.0);
    
    displayCircuit(&myCircuit);
    
    double totalResistance = calculateTotalResistance(&myCircuit);
    printf("Total Resistance in this tragic circuit: %.2f Ohms\n", totalResistance);
    
    double voltageDrop = calculateVoltageDrop(&myCircuit, totalResistance);
    printf("Voltage Drop across the components: %.2f Volts\n", voltageDrop);
    
    tragicEnd();
    
    return 0;
}