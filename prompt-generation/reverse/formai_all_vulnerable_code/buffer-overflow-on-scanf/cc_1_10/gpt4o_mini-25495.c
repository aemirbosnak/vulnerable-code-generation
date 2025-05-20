//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 10

typedef struct {
    char type; // 'R' for resistor, 'V' for voltage source
    double value; // resistance in ohms or voltage in volts
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void add_component(Circuit *circuit, char type, double value) {
    if (circuit->count < MAX_COMPONENTS) {
        circuit->components[circuit->count].type = type;
        circuit->components[circuit->count].value = value;
        circuit->count++;
    } else {
        printf("Error: Maximum number of components reached.\n");
    }
}

double total_resistance(Circuit *circuit) {
    double totalR = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'R') {
            totalR += circuit->components[i].value;
        }
    }
    return totalR;
}

double calculate_current(Circuit *circuit) {
    double voltage = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'V') {
            voltage += circuit->components[i].value;
        }
    }
    double resistance = total_resistance(circuit);
    if (resistance != 0) {
        return voltage / resistance;
    } else {
        return 0.0;
    }
}

void print_circuit(Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'R') {
            printf("Resistor: %.2f Ohms\n", circuit->components[i].value);
        } else if (circuit->components[i].type == 'V') {
            printf("Voltage Source: %.2f Volts\n", circuit->components[i].value);
        }
    }
}

int main() {
    Circuit myCircuit = { .count = 0 };
    char choice;
    double value;

    while (1) {
        printf("Circuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Voltage Source\n");
        printf("3. Calculate Total Resistance\n");
        printf("4. Calculate Current\n");
        printf("5. Print Circuit Details\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        choice = getchar();
        getchar(); // Consume newline

        switch (choice) {
            case '1':
                printf("Enter resistor value (Ohms): ");
                scanf("%lf", &value);
                getchar(); // Consume newline
                add_component(&myCircuit, 'R', value);
                break;
            case '2':
                printf("Enter voltage source value (Volts): ");
                scanf("%lf", &value);
                getchar(); // Consume newline
                add_component(&myCircuit, 'V', value);
                break;
            case '3':
                printf("Total Resistance: %.2f Ohms\n", total_resistance(&myCircuit));
                break;
            case '4':
                printf("Circuit Current: %.2f Amps\n", calculate_current(&myCircuit));
                break;
            case '5':
                print_circuit(&myCircuit);
                break;
            case '6':
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    return 0;
}