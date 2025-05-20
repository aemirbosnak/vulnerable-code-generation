//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef enum { SERIES, PARALLEL } ConnectionType;

typedef struct {
    float resistance;
} Resistor;

typedef struct {
    Resistor* resistors;
    int count;
    ConnectionType connectionType;
} Circuit;

Circuit* createCircuit(ConnectionType type) {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->resistors = NULL;
    circuit->count = 0;
    circuit->connectionType = type;
    return circuit;
}

void addResistor(Circuit* circuit, float resistance) {
    circuit->resistors = (Resistor*)realloc(circuit->resistors, sizeof(Resistor) * (circuit->count + 1));
    circuit->resistors[circuit->count].resistance = resistance;
    circuit->count++;
}

float calculateTotalResistance(Circuit* circuit) {
    float totalResistance = 0.0;
    
    if (circuit->connectionType == SERIES) {
        for (int i = 0; i < circuit->count; i++) {
            totalResistance += circuit->resistors[i].resistance;
        }
    } else if (circuit->connectionType == PARALLEL) {
        for (int i = 0; i < circuit->count; i++) {
            if (circuit->resistors[i].resistance == 0) {
                return 0; // Infinite resistance due to short circuit
            }
            totalResistance += 1 / circuit->resistors[i].resistance;
        }
        totalResistance = 1 / totalResistance; // Taking reciprocal of the sum of inverses
    }
    
    return totalResistance;
}

void freeCircuit(Circuit* circuit) {
    free(circuit->resistors);
    free(circuit);
}

int main() {
    int choice, connectionType;
    Circuit* circuit;

    printf("Welcome to the Circuit Simulator!\n");
    printf("Choose connection type:\n1. Series\n2. Parallel\n");
    scanf("%d", &connectionType);
    
    if (connectionType == 1) {
        circuit = createCircuit(SERIES);
    } else {
        circuit = createCircuit(PARALLEL);
    }

    printf("Add resistors (Enter value in Ohms, -1 to stop):\n");
    
    while (1) {
        float resistance;
        printf("Enter resistor value: ");
        scanf("%f", &resistance);
        
        if (resistance == -1) {
            break;
        }
        
        addResistor(circuit, resistance);
    }

    float totalResistance = calculateTotalResistance(circuit);
    
    printf("Total resistance of the circuit: %.2f Ohms\n", totalResistance);
    
    freeCircuit(circuit);
    return 0;
}