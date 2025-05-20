//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: immersive
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h> // For usleep

#define GRAVITY 9.81

// Structure to hold projectile data
typedef struct {
    double initialSpeed;
    double launchAngle; // in degrees
    double time; // time of flight
    double x; // x position
    double y; // y position
} Projectile;

// Function to initialize the projectile
void initializeProjectile(Projectile *p, double speed, double angle) {
    p->initialSpeed = speed;
    p->launchAngle = angle;
    p->time = 0.0;
    p->x = 0.0;
    p->y = 0.0;
}

// Function to update the position of the projectile
void updatePosition(Projectile *p) {
    double angleInRadians = p->launchAngle * (M_PI / 180.0);
    p->x = p->initialSpeed * cos(angleInRadians) * p->time;
    p->y = (p->initialSpeed * sin(angleInRadians) * p->time) - (0.5 * GRAVITY * p->time * p->time);
}

// Function to simulate projectile motion
void simulateProjectileMotion(Projectile *p) {
    printf("Time (s)\tPosition X (m)\tPosition Y (m)\n");
    printf("------------------------------------------------\n");
    
    while (p->y >= 0) {
        updatePosition(p);
        printf("%.2f\t\t%.2f\t\t%.2f\n", p->time, p->x, p->y);
        
        // Increment time
        p->time += 0.1; // Update time by 0.1 seconds
        usleep(100000); // Simulate delay of 100 ms for visual effect
    }
    
    printf("------------------------------------------------\n");
    printf("Projectile has hit the ground!\n");
}

int main() {
    double speed, angle;
    Projectile projectile;

    // User input
    printf("Welcome to the Projectile Motion Simulator!\n");
    printf("Enter the initial speed of the projectile (m/s): ");
    scanf("%lf", &speed);
    printf("Enter the launch angle of the projectile (degrees): ");
    scanf("%lf", &angle);

    // Initialize the projectile
    initializeProjectile(&projectile, speed, angle);

    // Start simulation
    simulateProjectileMotion(&projectile);

    return 0;
}