//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 100

typedef struct {
    char type; // 'R' for Resistor, 'V' for Voltage source
    float value; // Ohms for Resistors, Volts for Voltage sources
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
} Circuit;

void add_resistor(Circuit *circuit, float resistance) {
    if (circuit->count < MAX_COMPONENTS) {
        circuit->components[circuit->count].type = 'R';
        circuit->components[circuit->count].value = resistance;
        circuit->count++;
    } else {
        printf("Cannot add more components, circuit limit reached!\n");
    }
}

void add_voltage_source(Circuit *circuit, float voltage) {
    if (circuit->count < MAX_COMPONENTS) {
        circuit->components[circuit->count].type = 'V';
        circuit->components[circuit->count].value = voltage;
        circuit->count++;
    } else {
        printf("Cannot add more components, circuit limit reached!\n");
    }
}

float calculate_total_resistance(Circuit *circuit) {
    float total_resistance = 0.0f;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'R') {
            total_resistance += circuit->components[i].value;
        }
    }
    return total_resistance;
}

float calculate_total_voltage(Circuit *circuit) {
    float total_voltage = 0.0f;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->components[i].type == 'V') {
            total_voltage += circuit->components[i].value;
        }
    }
    return total_voltage;
}

float calculate_current(Circuit *circuit) {
    float total_resistance = calculate_total_resistance(circuit);
    float total_voltage = calculate_total_voltage(circuit);
    
    if (total_resistance > 0) {
        return total_voltage / total_resistance;
    }
    return 0.0f; // If resistance is zero or undefined
}

void display_circuit(Circuit *circuit) {
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
    Circuit circuit;
    circuit.count = 0;

    char choice;
    float value;

    printf("Welcome to the Classical Circuit Simulator!\n");
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Resistor (R)\n");
        printf("2. Add Voltage Source (V)\n");
        printf("3. Display Circuit\n");
        printf("4. Calculate Total Resistance\n");
        printf("5. Calculate Total Voltage\n");
        printf("6. Calculate Current\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter resistance (Ohms): ");
                scanf("%f", &value);
                add_resistor(&circuit, value);
                break;

            case '2':
                printf("Enter voltage (Volts): ");
                scanf("%f", &value);
                add_voltage_source(&circuit, value);
                break;

            case '3':
                display_circuit(&circuit);
                break;

            case '4':
                printf("Total Resistance: %.2f Ohms\n", calculate_total_resistance(&circuit));
                break;

            case '5':
                printf("Total Voltage: %.2f Volts\n", calculate_total_voltage(&circuit));
                break;

            case '6':
                printf("Current in the circuit: %.2f Amps\n", calculate_current(&circuit));
                break;

            case '7':
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}