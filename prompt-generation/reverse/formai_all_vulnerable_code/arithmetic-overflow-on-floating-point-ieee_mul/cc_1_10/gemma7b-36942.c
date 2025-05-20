//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the circuit parameters
#define R1 10
#define R2 22
#define C1 100
#define V1 5

// Define the time constants
#define T 0.001
#define T_MAX 1

// Define the simulation variables
double v_out = 0;
double t = 0;
double v_source = V1;

// Main simulation loop
void simulate()
{
    // Calculate the voltage across the capacitor
    double v_cap = v_source * (1 - exp(-t / C1)) - v_out;

    // Calculate the voltage across the resistor
    double v_res = R2 * v_cap;

    // Update the output voltage
    v_out = v_res;

    // Increment the time
    t += T;

    // Repeat the above steps for the specified time
    while (t < T_MAX)
    {
        simulate();
    }
}

// Print the results
int main()
{
    // Simulate the circuit
    simulate();

    // Print the output voltage
    printf("The output voltage is: %.2f volts\n", v_out);

    return 0;
}