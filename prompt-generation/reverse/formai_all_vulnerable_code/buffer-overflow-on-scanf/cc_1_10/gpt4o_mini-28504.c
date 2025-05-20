//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 10

typedef struct {
    char name[20];
    float resistance; // in Ohms
} Resistor;

typedef struct {
    Resistor resistors[MAX_ELEMENTS];
    int count;
    float voltage; // in Volts
} Circuit;

void add_resistor(Circuit *circuit, const char *name, float resistance) {
    if (circuit->count < MAX_ELEMENTS) {
        Resistor new_resistor;
        snprintf(new_resistor.name, sizeof(new_resistor.name), "%s", name);
        new_resistor.resistance = resistance;
        circuit->resistors[circuit->count] = new_resistor;
        circuit->count++;
    } else {
        printf("Cannot add more resistors. Maximum limit reached.\n");
    }
}

float calculate_total_resistance(const Circuit *circuit) {
    float total_resistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        total_resistance += circuit->resistors[i].resistance;
    }
    return total_resistance;
}

float calculate_current(const Circuit *circuit) {
    float total_resistance = calculate_total_resistance(circuit);
    if (total_resistance == 0) {
        printf("Error: Total resistance is zero! Current cannot be calculated.\n");
        return 0;
    }
    return circuit->voltage / total_resistance;
}

void display_circuit(const Circuit *circuit) {
    printf("Circuit Voltage: %.2f V\n", circuit->voltage);
    printf("Resistors in the Circuit:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf(" - %s: %.2f Ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
}

int main() {
    Circuit circuit;
    circuit.count = 0;
    circuit.voltage = 0.0;

    printf("Welcome to the Classical Circuit Simulator!\n");

    printf("Enter the voltage of the circuit (in Volts): ");
    scanf("%f", &circuit.voltage);

    char name[20];
    float resistance;
    char cont;

    do {
        printf("Enter the name of the resistor: ");
        scanf("%s", name);
        printf("Enter the resistance of the resistor (in Ohms): ");
        scanf("%f", &resistance);
        add_resistor(&circuit, name, resistance);

        printf("Do you want to add another resistor? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    display_circuit(&circuit);
    float total_resistance = calculate_total_resistance(&circuit);
    printf("Total Resistance: %.2f Ohms\n", total_resistance);

    float current = calculate_current(&circuit);
    printf("Calculated Current: %.2f Amps\n", current);

    return 0;
}