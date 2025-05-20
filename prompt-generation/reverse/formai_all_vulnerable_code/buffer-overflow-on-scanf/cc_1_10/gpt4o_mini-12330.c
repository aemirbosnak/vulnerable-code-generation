//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>

#define MAX_RESISTORS 10

// Function to calculate total resistance in series
float calculateTotalResistance(float resistors[], int count) {
    float totalResistance = 0.0;
    for (int i = 0; i < count; i++) {
        totalResistance += resistors[i];
    }
    return totalResistance;
}

// Function to calculate current using Ohm's Law
float calculateCurrent(float voltage, float totalResistance) {
    return voltage / totalResistance;
}

// Function to calculate voltage drop across each resistor
void calculateVoltageDrops(float voltage, float resistors[], int count, float voltageDrops[]) {
    float totalResistance = calculateTotalResistance(resistors, count);
    for (int i = 0; i < count; i++) {
        voltageDrops[i] = (resistors[i] / totalResistance) * voltage;
    }
}

// Main function
int main() {
    float voltage;                      // Supply voltage
    float resistors[MAX_RESISTORS];    // Array to store resistor values
    float voltageDrops[MAX_RESISTORS];  // Array to store voltage drops across resistors
    int numResistors;                   // Number of resistors

    printf("Welcome to the Simple Circuit Simulator!\n\n");
    
    // Input supply voltage
    printf("Enter the supply voltage (in Volts): ");
    scanf("%f", &voltage);

    // Input number of resistors
    printf("Enter the number of resistors (max %d): ", MAX_RESISTORS);
    scanf("%d", &numResistors);

    // Input each resistor value
    for (int i = 0; i < numResistors; i++) {
        printf("Enter value for resistor %d (in Ohms): ", i + 1);
        scanf("%f", &resistors[i]);
    }

    // Calculate total resistance
    float totalResistance = calculateTotalResistance(resistors, numResistors);
    printf("\nTotal Resistance in the circuit: %.2f Ohms\n", totalResistance);
    
    // Calculate current in the circuit
    float current = calculateCurrent(voltage, totalResistance);
    printf("Current flowing through the circuit: %.2f Amps\n", current);
    
    // Calculate voltage drops for each resistor
    calculateVoltageDrops(voltage, resistors, numResistors, voltageDrops);

    // Display voltage drops
    printf("\nVoltage drops across each resistor:\n");
    for (int i = 0; i < numResistors; i++) {
        printf("Voltage drop across resistor %d: %.2f Volts\n", i + 1, voltageDrops[i]);
    }

    printf("\nThank you for using the Circuit Simulator!\n");
    return 0;
}