//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: unmistakable
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159265

// Function to calculate position of mass on spring
double position(double amplitude, double omega, double time) {
    return amplitude * cos(omega * time);
}

// Function to calculate velocity of mass on spring
double velocity(double amplitude, double omega, double time) {
    return -amplitude * omega * sin(omega * time);
}

// Function to calculate acceleration of mass on spring
double acceleration(double amplitude, double omega, double time) {
    return -amplitude * omega * omega * cos(omega * time);
}

// Function to display the system's state
void display(double time, double pos, double vel, double acc) {
    printf("Time: %.2f s | Position: %.2f m | Velocity: %.2f m/s | Acceleration: %.2f m/s²\n", time, pos, vel, acc);
}

int main() {
    // User-defined parameters
    double mass, springConstant, amplitude, omega;
    double time, deltaTime;
    int numSteps;

    // Input parameters from user
    printf("Enter mass (kg): ");
    scanf("%lf", &mass);
    printf("Enter spring constant (N/m): ");
    scanf("%lf", &springConstant);
    printf("Enter maximum displacement (amplitude in m): ");
    scanf("%lf", &amplitude);
    
    // Calculate omega (angular frequency)
    omega = sqrt(springConstant / mass);
    
    printf("Angular frequency (omega): %.2f rad/s\n", omega);

    // Set the simulation time parameters
    printf("Enter the total simulation time (s): ");
    scanf("%lf", &time);
    printf("Enter the time step (s): ");
    scanf("%lf", &deltaTime);
    
    numSteps = (int)(time / deltaTime);
    
    // Simulation loop
    for (int i = 0; i <= numSteps; i++) {
        double currentTime = i * deltaTime;
        double pos = position(amplitude, omega, currentTime);
        double vel = velocity(amplitude, omega, currentTime);
        double acc = acceleration(amplitude, omega, currentTime);
        
        // Display current state
        display(currentTime, pos, vel, acc);
        
        // Control the speed of output
        usleep(100000); // sleep for 100 ms
    }

    return 0;
}