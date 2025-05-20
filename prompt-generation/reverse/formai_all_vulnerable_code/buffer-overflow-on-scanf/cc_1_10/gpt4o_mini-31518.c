//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 10

typedef enum {
    SERIES,
    PARALLEL
} CircuitType;

typedef struct {
    double value;
    char type; // 'R' for Resistor, 'C' for Capacitor
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
    CircuitType type;
} Circuit;

double calculate_series(Circuit *circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'R') {
            total += circuit->components[i].value;
        } else if (circuit->components[i].type == 'C') {
            total += 1.0 / circuit->components[i].value;
        }
    }
    return (circuit->components[0].type == 'R') ? total : 1.0 / total;
}

double calculate_parallel(Circuit *circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'R') {
            total += 1.0 / circuit->components[i].value;
        } else if (circuit->components[i].type == 'C') {
            total += circuit->components[i].value;
        }
    }
    return (circuit->components[0].type == 'R') ? 1.0 / total : total;
}

void display_result(Circuit *circuit) {
    double total;
    if (circuit->type == SERIES) {
        total = calculate_series(circuit);
        printf("Total Resistance/Impedance for Series Circuit: %.2f Ohms\n", total);
    } else {
        total = calculate_parallel(circuit);
        printf("Total Resistance/Impedance for Parallel Circuit: %.2f Ohms\n", total);
    }
}

void input_components(Circuit *circuit) {
    printf("Enter number of components (Max %d): ", MAX_COMPONENTS);
    scanf("%d", &circuit->count);
    
    if (circuit->count > MAX_COMPONENTS) {
        printf("Exceeds maximum components limit.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < circuit->count; i++) {
        printf("Enter component type (R for Resistor, C for Capacitor): ");
        scanf(" %c", &circuit->components[i].type);
        
        printf("Enter component value: ");
        scanf("%lf", &circuit->components[i].value);
    }
}

void select_circuit_type(Circuit *circuit) {
    int choice;
    printf("Select Circuit Type:\n1. Series\n2. Parallel\n");
    scanf("%d", &choice);
    circuit->type = (choice == 1) ? SERIES : PARALLEL;
}

int main() {
    Circuit circuit;
    circuit.count = 0;

    select_circuit_type(&circuit);
    input_components(&circuit);
    display_result(&circuit);

    return 0;
}