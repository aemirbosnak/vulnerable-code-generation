//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100

typedef struct {
    char type[10]; // Type of component: Resistor, Capacitor, Inductor
    char name[10];
    float value; // Value of component (e.g., resistance in ohms)
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void add_component(Circuit *circuit, const char *type, const char *name, float value) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Circuit is full. Cannot add more components.\n");
        return;
    }
    strcpy(circuit->components[circuit->count].type, type);
    strcpy(circuit->components[circuit->count].name, name);
    circuit->components[circuit->count].value = value;
    circuit->count++;
}

void display_circuit(const Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("%s: %s, Value: %.2f\n", circuit->components[i].type, circuit->components[i].name, circuit->components[i].value);
    }
}

float calculate_total_resistance(const Circuit *circuit) {
    float total_resistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "Resistor") == 0) {
            total_resistance += circuit->components[i].value;
        }
    }
    return total_resistance;
}

float calculate_total_capacitance(const Circuit *circuit) {
    float total_capacitance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "Capacitor") == 0) {
            total_capacitance += circuit->components[i].value;
        }
    }
    return total_capacitance;
}

float calculate_total_inductance(const Circuit *circuit) {
    float total_inductance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "Inductor") == 0) {
            total_inductance += circuit->components[i].value;
        }
    }
    return total_inductance;
}

int main() {
    Circuit myCircuit;
    myCircuit.count = 0;

    printf("Welcome to the Circuit Simulator.\n");
    printf("Let's add some components to your circuit!\n");

    while (1) {
        char type[10], name[10];
        float value;

        printf("Enter component type (Resistor, Capacitor, Inductor) or 'exit' to finish: ");
        scanf("%s", type);
        if (strcmp(type, "exit") == 0) {
            break;
        }
        printf("Enter component name: ");
        scanf("%s", name);
        printf("Enter component value: ");
        scanf("%f", &value);

        add_component(&myCircuit, type, name, value);
    }

    display_circuit(&myCircuit);
    
    float total_resistance = calculate_total_resistance(&myCircuit);
    printf("Total Resistance in the circuit: %.2f Ohms\n", total_resistance);

    float total_capacitance = calculate_total_capacitance(&myCircuit);
    printf("Total Capacitance in the circuit: %.2f Farads\n", total_capacitance);
    
    float total_inductance = calculate_total_inductance(&myCircuit);
    printf("Total Inductance in the circuit: %.2f Henrys\n", total_inductance);

    printf("Thank you for using the Circuit Simulator! Goodbye.\n");
    return 0;
}