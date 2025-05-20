//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resistor {
    float resistance;
    struct Resistor *next;
} Resistor;

typedef enum { SERIES, PARALLEL } ConnectionType;

typedef struct Circuit {
    Resistor *resistors;
    ConnectionType connectionType;
} Circuit;

Circuit* createCircuit(ConnectionType type) {
    Circuit *circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->resistors = NULL;
    circuit->connectionType = type;
    return circuit;
}

void addResistor(Circuit *circuit, float resistance) {
    Resistor *newResistor = (Resistor*)malloc(sizeof(Resistor));
    newResistor->resistance = resistance;
    newResistor->next = circuit->resistors;
    circuit->resistors = newResistor;
}

float calculateTotalResistance(Circuit *circuit) {
    float totalResistance = 0.0;
    Resistor *current = circuit->resistors;

    if (circuit->connectionType == SERIES) {
        while (current != NULL) {
            totalResistance += current->resistance;
            current = current->next;
        }
    } else {
        while (current != NULL) {
            totalResistance += 1.0 / current->resistance;
            current = current->next;
        }
        if (totalResistance != 0) {
            totalResistance = 1.0 / totalResistance;
        } else {
            totalResistance = 0; // Avoid division by zero
        }
    }
    
    return totalResistance;
}

void freeCircuit(Circuit *circuit) {
    Resistor *current = circuit->resistors;
    Resistor *nextResistor;
    
    while (current != NULL) {
        nextResistor = current->next;
        free(current);
        current = nextResistor;
    }
    
    free(circuit);
}

void displayCircuit(Circuit *circuit) {
    Resistor *current = circuit->resistors;
    printf("Circuit Configuration: %s\n", circuit->connectionType == SERIES ? "Series" : "Parallel");
    printf("Resistors in the circuit:\n");
    
    while (current != NULL) {
        printf("R: %.2f Ohms\n", current->resistance);
        current = current->next;
    }
    
    printf("Total Resistance: %.2f Ohms\n", calculateTotalResistance(circuit));
}

int main() {
    printf("Welcome to the C Classical Circuit Simulator!\n");

    ConnectionType connectionType;
    printf("Choose connection type (0 - SERIES, 1 - PARALLEL): ");
    
    int type;
    scanf("%d", &type);
    connectionType = (type == 0) ? SERIES : PARALLEL;

    Circuit *circuit = createCircuit(connectionType);

    char choice;
    do {
        float resistance;
        printf("Enter the resistance value (Ohms) to add: ");
        scanf("%f", &resistance);
        addResistor(circuit, resistance);
        
        printf("Would you like to add another resistor? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    displayCircuit(circuit);
    
    freeCircuit(circuit);
    printf("Thank you for using the C Classical Circuit Simulator!\n");

    return 0;
}