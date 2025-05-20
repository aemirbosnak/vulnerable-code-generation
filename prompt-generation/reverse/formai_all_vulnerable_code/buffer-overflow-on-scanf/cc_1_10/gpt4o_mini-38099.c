//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include <stdio.h>

typedef struct {
    double resistance; // in Ohms
} Resistor;

typedef struct {
    Resistor *resistors;
    int count;
} Circuit;

double total_resistance(Circuit *circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        total += circuit->resistors[i].resistance;
    }
    return total;
}

double current(double voltage, double resistance) {
    if (resistance == 0) {
        return 0; // To avoid division by zero
    }
    return voltage / resistance; // Ohm's law: I = V/R
}

void display_circuit_info(Circuit *circuit, double voltage) {
    double totalR = total_resistance(circuit);
    double I = current(voltage, totalR);
    printf("Circuit Information:\n");
    printf("Total Resistance: %.2f Ohms\n", totalR);
    printf("Supply Voltage: %.2f Volts\n", voltage);
    printf("Current through the circuit: %.2f Amps\n", I);
}

int main() {
    int num_resistors;
    double supply_voltage;

    printf("Enter the number of resistors in series: ");
    scanf("%d", &num_resistors);

    Circuit circuit;
    circuit.count = num_resistors;
    circuit.resistors = (Resistor *)malloc(num_resistors * sizeof(Resistor));

    for (int i = 0; i < num_resistors; i++) {
        printf("Enter resistance for resistor %d (in Ohms): ", (i + 1));
        scanf("%lf", &circuit.resistors[i].resistance);
    }

    printf("Enter the supply voltage (in Volts): ");
    scanf("%lf", &supply_voltage);

    display_circuit_info(&circuit, supply_voltage);

    free(circuit.resistors);
    return 0;
}