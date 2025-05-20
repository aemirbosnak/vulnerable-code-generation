//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure for a circuit element
typedef struct {
    char type; // 'R' for resistor, 'C' for capacitor, 'V' for voltage source
    double value; // Ohms for resistor, Farads for capacitor, Volts for voltage source
} CircuitElement;

// Function prototypes
void simulateCircuit(CircuitElement *elements, int count);
void addElement(CircuitElement *elements, int *count);
void displayElements(CircuitElement *elements, int count);
void calculateTotalResistance(CircuitElement *elements, int count);
void calculateTotalCapacitance(CircuitElement *elements, int count);
void calculateTotalVoltage(CircuitElement *elements, int count);

int main() {
    CircuitElement elements[100];
    int count = 0;
    int option;

    printf("Welcome to the Lively Circuit Simulator!\n");
    printf("Let's build your circuit step by step.\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a circuit element\n");
        printf("2. Display circuit elements\n");
        printf("3. Simulate circuit\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addElement(elements, &count);
                break;
            case 2:
                displayElements(elements, count);
                break;
            case 3:
                simulateCircuit(elements, count);
                break;
            case 4:
                printf("Thanks for using the Lively Circuit Simulator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void addElement(CircuitElement *elements, int *count) {
    if (*count >= 100) {
        printf("You have reached the maximum number of elements.\n");
        return;
    }

    char type;
    double value;
    printf("Enter element type (R = Resistor, C = Capacitor, V = Voltage source): ");
    scanf(" %c", &type);
    printf("Enter value (numeric): ");
    scanf("%lf", &value);

    // Validate input
    if ((type == 'R' && value <= 0) || (type == 'C' && value <= 0) || (type == 'V' && value < 0)) {
        printf("Invalid value for the element.\n");
        return;
    }

    elements[*count].type = type;
    elements[*count].value = value;
    (*count)++;
    printf("%c element with value %.2f added!\n", type, value);
}

void displayElements(CircuitElement *elements, int count) {
    if (count == 0) {
        printf("No circuit elements in the circuit!\n");
        return;
    }
    printf("\nCircuit Elements:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: Type = %c, Value = %.2f\n", i + 1, elements[i].type, elements[i].value);
    }
}

void simulateCircuit(CircuitElement *elements, int count) {
    if (count == 0) {
        printf("No circuit elements to simulate!\n");
        return;
    }

    calculateTotalResistance(elements, count);
    calculateTotalCapacitance(elements, count);
    calculateTotalVoltage(elements, count);
}

void calculateTotalResistance(CircuitElement *elements, int count) {
    double totalResistance = 0;
    for (int i = 0; i < count; i++) {
        if (elements[i].type == 'R') {
            totalResistance += elements[i].value; // Series connection
        }
    }
    printf("Total Resistance in the circuit: %.2f Ohms\n", totalResistance);
}

void calculateTotalCapacitance(CircuitElement *elements, int count) {
    double totalCapacitance = 0;
    for (int i = 0; i < count; i++) {
        if (elements[i].type == 'C') {
            totalCapacitance += elements[i].value; // Series connection assumed for simplicity
        }
    }
    printf("Total Capacitance in the circuit: %.2f Farads\n", totalCapacitance);
}

void calculateTotalVoltage(CircuitElement *elements, int count) {
    double totalVoltage = 0;
    for (int i = 0; i < count; i++) {
        if (elements[i].type == 'V') {
            totalVoltage += elements[i].value; // Sum of voltage sources
        }
    }
    printf("Total Voltage in the circuit: %.2f Volts\n", totalVoltage);
}