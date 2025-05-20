//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Component {
    char type; // 'R' for Resistor, 'C' for Capacitor, 'L' for Inductor
    double value; // Ohms for Resistor, Farads for Capacitor, Henrys for Inductor
    struct Component* next;
} Component;

typedef struct Circuit {
    Component* head;
} Circuit;

Circuit* createCircuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->head = NULL;
    return circuit;
}

void addComponent(Circuit* circuit, char type, double value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    newComponent->type = type;
    newComponent->value = value;
    newComponent->next = circuit->head;
    circuit->head = newComponent;
}

void freeCircuit(Circuit* circuit) {
    Component* current = circuit->head;
    Component* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(circuit);
}

void displayCircuit(Circuit* circuit) {
    Component* current = circuit->head;
    printf("Circuit Components:\n");
    while (current != NULL) {
        printf("Type: %c, Value: %.2f\n", current->type, current->value);
        current = current->next;
    }
    printf("\n");
}

double calculateTotalResistance(Circuit* circuit) {
    double totalResistance = 0;
    Component* current = circuit->head;

    while (current != NULL) {
        if (current->type == 'R') {
            totalResistance += current->value;
        }
        current = current->next;
    }
    return totalResistance;
}

double calculateCapacitanceInSeries(Circuit* circuit) {
    double totalCapacitance = 0;
    Component* current = circuit->head;

    while (current != NULL) {
        if (current->type == 'C') {
            totalCapacitance += 1 / current->value; // 1/Ceq = 1/C1 + 1/C2 + ...
        }
        current = current->next;
    }

    if (totalCapacitance > 0) {
        return 1 / totalCapacitance;
    }
    return 0;
}

double calculateInductanceInSeries(Circuit* circuit) {
    double totalInductance = 0;
    Component* current = circuit->head;

    while (current != NULL) {
        if (current->type == 'L') {
            totalInductance += current->value; // Leq = L1 + L2 + ...
        }
        current = current->next;
    }
    return totalInductance;
}

void simulateCircuit(Circuit* circuit) {
    printf("Simulation Results:\n");
    double totalResistance = calculateTotalResistance(circuit);
    double totalCapacitance = calculateCapacitanceInSeries(circuit);
    double totalInductance = calculateInductanceInSeries(circuit);

    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    printf("Total Capacitance (in series): %.6f F\n", totalCapacitance);
    printf("Total Inductance (in series): %.2f H\n", totalInductance);
}

void userInput(Circuit* circuit) {
    char type;
    double value;
    while (1) {
        printf("Enter component type (R for Resistor, C for Capacitor, L for Inductor, Q to quit): ");
        scanf(" %c", &type);
        if (type == 'Q') {
            break;
        }
        printf("Enter component value: ");
        scanf("%lf", &value);
        addComponent(circuit, type, value);
    }
}

int main() {
    Circuit* circuit = createCircuit();

    userInput(circuit);
    displayCircuit(circuit);
    simulateCircuit(circuit);

    freeCircuit(circuit);
    return 0;
}