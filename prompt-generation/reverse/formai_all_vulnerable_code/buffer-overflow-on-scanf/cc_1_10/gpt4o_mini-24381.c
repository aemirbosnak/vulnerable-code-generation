//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define PI 3.14159265

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR
} ComponentType;

typedef struct {
    ComponentType type;
    double value; // in Ohms for Resistor, Farads for Capacitor, Henries for Inductor
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void add_component(Circuit *circuit, ComponentType type, double value) {
    if (circuit->count < MAX_COMPONENTS) {
        circuit->components[circuit->count].type = type;
        circuit->components[circuit->count].value = value;
        circuit->count++;
    } else {
        printf("Maximum components reached! Cannot add more.\n");
    }
}

double calculate_current(const Circuit *circuit, double voltage) {
    double total_resistance = 0.0;
    double total_capacitance = 0.0;
    double total_inductance = 0.0;

    for (int i = 0; i < circuit->count; i++) {
        switch (circuit->components[i].type) {
            case RESISTOR:
                total_resistance += circuit->components[i].value;
                break;
            case CAPACITOR:
                total_capacitance += circuit->components[i].value;
                break;
            case INDUCTOR:
                total_inductance += circuit->components[i].value;
                break;
        }
    }

    // Apply Ohm's law: V = IR
    if (total_resistance > 0) {
        return voltage / total_resistance;
    } else {
        return 0; // In case of no resistors in the circuit
    }
}

void show_circuit(const Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        switch (circuit->components[i].type) {
            case RESISTOR:
                printf("Resistor: %.2f Ohms\n", circuit->components[i].value);
                break;
            case CAPACITOR:
                printf("Capacitor: %.2f Farads\n", circuit->components[i].value);
                break;
            case INDUCTOR:
                printf("Inductor: %.2f Henries\n", circuit->components[i].value);
                break;
        }
    }
}

void simulate_circuit(const Circuit *circuit, double voltage) {
    double current = calculate_current(circuit, voltage);
    printf("Applied Voltage: %.2f V\n", voltage);
    printf("Calculated Current: %.2f A\n", current);
}

int main() {
    Circuit circuit = { .count = 0 };

    // Adding components
    add_component(&circuit, RESISTOR, 100.0);   // 100 Ohms
    add_component(&circuit, CAPACITOR, 0.01);   // 10 mF
    add_component(&circuit, INDUCTOR, 0.5);      // 0.5 H
    add_component(&circuit, RESISTOR, 50.0);     // 50 Ohms

    // Show the current circuit details
    show_circuit(&circuit);

    // Simulate with a voltage
    double applied_voltage;
    printf("Enter the voltage applied to the circuit: ");
    scanf("%lf", &applied_voltage);

    simulate_circuit(&circuit, applied_voltage);

    return 0;
}