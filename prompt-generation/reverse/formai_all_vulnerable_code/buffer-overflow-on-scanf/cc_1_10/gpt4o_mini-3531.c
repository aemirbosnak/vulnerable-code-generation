//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    double resistance; // Ohms
    double voltage; // Volts
} Resistor;

typedef struct {
    double capacitance; // Farads
    double voltage; // Volts
} Capacitor;

typedef struct {
    double inductance; // Henrys
    double current; // Amperes
} Inductor;

typedef struct Node {
    Resistor r;
    Capacitor c;
    Inductor l;
    struct Node *next;
} Node;

Node* head = NULL;

void addResistor(double resistance, double voltage) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->r.resistance = resistance;
    newNode->r.voltage = voltage;
    newNode->next = head;
    head = newNode;
}

void addCapacitor(double capacitance, double voltage) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c.capacitance = capacitance;
    newNode->c.voltage = voltage;
    newNode->next = head;
    head = newNode;
}

void addInductor(double inductance, double current) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->l.inductance = inductance;
    newNode->l.current = current;
    newNode->next = head;
    head = newNode;
}

void analyzeCircuit() {
    Node* current = head;
    double totalResistance = 0.0, totalCapacitance = 0.0, totalInductance = 0.0;

    while (current != NULL) {
        if (current->r.resistance != 0) {
            totalResistance += current->r.resistance;
        }
        if (current->c.capacitance > 0) {
            totalCapacitance += current->c.capacitance;
        }
        if (current->l.inductance > 0) {
            totalInductance += current->l.inductance;
        }
        current = current->next;
    }

    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    printf("Total Capacitance: %.2f Farads\n", totalCapacitance);
    printf("Total Inductance: %.2f Henrys\n", totalInductance);
}

void clearCircuit() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

void displayMenu() {
    printf("\n");
    printf("Welcome to the Mind-Bending Circuit Simulator!\n");
    printf("1. Add Resistor\n");
    printf("2. Add Capacitor\n");
    printf("3. Add Inductor\n");
    printf("4. Analyze Circuit\n");
    printf("5. Clear Circuit\n");
    printf("6. Exit\n");
    printf("Choose action: ");
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            double resistance, voltage;
            printf("Enter Resistance (Ohms): ");
            scanf("%lf", &resistance);
            printf("Enter Voltage (Volts): ");
            scanf("%lf", &voltage);
            addResistor(resistance, voltage);
        } else if (choice == 2) {
            double capacitance, voltage;
            printf("Enter Capacitance (Farads): ");
            scanf("%lf", &capacitance);
            printf("Enter Voltage (Volts): ");
            scanf("%lf", &voltage);
            addCapacitor(capacitance, voltage);
        } else if (choice == 3) {
            double inductance, current;
            printf("Enter Inductance (Henrys): ");
            scanf("%lf", &inductance);
            printf("Enter Current (Amperes): ");
            scanf("%lf", &current);
            addInductor(inductance, current);
        } else if (choice == 4) {
            analyzeCircuit();
        } else if (choice == 5) {
            clearCircuit();
            printf("Circuit cleared!\n");
        } else if (choice == 6) {
            printf("Exiting the mind-bending simulator...\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    clearCircuit();
    return 0;
}