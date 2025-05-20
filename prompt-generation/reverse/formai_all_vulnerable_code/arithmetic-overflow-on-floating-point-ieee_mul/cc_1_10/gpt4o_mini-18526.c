//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81
#define TIME_STEP 0.1

void simulateProjectile(double initialSpeed, double launchAngle, double totalTime) {
    // Convert angle to radians
    double angleInRadians = launchAngle * (M_PI / 180.0);
    
    // Calculate initial velocities in the x and y directions
    double initialVelX = initialSpeed * cos(angleInRadians);
    double initialVelY = initialSpeed * sin(angleInRadians);
    
    // Initialize time and position variables
    double time = 0.0;
    double posX = 0.0, posY = 0.0;

    printf("Time(s)   Position X(m)   Position Y(m)\n");
    printf("-----------------------------------------\n");
    
    // Simulation loop
    while (time <= totalTime) {
        // Update position
        posX = initialVelX * time;
        posY = initialVelY * time - 0.5 * GRAVITY * time * time;

        // Print the current state of the simulation
        printf("%-10.2f %-14.2f %-14.2f\n", time, posX, posY);

        // Increment time
        time += TIME_STEP;
    }
}

int main() {
    // Define initial conditions
    double initialSpeed, launchAngle, totalTime;

    // User input for initial velocity, angle, and time duration
    printf("Enter initial speed (m/s): ");
    scanf("%lf", &initialSpeed);
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &launchAngle);
    printf("Enter total time for simulation (s): ");
    scanf("%lf", &totalTime);

    // Call simulation function
    simulateProjectile(initialSpeed, launchAngle, totalTime);

    return 0;
}