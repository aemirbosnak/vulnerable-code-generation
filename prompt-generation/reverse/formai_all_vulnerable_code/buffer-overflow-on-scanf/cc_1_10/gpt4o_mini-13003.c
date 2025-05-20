//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>

#define MAX_COMPONENTS 10

// Structure to represent a resistor
typedef struct {
    char name[20];
    float resistance; // Ohms
} Resistor;

// Function to add a resistor to the circuit
void add_resistor(Resistor *resistors, int *count) {
    if (*count >= MAX_COMPONENTS) {
        printf("Cannot add more resistors, limit reached!\n");
        return;
    }

    printf("Enter the name of resistor %d: ", *count + 1);
    scanf("%s", resistors[*count].name);
    printf("Enter the resistance of %s (in Ohms): ", resistors[*count].name);
    scanf("%f", &resistors[*count].resistance);
    (*count)++;
}

// Function to calculate total resistance in series
float total_resistance(Resistor *resistors, int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += resistors[i].resistance;
    }
    return total;
}

// Function to calculate the current flowing through the circuit
float calculate_current(float voltage, float resistance) {
    if (resistance == 0) {
        printf("Resistance cannot be zero, current is undefined!\n");
        return -1;
    }
    return voltage / resistance;
}

// Main function to run the circuit simulator
int main() {
    Resistor resistors[MAX_COMPONENTS];
    int count = 0;
    float voltage;

    printf("Welcome to the Simple Circuit Simulator!\n");

    // Adding resistors to the circuit
    char choice;
    do {
        add_resistor(resistors, &count);
        printf("Do you want to add another resistor? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Getting the voltage of the source
    printf("Enter the voltage of the source (in Volts): ");
    scanf("%f", &voltage);

    // Calculating total resistance
    float totalRes = total_resistance(resistors, count);
    printf("Total Resistance in Series: %.2f Ohms\n", totalRes);

    // Calculating current
    float current = calculate_current(voltage, totalRes);
    if (current != -1) {
        printf("Current flowing through the circuit: %.2f Amps\n", current);
    }

    // Display the circuit components
    printf("\n--- Circuit Components ---\n");
    for (int i = 0; i < count; i++) {
        printf("Resistor %d: %s, Resistance: %.2f Ohms\n", i + 1, resistors[i].name, resistors[i].resistance);
    }

    printf("Thank you for using the Circuit Simulator!\n");
    return 0;
}