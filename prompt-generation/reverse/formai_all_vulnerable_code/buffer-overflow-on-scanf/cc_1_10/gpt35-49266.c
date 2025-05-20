//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 100

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    DC_SOURCE,
    AC_SOURCE
} componentType;

typedef struct {
    componentType type;
    double value;
    int node1;
    int node2;
} component;

component circuit[MAX_COMPONENTS];

int numOfComponents = 0;

void printMenu() {
    printf("\nMenu:\n");
    printf("1 - Add a resistor\n");
    printf("2 - Add a capacitor\n");
    printf("3 - Add an inductor\n");
    printf("4 - Add a DC source\n");
    printf("5 - Add an AC source\n");
    printf("0 - Quit\n\n");
}

void addResistor() {
    double value;
    int node1, node2;

    printf("Enter the value of the resistor: ");
    scanf("%lf", &value);
    printf("Enter the number of node 1: ");
    scanf("%d", &node1);
    printf("Enter the number of node 2: ");
    scanf("%d", &node2);

    if (numOfComponents == MAX_COMPONENTS) {
        printf("Error: Maximum number of components exceeded!\n");
        return;
    }

    circuit[numOfComponents].type = RESISTOR;
    circuit[numOfComponents].value = value;
    circuit[numOfComponents].node1 = node1;
    circuit[numOfComponents].node2 = node2;

    printf("Resistor added to the circuit!\n");
    numOfComponents++;
}

void simulateCircuit() {
    double voltage[MAX_COMPONENTS] = { 0 };
    double current[MAX_COMPONENTS] = { 0 };

    // calculate DC voltages
    for (int i = 0; i < numOfComponents; i++) {
        if (circuit[i].type == DC_SOURCE) {
            voltage[circuit[i].node2] = circuit[i].value;
        }
    }

    printf("\nSimulation results:\n");

    // print DC voltages
    for (int i = 0; i < numOfComponents; i++) {
        if (circuit[i].type != DC_SOURCE) {
            voltage[circuit[i].node2] = voltage[circuit[i].node1] - current[i] * circuit[i].value;
        }

        printf("Voltage at node %d is %lf volts.\n", circuit[i].node2, voltage[circuit[i].node2]);
    }
}

int main() {
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addResistor();
                break;
            case 2:
                // add capacitor
                break;
            case 3:
                // add inductor
                break;
            case 4:
                // add dc source
                break;
            case 5:
                // add ac source
                break;
            case 0:
                // quit
                break;
            default:
                printf("Error: Invalid choice!\n");
        }
    } while (choice != 0);

    simulateCircuit();

    return EXIT_SUCCESS;
}