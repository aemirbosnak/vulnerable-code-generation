//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Component {
    char type; // 'R' for resistor, 'C' for capacitor, 'V' for voltage source
    double value; // resistance in ohms, capacitance in farads, voltage in volts
    struct Component *next;
} Component;

Component *head = NULL;

void addComponent(char type, double value) {
    Component *newComp = (Component *)malloc(sizeof(Component));
    newComp->type = type;
    newComp->value = value;
    newComp->next = head;
    head = newComp;
}

void displayComponents() {
    Component *current = head;
    printf("Components in the Circuit:\n");
    while (current != NULL) {
        printf("Type: %c, Value: %.2f\n", current->type, current->value);
        current = current->next;
    }
}

double calculateTotalResistance() {
    double totalResistance = 0.0;
    Component *current = head;
    
    while (current != NULL) {
        if (current->type == 'R') {
            totalResistance += current->value; // Sum resistance for resistors in series
        }
        current = current->next;
    }
    return totalResistance;
}

double calculateTotalCapacitance() {
    double totalCapacitance = 0.0;
    Component *current = head;

    while (current != NULL) {
        if (current->type == 'C') {
            totalCapacitance += current->value; // Sum capacitance for capacitors in parallel
        }
        current = current->next;
    }
    return totalCapacitance;
}

double calculateVoltageDrop() {
    double totalVoltage = 0.0;
    Component *current = head;

    while (current != NULL) {
        if (current->type == 'V') {
            totalVoltage += current->value; // Sum voltage sources
        }
        current = current->next;
    }
    return totalVoltage;
}

void freeComponents() {
    Component *current = head;
    while (current != NULL) {
        Component *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    char command;
    double value;

    printf("Welcome to the C Classical Circuit Simulator!\n");

    while (1) {
        printf("\nChoose an action:\n");
        printf("A: Add Component (R: Resistor; C: Capacitor; V: Voltage Source)\n");
        printf("D: Display Components\n");
        printf("T: Calculate Total Resistance\n");
        printf("C: Calculate Total Capacitance\n");
        printf("V: Calculate Total Voltage\n");
        printf("E: Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &command);

        switch (command) {
            case 'A':
                printf("Enter type (R/C/V) and value: ");
                scanf(" %c %lf", &command, &value);
                addComponent(command, value);
                break;

            case 'D':
                displayComponents();
                break;

            case 'T':
                printf("Total Resistance: %.2f Ohms\n", calculateTotalResistance());
                break;

            case 'C':
                printf("Total Capacitance: %.2f Farads\n", calculateTotalCapacitance());
                break;

            case 'V':
                printf("Total Voltage: %.2f Volts\n", calculateVoltageDrop());
                break;

            case 'E':
                freeComponents();
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}