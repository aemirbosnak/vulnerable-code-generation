//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct Resistor {
    float resistance; // Resistance in Ohms
};

struct Circuit {
    struct Resistor *resistors;
    int num_resistors;
};

void initializeCircuit(struct Circuit *circuit, int num) {
    circuit->num_resistors = num;
    circuit->resistors = (struct Resistor *)malloc(num * sizeof(struct Resistor));
}

void inputResistorValues(struct Circuit *circuit) {
    for (int i = 0; i < circuit->num_resistors; i++) {
        printf("Enter resistance for resistor %d (in Ohms): ", i + 1);
        scanf("%f", &(circuit->resistors[i].resistance));
    }
}

float calculateTotalResistance(struct Circuit *circuit) {
    float total = 0.0f;
    for (int i = 0; i < circuit->num_resistors; i++) {
        total += circuit->resistors[i].resistance;
    }
    return total;
}

void simulateCircuit(struct Circuit *circuit) {
    float voltage, totalResistance, current;
    printf("Enter the voltage supply (in Volts): ");
    scanf("%f", &voltage);

    totalResistance = calculateTotalResistance(circuit);
    current = voltage / totalResistance;

    printf("\nTotal Resistance: %.2f Ohms\n", totalResistance);
    printf("Circuit Current: %.2f Amps\n", current);
    
    for (int i = 0; i < circuit->num_resistors; i++) {
        float voltageDrop = current * circuit->resistors[i].resistance;
        printf("Voltage drop across Resistor %d: %.2f Volts\n", 
               i + 1, voltageDrop);
    }
}

void freeCircuit(struct Circuit *circuit) {
    free(circuit->resistors);
}

int main() {
    struct Circuit myCircuit;
    int numOfResistors;

    printf("Welcome to the Peaceful Circuit Simulator!\n");
    printf("How many resistors are in your circuit? ");
    scanf("%d", &numOfResistors);

    initializeCircuit(&myCircuit, numOfResistors);
    inputResistorValues(&myCircuit);
    simulateCircuit(&myCircuit);
    freeCircuit(&myCircuit);

    printf("Thank you for simulating with us today. Have a tranquil day!\n");
    return 0;
}