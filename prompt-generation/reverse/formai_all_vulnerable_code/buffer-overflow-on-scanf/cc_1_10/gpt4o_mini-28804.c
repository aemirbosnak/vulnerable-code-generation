//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: synchronous
#include <stdio.h>

#define MAX_RESISTORS 10

void displayCircuit(double resistors[], int count, double voltage);
double calculateTotalResistance(double resistors[], int count);
double calculateCurrent(double voltage, double totalResistance);
void calculateVoltageDrops(double resistors[], int count, double current);

int main() {
    double resistors[MAX_RESISTORS];
    double voltage;
    int count;

    printf("Welcome to the Circuit Simulator!\n");
    printf("How many resistors do you want to include in your circuit (max %d)? ", MAX_RESISTORS);
    scanf("%d", &count);

    if (count < 1 || count > MAX_RESISTORS) {
        printf("Invalid number of resistors. Please enter a number between 1 and %d.\n", MAX_RESISTORS);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter value of resistor %d (in ohms): ", i + 1);
        scanf("%lf", &resistors[i]);
    }

    printf("Enter the voltage of the power supply (in volts): ");
    scanf("%lf", &voltage);

    displayCircuit(resistors, count, voltage);

    return 0;
}

void displayCircuit(double resistors[], int count, double voltage) {
    double totalResistance = calculateTotalResistance(resistors, count);
    double current = calculateCurrent(voltage, totalResistance);

    printf("\n--- Circuit Details ---\n");
    printf("Total Resistance: %.2f ohms\n", totalResistance);
    printf("Current flowing through the circuit: %.2f A\n", current);
    
    calculateVoltageDrops(resistors, count, current);
}

double calculateTotalResistance(double resistors[], int count) {
    double totalResistance = 0.0;
    for (int i = 0; i < count; i++) {
        totalResistance += resistors[i];
    }
    return totalResistance;
}

double calculateCurrent(double voltage, double totalResistance) {
    if (totalResistance == 0) {
        printf("Total resistance is zero, current cannot be calculated.\n");
        return 0;
    }
    return voltage / totalResistance;
}

void calculateVoltageDrops(double resistors[], int count, double current) {
    printf("Voltage drops across each resistor:\n");
    for (int i = 0; i < count; i++) {
        double voltageDrop = current * resistors[i];
        printf("Resistor %d: %.2f V\n", i + 1, voltageDrop);
    }
}