//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct CircuitElement {
    char name[10];
    char type; // 'R' for Resistor, 'C' for Capacitor, 'L' for Inductor
    double value; // ohms for R, farads for C, henrys for L
    struct CircuitElement *next;
} CircuitElement;

typedef struct Circuit {
    CircuitElement *head;
    double totalResistance;
    double totalCapacitance;
    double totalInductance;
} Circuit;

Circuit *createCircuit() {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->head = NULL;
    circuit->totalResistance = 0;
    circuit->totalCapacitance = 0;
    circuit->totalInductance = 0;
    return circuit;
}

void addElement(Circuit *circuit, const char *name, char type, double value) {
    CircuitElement *element = (CircuitElement *)malloc(sizeof(CircuitElement));
    snprintf(element->name, sizeof(element->name), "%s", name);
    element->type = type;
    element->value = value;
    element->next = circuit->head;
    circuit->head = element;

    if (type == 'R') {
        circuit->totalResistance += value;
    } else if (type == 'C') {
        circuit->totalCapacitance += value;
    } else if (type == 'L') {
        circuit->totalInductance += value;
    }
}

void displayCircuit(Circuit *circuit) {
    CircuitElement *current = circuit->head;
    printf("Circuit Elements:\n");
    while (current != NULL) {
        printf("Name: %s, Type: %c, Value: %.2f\n", current->name, current->type, current->value);
        current = current->next;
    }
    
    printf("Total Resistance: %.2f Ohms\n", circuit->totalResistance);
    printf("Total Capacitance: %.2f Farads\n", circuit->totalCapacitance);
    printf("Total Inductance: %.2f Henries\n", circuit->totalInductance);
}

double calculateCurrent(double voltage, double resistance) {
    if(resistance == 0) {
        printf("Error: Resistance cannot be zero for current calculation.\n");
        return 0;
    }
    return voltage / resistance;
}

void freeCircuit(Circuit *circuit) {
    CircuitElement *current = circuit->head;
    CircuitElement *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(circuit);
}

int main() {
    Circuit *myCircuit = createCircuit();
    printf("Welcome to the Circuit Simulator!\n");

    addElement(myCircuit, "R1", 'R', 10.0);
    addElement(myCircuit, "C1", 'C', 0.1);
    addElement(myCircuit, "L1", 'L', 0.01);

    displayCircuit(myCircuit);

    double voltage;
    printf("Enter the voltage (in Volts) provided by the source: ");
    scanf("%lf", &voltage);

    double current = calculateCurrent(voltage, myCircuit->totalResistance);
    printf("Calculated Current: %.2f Amperes\n", current);

    freeCircuit(myCircuit);

    return 0;
}