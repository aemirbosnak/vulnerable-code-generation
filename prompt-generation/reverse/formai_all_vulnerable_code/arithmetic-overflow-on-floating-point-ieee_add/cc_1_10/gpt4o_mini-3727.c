//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double resistance; // Ohms
    double capacitance; // Farads
    double inductance; // Henrys
} Component;

typedef struct {
    double voltage; // Volts
    double current; // Amperes
    double frequency; // Hertz
} Circuit;

void calculate_current(Component *comp, Circuit *circ) {
    // Simple Ohm's Law: I = V/R
    if (comp->resistance != 0) {
        circ->current = circ->voltage / comp->resistance;
    } else {
        circ->current = 0; // Infinite current if resistance is zero
    }
}

void calculate_impedance(Component *comp, Circuit *circ) {
    // Assuming a series circuit: Z = sqrt(R^2 + (1/(2πfC))^2 + (2πfL)^2)
    double XL = 2 * M_PI * circ->frequency * comp->inductance;
    double XC = 1 / (2 * M_PI * circ->frequency * comp->capacitance);
    double impedance = sqrt(comp->resistance * comp->resistance + (XC - XL) * (XC - XL));
    
    printf("Impedance of the circuit: %.2f Ohms\n", impedance);
}

void simulate_circuit(Component *comp, Circuit *circ) {
    printf("Simulating circuit with Voltage: %.2f Volts\n", circ->voltage);
    calculate_current(comp, circ);
    printf("Calculated Current: %.2f Amperes\n", circ->current);
    calculate_impedance(comp, circ);
}

void display_intro() {
    printf("Circuit Simulator Version 1.0\n");
    printf("Created in the spirit of computational exploration.\n");
    printf("This simulation computes the current and impedance of a simple circuit.\n");
    printf("-------------------------------------------\n");
}

int main() {
    Component comp;
    Circuit circ;

    display_intro();
    
    // Getting user input
    printf("Enter the resistance (Ohms): ");
    scanf("%lf", &comp.resistance);
    
    printf("Enter the capacitance (Farads): ");
    scanf("%lf", &comp.capacitance);
    
    printf("Enter the inductance (Henrys): ");
    scanf("%lf", &comp.inductance);
    
    printf("Enter the voltage (Volts): ");
    scanf("%lf", &circ.voltage);
    
    printf("Enter the frequency (Hertz): ");
    scanf("%lf", &circ.frequency);
    
    // Simulate the circuit
    simulate_circuit(&comp, &circ);
    
    return 0;
}