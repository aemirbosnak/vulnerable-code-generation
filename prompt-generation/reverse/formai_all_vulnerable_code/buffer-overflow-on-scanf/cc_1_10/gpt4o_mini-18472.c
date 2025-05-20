//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Component {
    char type[10];  // Type of component: R, C, V
    double value;   // Value of the component: resistance in ohms, capacitance in farads, or voltage in volts
    struct Component* next; // Pointer to the next component
} Component;

typedef struct Circuit {
    Component* head; // Head of the component linked list
} Circuit;

// Function prototypes
Circuit* createCircuit();
void addComponent(Circuit* circuit, const char* type, double value);
void calculateTotalResistance(Circuit* circuit);
void calculateTotalReactance(Circuit* circuit);
void displayCircuit(Circuit* circuit);
void freeCircuit(Circuit* circuit);

int main() {
    Circuit* circuit = createCircuit();
    char option[2];
    while (1) {
        printf("\n--- Circuit Simulator ---\n");
        printf("1. Add Component\n");
        printf("2. Calculate Total Resistance\n");
        printf("3. Calculate Total Reactance\n");
        printf("4. Display Circuit\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%s", option);

        if (strcmp(option, "1") == 0) {
            char type[10];
            double value;
            printf("Enter component type (R/C/V): ");
            scanf("%s", type);
            printf("Enter component value: ");
            scanf("%lf", &value);
            addComponent(circuit, type, value);
        } else if (strcmp(option, "2") == 0) {
            calculateTotalResistance(circuit);
        } else if (strcmp(option, "3") == 0) {
            calculateTotalReactance(circuit);
        } else if (strcmp(option, "4") == 0) {
            displayCircuit(circuit);
        } else if (strcmp(option, "5") == 0) {
            freeCircuit(circuit);
            printf("Exiting simulator...\n");
            break;
        } else {
            printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}

Circuit* createCircuit() {
    Circuit* circuit = (Circuit*) malloc(sizeof(Circuit));
    circuit->head = NULL;
    return circuit;
}

void addComponent(Circuit* circuit, const char* type, double value) {
    Component* newComponent = (Component*) malloc(sizeof(Component));
    strcpy(newComponent->type, type);
    newComponent->value = value;
    newComponent->next = circuit->head; // Insert at the beginning
    circuit->head = newComponent;
    printf("Added %s: %.2f\n", type, value);
}

void calculateTotalResistance(Circuit* circuit) {
    double totalResistance = 0.0;
    Component* current = circuit->head;
    while (current != NULL) {
        if (strcmp(current->type, "R") == 0) {
            totalResistance += current->value;
        }
        current = current->next;
    }
    printf("Total Resistance: %.2f Ohms\n", totalResistance);
}

void calculateTotalReactance(Circuit* circuit) {
    double totalReactance = 0.0;
    Component* current = circuit->head;
    while (current != NULL) {
        if (strcmp(current->type, "C") == 0) {
            totalReactance += (1 / (2 * 3.14159 * current->value));
        }
        current = current->next;
    }
    printf("Total Reactance: %.2f Ohms\n", totalReactance);
}

void displayCircuit(Circuit* circuit) {
    Component* current = circuit->head;
    if (current == NULL) {
        printf("The circuit is empty.\n");
        return;
    }
    
    printf("Current Circuit Components:\n");
    while (current != NULL) {
        printf("Type: %s, Value: %.2f\n", current->type, current->value);
        current = current->next;
    }
}

void freeCircuit(Circuit* circuit) {
    Component* current = circuit->head;
    while (current != NULL) {
        Component* next = current->next;
        free(current);
        current = next;
    }
    free(circuit);
}