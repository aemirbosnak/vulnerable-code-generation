//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance; // in ohms
    struct Resistor* next;
} Resistor;

typedef struct Capacitor {
    float capacitance; // in farads
    struct Capacitor* next;
} Capacitor;

Resistor* resistorList = NULL;
Capacitor* capacitorList = NULL;

void addResistor(float resistance) {
    Resistor* newResistor = (Resistor*)malloc(sizeof(Resistor));
    newResistor->resistance = resistance;
    newResistor->next = resistorList;
    resistorList = newResistor;
}

void addCapacitor(float capacitance) {
    Capacitor* newCapacitor = (Capacitor*)malloc(sizeof(Capacitor));
    newCapacitor->capacitance = capacitance;
    newCapacitor->next = capacitorList;
    capacitorList = newCapacitor;
}

float calculateEquivalentResistance() {
    float totalResistance = 0.0;
    Resistor* current = resistorList;
    while (current != NULL) {
        totalResistance += current->resistance;
        current = current->next;
    }
    return totalResistance;
}

float calculateEquivalentCapacitance() {
    float totalCapacitance = 0.0;
    Capacitor* current = capacitorList;
    while (current != NULL) {
        totalCapacitance += current->capacitance;
        current = current->next;
    }
    if (totalCapacitance > 0) {
        return totalCapacitance; // Series capacitors sum their capacitance
    }
    return 0.0;
}

void displayComponents() {
    printf("Resistors in circuit:\n");
    Resistor* currentR = resistorList;
    while (currentR != NULL) {
        printf("- %.2f Ohms\n", currentR->resistance);
        currentR = currentR->next;
    }

    printf("Capacitors in circuit:\n");
    Capacitor* currentC = capacitorList;
    while (currentC != NULL) {
        printf("- %.2f Farads\n", currentC->capacitance);
        currentC = currentC->next;
    }
}

void freeMemory() {
    Resistor* currentR = resistorList;
    while (currentR != NULL) {
        Resistor* temp = currentR;
        currentR = currentR->next;
        free(temp);
    }

    Capacitor* currentC = capacitorList;
    while (currentC != NULL) {
        Capacitor* temp = currentC;
        currentC = currentC->next;
        free(temp);
    }
}

int main() {
    int choice;
    float value;

    while (1) {
        printf("\nCircuit Simulator\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Calculate Equivalent Resistance\n");
        printf("4. Calculate Equivalent Capacitance\n");
        printf("5. Display Components\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance (Ohms): ");
                scanf("%f", &value);
                addResistor(value);
                break;
            case 2:
                printf("Enter capacitance (Farads): ");
                scanf("%f", &value);
                addCapacitor(value);
                break;
            case 3:
                printf("Total Equivalent Resistance: %.2f Ohms\n", calculateEquivalentResistance());
                break;
            case 4:
                printf("Total Equivalent Capacitance: %.2f Farads\n", calculateEquivalentCapacitance());
                break;
            case 5:
                displayComponents();
                break;
            case 6:
                freeMemory();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}