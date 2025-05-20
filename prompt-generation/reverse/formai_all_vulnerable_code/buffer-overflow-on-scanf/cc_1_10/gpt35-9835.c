//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>

// Define variables for circuit elements
float res1, res2, cap1, ind1, volt, freq;

// Define variables for calculated values
float react, impedance, current, voltage_drop, power;

int main() {

    // Get user input for circuit element values
    printf("Enter resistance of resistor 1 in ohms: ");
    scanf("%f", &res1);

    printf("Enter resistance of resistor 2 in ohms: ");
    scanf("%f", &res2);

    printf("Enter capacitance of capacitor 1 in farads: ");
    scanf("%f", &cap1);

    printf("Enter inductance of inductor 1 in henrys: ");
    scanf("%f", &ind1);

    printf("Enter voltage of source in volts: ");
    scanf("%f", &volt);

    printf("Enter frequency of source in hertz: ");
    scanf("%f", &freq);

    // Calculate reactive element value
    react = 1/(2*3.14159*freq*cap1) - 2*3.14159*freq*ind1;

    // Calculate impedance of circuit
    impedance = res1 + res2 + react;

    // Calculate current through circuit
    current = volt / impedance;

    // Calculate voltage drop across resistors
    voltage_drop = current * res1;

    // Calculate power dissipated by resistors
    power = voltage_drop * current;

    // Print results
    printf("\nCircuit Analysis Results\n");
    printf("========================\n");
    printf("Impedance: %.2f ohms\n", impedance);
    printf("Current: %.2f amps\n", current);
    printf("Voltage drop across resistor 1: %.2f volts\n", voltage_drop);
    printf("Power dissipated by resistor 1: %.2f watts\n", power);

    return 0;
}