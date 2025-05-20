//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>

// Define maximum values for circuit components
#define MAX_RESISTANCE 10.0
#define MAX_CAPACITANCE 5.0
#define MAX_INDUCTANCE 2.0

// Define struct for circuit components
typedef struct {
    char type;
    float value;
} component;

// Define function to calculate impedance of a circuit
float calculate_impedance(component* circuit, int num_components) {
    float impedance = 0.0;
    for (int i = 0; i < num_components; i++) {
        if (circuit[i].type == 'R') { // resistance
            impedance += circuit[i].value;
        } else if (circuit[i].type == 'C') { // capacitance
            impedance -= 1.0 / (circuit[i].value * 2 * 3.14159);
        } else if (circuit[i].type == 'L') { // inductance
            impedance += circuit[i].value * 2 * 3.14159;
        }
    }
    return impedance;
}

int main() {
    // Welcome message
    printf("Welcome to the Classical Circuit Simulator!\n");
    printf("Please enter your circuit components one by one...\n");

    // Define array to store circuit components
    component circuit[5];
    int num_components = 0;

    // Loop to get user input for circuit components
    while (num_components < 5) {
        char type;
        float value;

        // Prompt user for component type and value
        printf("Component #%d: ", num_components+1);
        scanf("%c %f", &type, &value);

        // Check that component type is valid
        if (type != 'R' && type != 'C' && type != 'L') {
            printf("Invalid component type! Please try again...\n");
            continue;
        }

        // Check that component value is valid
        if (type == 'R' && (value < 0 || value > MAX_RESISTANCE)) {
            printf("Invalid resistance value! Please try again...\n");
            continue;
        } else if (type == 'C' && (value < 0 || value > MAX_CAPACITANCE)) {
            printf("Invalid capacitance value! Please try again...\n");
            continue;
        } else if (type == 'L' && (value < 0 || value > MAX_INDUCTANCE)) {
            printf("Invalid inductance value! Please try again...\n");
            continue;
        }

        // Add component to circuit
        circuit[num_components].type = type;
        circuit[num_components].value = value;
        num_components++;

        // Clear stdin buffer
        while (getchar() != '\n');
    }

    // Calculate impedance of circuit
    float impedance = calculate_impedance(circuit, num_components);

    // Output the results
    printf("Your circuit has an impedance of %.2f Ohms.\n", impedance);

    // End program
    return 0;
}