//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_RESISTORS 10

typedef struct {
    float resistors[MAX_RESISTORS];
    int count;
} Circuit;

void add_resistor(Circuit *circuit, float resistance) {
    if (circuit->count < MAX_RESISTORS) {
        circuit->resistors[circuit->count++] = resistance;
    } else {
        printf("Max resistor limit reached!\n");
    }
}

float calculate_series_current(Circuit *circuit, float voltage) {
    float total_resistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        total_resistance += circuit->resistors[i];
    }
    return voltage / total_resistance;
}

float calculate_parallel_current(Circuit *circuit, float voltage) {
    float inverse_total_resistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        inverse_total_resistance += 1 / circuit->resistors[i];
    }
    float total_resistance = 1 / inverse_total_resistance;
    return voltage / total_resistance;
}

void display_circuit(Circuit *circuit) {
    printf("Circuit configuration with %d resistors:\n", circuit->count);
    for (int i = 0; i < circuit->count; i++) {
        printf("R%d: %.2f Ω\n", i + 1, circuit->resistors[i]);
    }
}

int main() {
    Circuit circuit;
    circuit.count = 0;
    int choice;
    float voltage;
    int i;
    float resistance;

    printf("Welcome to the Classical Circuit Simulator!\n");
    printf("You can simulate either a series or parallel circuit.\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a resistor\n");
        printf("2. Calculate series circuit current\n");
        printf("3. Calculate parallel circuit current\n");
        printf("4. Display circuit\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance value (in ohms): ");
                scanf("%f", &resistance);
                add_resistor(&circuit, resistance);
                break;

            case 2:
                printf("Enter the voltage (in volts): ");
                scanf("%f", &voltage);
                display_circuit(&circuit);
                printf("Current in series configuration: %.2f A\n", calculate_series_current(&circuit, voltage));
                break;

            case 3:
                printf("Enter the voltage (in volts): ");
                scanf("%f", &voltage);
                display_circuit(&circuit);
                printf("Current in parallel configuration: %.2f A\n", calculate_parallel_current(&circuit, voltage));
                break;

            case 4:
                display_circuit(&circuit);
                break;

            case 5:
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}