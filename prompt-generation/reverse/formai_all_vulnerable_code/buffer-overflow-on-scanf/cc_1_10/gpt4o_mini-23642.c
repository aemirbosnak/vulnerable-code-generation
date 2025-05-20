//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESISTORS 100

typedef struct {
    double resistance; // Resistance in Ohms
    char name[20];     // Name of the resistor
} Resistor;

typedef struct {
    Resistor resistors[MAX_RESISTORS];
    int count;
} Circuit;

// Function to create a resistor
Resistor create_resistor(const char *name, double resistance) {
    Resistor r;
    strncpy(r.name, name, sizeof(r.name) - 1);
    r.name[sizeof(r.name) - 1] = '\0';
    r.resistance = resistance;
    return r;
}

// Function to add a resistor to the circuit
void add_resistor(Circuit *circuit, Resistor r) {
    if (circuit->count < MAX_RESISTORS) {
        circuit->resistors[circuit->count++] = r;
        printf("Added Resistor: %s (%.2f Ohms)\n", r.name, r.resistance);
    } else {
        printf("Error: Maximum number of resistors reached!\n");
    }
}

// Function to remove a resistor from the circuit
void remove_resistor(Circuit *circuit, const char *name) {
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->resistors[i].name, name) == 0) {
            printf("Removed Resistor: %s (%.2f Ohms)\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
            for (int j = i; j < circuit->count - 1; j++) {
                circuit->resistors[j] = circuit->resistors[j + 1];
            }
            circuit->count--;
            return;
        }
    }
    printf("Resistor %s not found!\n", name);
}

// Function to calculate total resistance in series
double calculate_series_resistance(Circuit *circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        total += circuit->resistors[i].resistance;
    }
    return total;
}

// Function to calculate total resistance in parallel
double calculate_parallel_resistance(Circuit *circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (circuit->resistors[i].resistance != 0) {
            total += 1.0 / circuit->resistors[i].resistance;
        }
    }
    return (total > 0) ? 1.0 / total : 0;
}

// Function to display all resistors in the circuit
void display_resistors(Circuit *circuit) {
    printf("Current Resistors in Circuit:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("%d: %s (%.2f Ohms)\n", i + 1, circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
}

// Main function - Circuit Simulator
int main() {
    Circuit circuit = {{0}, 0};
    int choice;
    char name[20];
    double resistance;

    do {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Remove Resistor\n");
        printf("3. Calculate Series Resistance\n");
        printf("4. Calculate Parallel Resistance\n");
        printf("5. Display Resistors\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Resistor Name: ");
                scanf("%s", name);
                printf("Enter Resistance (Ohms): ");
                scanf("%lf", &resistance);
                add_resistor(&circuit, create_resistor(name, resistance));
                break;

            case 2:
                printf("Enter Resistor Name to Remove: ");
                scanf("%s", name);
                remove_resistor(&circuit, name);
                break;

            case 3:
                printf("Total Series Resistance: %.2f Ohms\n", calculate_series_resistance(&circuit));
                break;

            case 4:
                printf("Total Parallel Resistance: %.2f Ohms\n", calculate_parallel_resistance(&circuit));
                break;

            case 5:
                display_resistors(&circuit);
                break;

            case 6:
                printf("Exiting Simulator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}