//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define G 9.81 // acceleration due to gravity (m/s^2)

void simulateProjectileMotion(double initialVelocity, double launchAngle);
void displayTrajectory(double time, double x, double y);

int main() {
    double initialVelocity, launchAngle;

    // Get user input for initial velocity and launch angle
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);
    
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &launchAngle);
    
    // Convert angle to radians
    launchAngle = launchAngle * (M_PI / 180);

    // Call the simulation function
    simulateProjectileMotion(initialVelocity, launchAngle);

    return 0;
}

void simulateProjectileMotion(double initialVelocity, double launchAngle) {
    double timeOfFlight = (2 * initialVelocity * sin(launchAngle)) / G; // time of flight formula
    double range = (initialVelocity * cos(launchAngle)) * timeOfFlight; // horizontal range
    double timeInterval = 0.1; // time interval for simulation
    double time = 0.0;

    printf("Time of Flight: %.2f seconds\n", timeOfFlight);
    printf("Horizontal Range: %.2f meters\n\n", range);
    printf("Projectile Trajectory:\n");
    printf("Time (s) \t X (m) \t Y (m)\n");

    // Loop to calculate position at different times
    while (time <= timeOfFlight) {
        double x = initialVelocity * cos(launchAngle) * time; // x position
        double y = initialVelocity * sin(launchAngle) * time - 0.5 * G * time * time; // y position
        
        // Display the trajectory at current time
        displayTrajectory(time, x, y);
        time += timeInterval;

        // Sleep for a short duration to visualize the movement
        usleep(100000); // sleep for 100 milliseconds
    }
}

void displayTrajectory(double time, double x, double y) {
    printf("%.2f \t %.2f \t %.2f\n", time, x, (y < 0) ? 0 : y); // prevent negative y values
}