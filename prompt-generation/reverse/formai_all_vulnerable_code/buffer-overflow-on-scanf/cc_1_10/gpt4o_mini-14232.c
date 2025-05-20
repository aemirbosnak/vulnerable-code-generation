//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ELEMENTS 100

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
} ElementType;

typedef struct {
    ElementType type;
    double value; // resistance, capacitance, inductance, voltage or current 
    char name[50]; // user-defined name
} CircuitElement;

CircuitElement circuit[MAX_ELEMENTS];
int element_count = 0;

void add_element(ElementType type, double value, const char *name) {
    if (element_count >= MAX_ELEMENTS) {
        printf("Error: Circuit component limit reached.\n");
        return;
    }
    circuit[element_count].type = type;
    circuit[element_count].value = value;
    strncpy(circuit[element_count].name, name, sizeof(circuit[element_count].name) - 1);
    circuit[element_count].name[sizeof(circuit[element_count].name) - 1] = '\0'; // Null-terminate
    element_count++;
}

void print_circuit() {
    printf("Current Circuit Elements:\n");
    for (int i = 0; i < element_count; i++) {
        switch (circuit[i].type) {
            case RESISTOR:
                printf("Resistor: %s, Value: %.2f Ohm\n", circuit[i].name, circuit[i].value);
                break;
            case CAPACITOR:
                printf("Capacitor: %s, Value: %.2f Farad\n", circuit[i].name, circuit[i].value);
                break;
            case INDUCTOR:
                printf("Inductor: %s, Value: %.2f Henry\n", circuit[i].name, circuit[i].value);
                break;
            case VOLTAGE_SOURCE:
                printf("Voltage Source: %s, Value: %.2f Volt\n", circuit[i].name, circuit[i].value);
                break;
            case CURRENT_SOURCE:
                printf("Current Source: %s, Value: %.2f Amp\n", circuit[i].name, circuit[i].value);
                break;
            default:
                printf("Unknown Element\n");
                break;
        }
    }
}

double calculate_total_resistance() {
    double total_resistance = 0;
    for (int i = 0; i < element_count; i++) {
        if (circuit[i].type == RESISTOR) {
            total_resistance += circuit[i].value;
        }
    }
    return total_resistance;
}

void simulate() {
    double total_resistance = calculate_total_resistance();
    printf("\nTotal Resistance in the circuit: %.2f Ohm\n", total_resistance);
}

void menu() {
    int choice;
    do {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Add Inductor\n");
        printf("4. Add Voltage Source\n");
        printf("5. Add Current Source\n");
        printf("6. Print Circuit\n");
        printf("7. Simulate Circuit\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 8) {
            break;
        }

        char name[50];
        double value;

        switch (choice) {
            case 1:
                printf("Enter Resistor Name: ");
                scanf("%s", name);
                printf("Enter Resistor Value in Ohm: ");
                scanf("%lf", &value);
                add_element(RESISTOR, value, name);
                break;
            case 2:
                printf("Enter Capacitor Name: ");
                scanf("%s", name);
                printf("Enter Capacitor Value in Farad: ");
                scanf("%lf", &value);
                add_element(CAPACITOR, value, name);
                break;
            case 3:
                printf("Enter Inductor Name: ");
                scanf("%s", name);
                printf("Enter Inductor Value in Henry: ");
                scanf("%lf", &value);
                add_element(INDUCTOR, value, name);
                break;
            case 4:
                printf("Enter Voltage Source Name: ");
                scanf("%s", name);
                printf("Enter Voltage Source Value in Volt: ");
                scanf("%lf", &value);
                add_element(VOLTAGE_SOURCE, value, name);
                break;
            case 5:
                printf("Enter Current Source Name: ");
                scanf("%s", name);
                printf("Enter Current Source Value in Amp: ");
                scanf("%lf", &value);
                add_element(CURRENT_SOURCE, value, name);
                break;
            case 6:
                print_circuit();
                break;
            case 7:
                simulate();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);
}

int main() {
    menu();
    return 0;
}