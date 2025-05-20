//FormAI DATASET v1.0 Category: Physics simulation ; Style: configurable
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

// Function to calculate gravitational force between two masses
double calculateForce(double m1, double m2, double r) {
    double G = 6.6743e-11; // Gravitational constant
    double F = (G * m1 * m2) / (r * r); // Formula for gravitational force
    return F;
}

int main() {
    double mass1, mass2, distance, angle, velocity;
    // User input for masses, distance, angle and velocity
    printf("Enter the mass of the first object in kg:\n");
    scanf("%lf", &mass1);
    printf("Enter the mass of the second object in kg:\n");
    scanf("%lf", &mass2);
    printf("Enter the distance between the two objects in meters:\n");
    scanf("%lf", &distance);
    printf("Enter the angle of initial velocity of first object in degrees:\n");
    scanf("%lf", &angle);
    printf("Enter the initial velocity of the first object in m/s:\n");
    scanf("%lf", &velocity);
    
    // Convert angle to radians for trigonometric functions
    double theta = angle * PI / 180.0;
    
    // Calculate initial velocities in x and y direction
    double v1x = velocity * cos(theta);
    double v1y = velocity * sin(theta);
    
    // Set initial velocity for second object to zero
    double v2x = 0;
    double v2y = 0;
    
    double t = 0.0; // Starting time
    double dt = 0.01; // Time increment in seconds
    
    // Loop to simulate motion
    while (distance > 0) {
        double r = distance; // Distance between the two objects
        double F = calculateForce(mass1, mass2, r); // Gravitational force between the two objects
        
        // Calculate acceleration for each object in x and y direction
        double a1x = (F / mass1) * cos(theta);
        double a1y = (F / mass1) * sin(theta);
        double a2x = (F / mass2) * cos(theta + PI);
        double a2y = (F / mass2) * sin(theta + PI);
        
        // Calculate new velocities in x and y direction for each object
        v1x += a1x * dt;
        v1y += a1y * dt;
        v2x += a2x * dt;
        v2y += a2y * dt;
        
        // Calculate new positions for each object in x and y direction
        double x1 = v1x * t + 0.5 * a1x * t * t;
        double y1 = v1y * t + 0.5 * a1y * t * t;
        double x2 = v2x * t + 0.5 * a2x * t * t;
        double y2 = v2y * t + 0.5 * a2y * t * t;
        
        // Update distance between the two objects
        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        
        // Print new positions for each object
        printf("Position of object 1: (%lf, %lf)\n", x1, y1);
        printf("Position of object 2: (%lf, %lf)\n", x2, y2);
        
        t += dt; // Increment time
    }
    
    return 0;
}