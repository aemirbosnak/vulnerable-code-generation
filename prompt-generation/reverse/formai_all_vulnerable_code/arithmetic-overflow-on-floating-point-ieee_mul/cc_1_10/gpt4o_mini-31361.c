//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: modular
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81

// Function prototypes
void getLaunchParameters(double *angle, double *velocity);
double calculateTimeOfFlight(double angle, double velocity);
double calculateRange(double angle, double velocity);
double calculateMaxHeight(double angle, double velocity);
void simulateProjectile(double angle, double velocity, double timeOfFlight);

int main() {
    double angle, velocity;
    
    // Get launch parameters from user
    getLaunchParameters(&angle, &velocity);
    
    // Calculate projectile motion properties
    double timeOfFlight = calculateTimeOfFlight(angle, velocity);
    double range = calculateRange(angle, velocity);
    double maxHeight = calculateMaxHeight(angle, velocity);
    
    // Output results
    printf("Time of Flight: %.2f seconds\n", timeOfFlight);
    printf("Range: %.2f meters\n", range);
    printf("Max Height: %.2f meters\n", maxHeight);
    
    // Simulate projectile motion
    simulateProjectile(angle, velocity, timeOfFlight);

    return 0;
}

void getLaunchParameters(double *angle, double *velocity) {
    printf("Enter launch angle (degrees): ");
    scanf("%lf", angle);
    printf("Enter launch velocity (m/s): ");
    scanf("%lf", velocity);
}

double calculateTimeOfFlight(double angle, double velocity) {
    // Convert angle from degrees to radians
    double radianAngle = angle * (M_PI / 180.0);
    return (2 * velocity * sin(radianAngle)) / GRAVITY;
}

double calculateRange(double angle, double velocity) {
    // Convert angle from degrees to radians
    double radianAngle = angle * (M_PI / 180.0);
    return (velocity * velocity * sin(2 * radianAngle)) / GRAVITY;
}

double calculateMaxHeight(double angle, double velocity) {
    // Convert angle from degrees to radians
    double radianAngle = angle * (M_PI / 180.0);
    return (velocity * velocity * sin(radianAngle) * sin(radianAngle)) / (2 * GRAVITY);
}

void simulateProjectile(double angle, double velocity, double timeOfFlight) {
    // Time step for simulation
    double timeStep = 0.1;
    double currentTime;
    double radianAngle = angle * (M_PI / 180.0);
    double initialVelocityY = velocity * sin(radianAngle);
    double initialVelocityX = velocity * cos(radianAngle);
    
    printf("\nProjectile motion simulation:\n");
    printf("Time (s)\tPosition X (m)\tPosition Y (m)\n");
    
    for (currentTime = 0; currentTime <= timeOfFlight; currentTime += timeStep) {
        double posX = initialVelocityX * currentTime;
        double posY = initialVelocityY * currentTime - (0.5 * GRAVITY * currentTime * currentTime);
        
        // Check if the projectile hits the ground
        if (posY < 0) {
            posY = 0;
        }
        
        printf("%.2f\t\t%.2f\t\t%.2f\n", currentTime, posX, posY);
    }
}