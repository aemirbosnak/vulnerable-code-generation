//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_COMPONENTS 50
#define BUFFER_SIZE 256

typedef struct {
    char type[10];
    char name[10];
    double value;
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void add_component(Circuit *circuit, const char *type, const char *name, double value) {
    if (circuit->count < MAX_COMPONENTS) {
        strcpy(circuit->components[circuit->count].type, type);
        strcpy(circuit->components[circuit->count].name, name);
        circuit->components[circuit->count].value = value;
        circuit->count++;
    } else {
        printf("Maximum component limit reached!\n");
    }
}

void display_circuit(const Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("%s (Name: %s, Value: %.2f)\n", circuit->components[i].type, circuit->components[i].name, circuit->components[i].value);
    }
}

double calculate_total_resistance(const Circuit *circuit) {
    double total_resistance = 0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "resistor") == 0) {
            total_resistance += circuit->components[i].value;
        }
    }
    return total_resistance;
}

double calculate_total_capacitance(const Circuit *circuit) {
    double total_capacitance = 0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "capacitor") == 0) {
            total_capacitance += circuit->components[i].value;
        }
    }
    return total_capacitance;
}

void simulate_circuit(const Circuit *circuit) {
    printf("Simulating Circuit...\n");
    double total_resistance = calculate_total_resistance(circuit);
    double total_capacitance = calculate_total_capacitance(circuit);

    printf("Total Resistance: %.2f Ohms\n", total_resistance);
    printf("Total Capacitance: %.2f Farads\n", total_capacitance);
    
    if (total_resistance > 0) {
        double current = 5.0 / total_resistance; // assuming V = 5V
        printf("Circuit Current: %.2f Amperes\n", current);
    } else {
        printf("Infinite current: Total resistance is zero!\n");
    }
}

void parse_input(Circuit *circuit) {
    char buffer[BUFFER_SIZE];
    printf("Enter components (type name value) or 'exit' to finish:\n");
    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
        char type[10], name[10];
        double value;
        if (sscanf(buffer, "%s %s %lf", type, name, &value) == 3) {
            add_component(circuit, type, name, value);
        } else {
            printf("Invalid input. Format: type name value\n");
        }
    }
}

int main() {
    Circuit circuit;
    circuit.count = 0;

    parse_input(&circuit);
    display_circuit(&circuit);
    simulate_circuit(&circuit);

    return 0;
}