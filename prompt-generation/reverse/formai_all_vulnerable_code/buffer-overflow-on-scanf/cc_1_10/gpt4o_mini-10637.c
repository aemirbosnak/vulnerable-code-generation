//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include <stdio.h>
#include <math.h>

// Constants
#define G 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1 // Time step for the simulation (s)
#define MAX_TIME 10.0 // Maximum time for the simulation (s)

// Function to calculate the x and y positions
void calculateProjectileMotion(double initialVelocity, double angle, double time, double *x, double *y) {
    // Convert angle to radians
    double angleRad = angle * (M_PI / 180.0);
    
    // Calculate the x and y positions
    *x = initialVelocity * cos(angleRad) * time;
    *y = (initialVelocity * sin(angleRad) * time) - (0.5 * G * time * time);
}

// Function to simulate projectile motion
void simulateProjectileMotion(double initialVelocity, double angle) {
    double time;
    double x, y;
    
    printf("Starting projectile motion simulation...\n");
    printf("Initial Velocity: %.2f m/s\n", initialVelocity);
    printf("Launch Angle: %.2f degrees\n", angle);
    printf("Time (s)   X Position (m)   Y Position (m)\n");
    
    for (time = 0; time <= MAX_TIME; time += TIME_STEP) {
        calculateProjectileMotion(initialVelocity, angle, time, &x, &y);
        
        // Stop if the projectile has hit the ground (y <= 0)
        if (y < 0) {
            break;
        }
        
        printf("%.2f\t\t%.2f\t\t%.2f\n", time, x, y);
    }
    
    printf("Projectile hit the ground after %.2f seconds.\n", time);
}

int main() {
    double initialVelocity, angle;

    // User Inputs
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &angle);

    // Validate inputs
    if (initialVelocity <= 0) {
        printf("Initial velocity must be positive!\n");
        return 1;
    }
    if (angle < 0 || angle > 90) {
        printf("Launch angle must be between 0 and 90 degrees!\n");
        return 1;
    }

    // Start simulation
    simulateProjectileMotion(initialVelocity, angle);

    return 0;
}