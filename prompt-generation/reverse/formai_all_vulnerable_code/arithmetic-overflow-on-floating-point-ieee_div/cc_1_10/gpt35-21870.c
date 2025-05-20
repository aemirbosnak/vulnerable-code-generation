//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
// Romeo and Juliet C Circuit Simulator

#include <stdio.h>
#include <math.h>

// Define circuit components
typedef struct {
    double voltage;
    double current;
} Resistor;

typedef struct {
    double voltage;
    double current;
    double capacitance;
} Capacitor;

typedef struct {
    double voltage;
    double current;
    double inductance;
} Inductor;

// Define circuit functions
double compute_resistor_current(Resistor r) {
    return r.voltage / r.current;
}

double compute_capacitor_current(Capacitor c, double time) {
    return c.voltage * c.capacitance * exp(-time / c.capacitance);
}

double compute_inductor_current(Inductor l, double time) {
    return l.current + (l.voltage / l.inductance) * time;
}

// Main function
int main() {
    // Initialize components
    Resistor r = {10, 0}; // Romeo represents a resistor with voltage of 10V and current 0A
    Capacitor c = {5, 0, 0.1}; // Juliet represents a capacitor with voltage of 5V, current 0A and capacitance 0.1F
    Inductor l = {0, 0, 0.05}; // Friar represents an inductor with zero voltage, current, and inductance of 0.05H

    // Display initial states
    printf("Romeo, a resistor with voltage of %.1fV and current of %.1fA, meets Juliet, a capacitor with voltage of %.1fV, current of %.1fA, and capacitance of %.1fF.\n", r.voltage, r.current, c.voltage, c.current, c.capacitance);
    printf("Friar, an inductor with zero voltage, current, and inductance of %.2fH, brings them together to form a circuit.\n", l.inductance);

    // Time loop
    double time = 0;
    double dt = 0.01;
    while (time < 1) {
        // Compute component currents
        double irc = compute_resistor_current(r);
        double icc = compute_capacitor_current(c, time);
        double ilc = compute_inductor_current(l, time);

        // Compute total current
        double itotal = -(irc + icc + ilc);

        // Update component currents
        r.current = irc;
        c.current = icc;
        l.current = ilc;

        // Update component voltages
        r.voltage = irc * r.voltage;
        c.voltage = icc / c.capacitance;
        l.voltage = -l.inductance * itotal;

        // Display current states
        printf("%.2fs: Romeo has a current of %.2fA, Juliet has a current of %.2fA, and Friar has a current of %.2fA.\n", time, r.current, c.current, l.current);

        // Increment time
        time += dt;
    }

    // Display final message
    printf("And thus the circuit is complete. Let the current flow and the love between Romeo and Juliet never fade away.\n");

    return 0;
}