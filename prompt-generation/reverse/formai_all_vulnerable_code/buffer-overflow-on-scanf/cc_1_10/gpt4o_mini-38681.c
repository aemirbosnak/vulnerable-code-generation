//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TIME 10.0
#define TIME_STEP 0.1

typedef struct {
    double resistance; // in Ohms
    double capacitance; // in Farads
    double inductance; // in Henries
} CircuitElement;

void simulateCircuit(CircuitElement elements, double voltageSource) {
    double time = 0.0;
    double current = 0.0;
    double charge = 0.0;
    double dt = TIME_STEP;

    printf("Time(s)   Current(A)   Charge(C)\n");
    printf("------------------------------------\n");

    while (time <= MAX_TIME) {
        // Update charge based on the current and capacitance
        charge += current * dt;

        // Calculate current using the RC charging equation:
        // I(t) = (V - (Q/C)) / R
        double voltageAcrossCapacitor = charge / elements.capacitance;
        current = (voltageSource - voltageAcrossCapacitor) / elements.resistance;

        printf("%-10.2f %-12.6f %-12.6f\n", time, current, charge);

        // Increment time
        time += dt;
    }
}

int main() {
    CircuitElement elements;
    double voltageSource;

    // Input circuit parameters
    printf("Enter the resistance (Ohms): ");
    scanf("%lf", &elements.resistance);

    printf("Enter the capacitance (Farads): ");
    scanf("%lf", &elements.capacitance);

    printf("Enter the inductance (Henries): ");
    scanf("%lf", &elements.inductance);

    printf("Enter the source voltage (Volts): ");
    scanf("%lf", &voltageSource);

    // Simulate the circuit
    simulateCircuit(elements, voltageSource);

    return 0;
}