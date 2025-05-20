//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef enum {SERIES, PARALLEL} CircuitType;

typedef struct {
    float value; // Resistance in Ohms
} Resistor;

typedef struct {
    float value; // Capacitance in Farads for future use
} Capacitor;

typedef struct {
    CircuitType type;
    Resistor* resistors;
    int resistorCount;
    Capacitor* capacitors;
    int capacitorCount;
} Circuit;

void calculateTotalResistance(Circuit* circuit) {
    float totalResistance = 0.0;

    if (circuit->type == SERIES) {
        for (int i = 0; i < circuit->resistorCount; i++) {
            totalResistance += circuit->resistors[i].value;
        }
    } else if (circuit->type == PARALLEL) {
        for (int i = 0; i < circuit->resistorCount; i++) {
            totalResistance += 1 / circuit->resistors[i].value;
        }
        if (totalResistance != 0) {
            totalResistance = 1 / totalResistance;
        } else {
            printf("Error: All resistors have infinite resistance (open circuit)\n");
            return;
        }
    }

    printf("Total Resistance: %.2f Ohms\n", totalResistance);
}

void createCircuit(Circuit* circuit) {
    printf("Enter circuit type (0 for SERIES, 1 for PARALLEL): ");
    scanf("%d", &circuit->type);
    printf("Enter number of resistors: ");
    scanf("%d", &circuit->resistorCount);
    
    circuit->resistors = (Resistor*)malloc(circuit->resistorCount * sizeof(Resistor));

    for (int i = 0; i < circuit->resistorCount; i++) {
        printf("Enter resistance for resistor %d (Ohms): ", i + 1);
        scanf("%f", &circuit->resistors[i].value);
    }
    
    circuit->capacitorCount = 0; // Currently not implemented, but here for future use
    circuit->capacitors = NULL;  // Allocate capacitors if needed
}

void freeCircuit(Circuit* circuit) {
    free(circuit->resistors);
    // Add free for capacitors if implemented in future
}

int main() {
    Circuit circuit;
    
    createCircuit(&circuit);
    calculateTotalResistance(&circuit);
    freeCircuit(&circuit);

    return 0;
}