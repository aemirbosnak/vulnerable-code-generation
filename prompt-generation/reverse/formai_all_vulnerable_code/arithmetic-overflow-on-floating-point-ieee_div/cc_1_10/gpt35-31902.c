//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define constants for the circuit components
#define R1 1000.0 // Resistor 1 (ohms)
#define R2 2000.0 // Resistor 2 (ohms)
#define C1 0.000001 // Capacitor 1 (farads)
#define C2 0.0000001 // Capacitor 2 (farads)

// Define a function for computing the voltage across R2
double compute_voltage(double v_in, double t) {
    // Define variables for the circuit's state variables
    static double v_C1 = 0.0; // Voltage across capacitor 1
    static double v_C2 = 0.0; // Voltage across capacitor 2
    static double i_R1 = 0.0; // Current through resistor 1
    static double i_R2 = 0.0; // Current through resistor 2
    
    // Compute the new voltage across capacitor 1
    double delta_vc1 = ((v_in - v_C1) / (R1 * C1)) * (1.0 / t);
    v_C1 += delta_vc1;

    // Compute the new current through resistor 1
    i_R1 = v_C1 / R1;

    // Compute the new voltage across capacitor 2
    double delta_vc2 = ((i_R1 - i_R2) * C2) * (1.0 / t);
    v_C2 += delta_vc2;

    // Compute the new current through resistor 2
    i_R2 = v_C2 / R2;

    // Return the voltage across R2
    return i_R2 * R2;
}

int main() {
    double v_in = 1.0; // Input voltage
    double t_step = 0.00001; // Time step (seconds)
    double t = 0.0; // Current time
    int num_steps = 10000000; // Number of time steps to simulate
    
    // Simulate the circuit for the specified number of time steps
    for (int i = 0; i < num_steps; i++) {
        // Compute the voltage across R2 and print it
        double v_R2 = compute_voltage(v_in, t);
        printf("%lf\n", v_R2);

        // Increment the time
        t += t_step;
    }

    return 0;
}