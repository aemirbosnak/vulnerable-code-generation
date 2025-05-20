//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>

typedef struct {
    float resistance; // Resistance in Ohms
} Resistor;

void calculateTotalResistance(Resistor resistors[], int count, float *totalResistance) {
    *totalResistance = 0;
    for (int i = 0; i < count; i++) {
        *totalResistance += resistors[i].resistance;
    }
}

void calculateCurrent(float voltage, float totalResistance, float *current) {
    *current = voltage / totalResistance;
}

void calculateVoltageDrops(Resistor resistors[], int count, float current, float voltageDrops[]) {
    for (int i = 0; i < count; i++) {
        voltageDrops[i] = resistors[i].resistance * current;
    }
}

void printResults(float voltage, float totalResistance, float current, float voltageDrops[], int count) {
    printf("\n--- Circuit Analysis Results ---\n");
    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    printf("Input Voltage: %.2f Volts\n", voltage);
    printf("Current through the Circuit: %.2f Amperes\n", current);
    for (int i = 0; i < count; i++) {
        printf("Voltage Drop across Resistor %d: %.2f Volts\n", i + 1, voltageDrops[i]);
    }
    printf("-----------------------------\n");
}

int main() {
    int resistorCount;
    printf("Welcome to the Circuit Simulator!\n");
    printf("Could you please tell me how many resistors are in your series circuit? ");
    scanf("%d", &resistorCount);

    Resistor resistors[resistorCount];
    float voltage;

    for (int i = 0; i < resistorCount; i++) {
        printf("What is the resistance of Resistor %d (in Ohms)? ", i + 1);
        scanf("%f", &resistors[i].resistance);
    }

    printf("What is the voltage of the source (in Volts)? ");
    scanf("%f", &voltage);

    float totalResistance;
    calculateTotalResistance(resistors, resistorCount, &totalResistance);

    float current;
    calculateCurrent(voltage, totalResistance, &current);

    float voltageDrops[resistorCount];
    calculateVoltageDrops(resistors, resistorCount, current, voltageDrops);

    printResults(voltage, totalResistance, current, voltageDrops, resistorCount);

    return 0;
}