//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 100

typedef struct {
    double resistance;
    double capacitance;
    double inductance;
} Component;

typedef struct {
    int num_components;
    Component components[MAX_COMPONENTS];
} Circuit;

void add_component(Circuit *circuit, Component component) {
    circuit->components[circuit->num_components++] = component;
}

void print_circuit(Circuit *circuit) {
    printf("Circuit:\n");
    for (int i = 0; i < circuit->num_components; i++) {
        printf("  Component %d: R=%f C=%f L=%f\n", i+1, circuit->components[i].resistance, circuit->components[i].capacitance, circuit->components[i].inductance);
    }
}

void simulate_circuit(Circuit *circuit, double voltage, double frequency) {
    for (int i = 0; i < circuit->num_components; i++) {
        Component component = circuit->components[i];
        double resistance = component.resistance;
        double capacitance = component.capacitance;
        double inductance = component.inductance;
        double impedance = resistance + 1/(2*M_PI*frequency*capacitance) - 1/(M_PI*frequency*inductance);
        double current = voltage / impedance;
        printf("  Component %d: V=%f A=%f\n", i+1, voltage, current);
        voltage -= current * impedance;
    }
}

int main() {
    Circuit circuit = {0};

    add_component(&circuit, (Component){1000, 0, 0});
    add_component(&circuit, (Component){0, 1e-6, 0});
    add_component(&circuit, (Component){0, 0, 1e-3});
    add_component(&circuit, (Component){0, 0, 0});

    print_circuit(&circuit);

    simulate_circuit(&circuit, 5, 50);

    return 0;
}