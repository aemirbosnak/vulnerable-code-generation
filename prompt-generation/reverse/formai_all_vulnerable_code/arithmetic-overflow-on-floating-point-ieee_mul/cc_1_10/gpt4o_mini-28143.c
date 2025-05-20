//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159265358979323846

// Struct to hold the circuit components
typedef struct {
    double resistance; // Resistance in Ohms
    double capacitance; // Capacitance in Farads
    double voltage; // Voltage in Volts
} Circuit;

// Function to simulate charging of the capacitor
void simulateCharging(Circuit *circuit, double timeDuration) {
    double timeStep = 0.01; // Time step in seconds
    printf("Charging Simulation:\n");
    printf("Time(s)\tVoltage(V)\n");

    for (double t = 0; t <= timeDuration; t += timeStep) {
        double voltageAcrossCapacitor = circuit->voltage * (1 - exp(-t / (circuit->resistance * circuit->capacitance)));
        printf("%.2f\t%.2f\n", t, voltageAcrossCapacitor);
        usleep(100000); // Sleep for 0.1 seconds to simulate real-time display
    }
}

// Function to simulate discharging of the capacitor
void simulateDischarging(Circuit *circuit, double timeDuration) {
    double timeStep = 0.01; // Time step in seconds
    printf("Discharging Simulation:\n");
    printf("Time(s)\tVoltage(V)\n");

    // Initially charged to the supply voltage
    double initialVoltage = circuit->voltage;

    for (double t = 0; t <= timeDuration; t += timeStep) {
        double voltageAcrossCapacitor = initialVoltage * exp(-t / (circuit->resistance * circuit->capacitance));
        printf("%.2f\t%.2f\n", t, voltageAcrossCapacitor);
        usleep(100000); // Sleep for 0.1 seconds to simulate real-time display
    }
}

int main() {
    Circuit circuit;

    // User input for circuit parameters
    printf("Welcome to the RC Circuit Simulator!\n");
    printf("Enter resistance (in Ohms): ");
    scanf("%lf", &circuit.resistance);
    printf("Enter capacitance (in Farads): ");
    scanf("%lf", &circuit.capacitance);
    printf("Enter supply voltage (in Volts): ");
    scanf("%lf", &circuit.voltage);

    double simulateTime;
    printf("Enter the time duration for simulation (in seconds): ");
    scanf("%lf", &simulateTime);

    // Run the charging simulation
    simulateCharging(&circuit, simulateTime);
    
    printf("\nPress Enter to continue to discharging simulation...");
    getchar(); // To consume the newline character from previous input
    getchar(); // Wait for user to press Enter

    // Run the discharging simulation
    simulateDischarging(&circuit, simulateTime);

    printf("\nSimulation complete!\n");
    return 0;
}