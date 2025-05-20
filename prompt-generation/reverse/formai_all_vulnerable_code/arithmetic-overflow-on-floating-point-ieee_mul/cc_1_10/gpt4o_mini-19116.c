//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <math.h>
#include <unistd.h> // For sleep function
#include <stdlib.h> // For system calls

#define PI 3.14159265
#define GRAVITY 9.81

void clearScreen() {
    // Clear the terminal screen
    system("clear");
}

void displayTrajectory(double initialVelocity, double launchAngle, double timeInterval, double totalTime) {
    double angleInRadians = launchAngle * (PI / 180.0);
    double horizontalVelocity = initialVelocity * cos(angleInRadians);
    double verticalVelocity = initialVelocity * sin(angleInRadians);

    double time = 0.0;
    clearScreen();
    printf("Projectile Motion Simulation\n");
    printf("Initial Velocity: %.2f m/s\n", initialVelocity);
    printf("Launch Angle: %.2f degrees\n", launchAngle);
    printf("Total Time of Flight: %.2f seconds\n\n", (2 * verticalVelocity / GRAVITY));

    printf("Time (s) | Position X (m) | Position Y (m)\n");
    printf("---------------------------------------------\n");
    while (time <= totalTime) {
        double positionX = horizontalVelocity * time;
        double positionY = (verticalVelocity * time) - (0.5 * GRAVITY * time * time);

        if (positionY < 0) {
            positionY = 0; // Prevent negative Y values
        }

        printf("%9.2f | %14.2f | %14.2f\n", time, positionX, positionY);
        usleep((unsigned int)(timeInterval * 1000000)); // Sleep for timeInterval seconds
        time += timeInterval;
    }
}

int main() {
    double initialVelocity, launchAngle, totalTime, timeInterval;

    printf("Welcome to the Projectile Motion Simulator!\n");
    
    // Getting user input
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &launchAngle);
    printf("Enter the simulation time interval (seconds): ");
    scanf("%lf", &timeInterval);

    // Calculate the total time of flight
    double verticalVelocity = initialVelocity * sin(launchAngle * (PI / 180.0));
    totalTime = (2 * verticalVelocity) / GRAVITY;

    displayTrajectory(initialVelocity, launchAngle, timeInterval, totalTime);

    printf("\nSimulation completed!\n");
    return 0;
}