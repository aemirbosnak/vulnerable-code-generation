//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to hold information about a resistor
typedef struct {
    char name[20];
    double resistance; // in ohms
} Resistor;

// Function to calculate total resistance in series
double calculate_total_resistance(Resistor *resistors, int num_resistors) {
    double total_resistance = 0;
    for (int i = 0; i < num_resistors; i++) {
        total_resistance += resistors[i].resistance;
    }
    return total_resistance;
}

// Function to calculate current using Ohm's Law (I = V/R)
double calculate_current(double voltage, double total_resistance) {
    return voltage / total_resistance;
}

// Function to calculate voltage across each resistor
void calculate_voltages(Resistor *resistors, double current, int num_resistors) {
    printf("\nVoltages across each resistor:\n");
    for (int i = 0; i < num_resistors; i++) {
        double voltage = current * resistors[i].resistance;
        printf("%s: %.2f V\n", resistors[i].name, voltage);
    }
}

int main() {
    int num_resistors;
    printf("Enter the number of resistors in the circuit: ");
    scanf("%d", &num_resistors);

    // Dynamic memory allocation for resistors
    Resistor *resistors = (Resistor *)malloc(num_resistors * sizeof(Resistor));
    if (resistors == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Getting resistor details from user
    for (int i = 0; i < num_resistors; i++) {
        printf("Enter the name of resistor %d: ", i + 1);
        scanf("%s", resistors[i].name);
        printf("Enter the resistance of %s (in ohms): ", resistors[i].name);
        scanf("%lf", &resistors[i].resistance);
    }

    double voltage;
    printf("Enter the power supply voltage (in volts): ");
    scanf("%lf", &voltage);

    // Calculate total resistance and current
    double total_resistance = calculate_total_resistance(resistors, num_resistors);
    double current = calculate_current(voltage, total_resistance);
    
    // Display results
    printf("\nTotal Resistance in the circuit: %.2f ohms\n", total_resistance);
    printf("Total Current flowing through the circuit: %.2f A\n", current);
    
    // Calculate and display the voltage across each resistor
    calculate_voltages(resistors, current, num_resistors);

    // Free the allocated memory
    free(resistors);
    
    return 0;
}