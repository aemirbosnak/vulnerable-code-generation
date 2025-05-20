//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define G 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1 // Time step for simulation (seconds)
#define MAX_TIME 5.0 // Maximum simulation time (seconds)

// Structure to represent a projectile
typedef struct {
    double x; // Position in x-axis
    double y; // Position in y-axis
    double vx; // Velocity in x-axis
    double vy; // Velocity in y-axis
} Projectile;

// Function to initialize the projectile
void initializeProjectile(Projectile* p, double initialSpeed, double angle) {
    p->x = 0.0; // Initial x position
    p->y = 0.0; // Initial y position
    p->vx = initialSpeed * cos(angle); // Initial x velocity
    p->vy = initialSpeed * sin(angle); // Initial y velocity
}

// Function to update the projectile's position
void updateProjectile(Projectile* p) {
    // Update velocity due to gravity
    p->vy -= G * TIME_STEP;

    // Update position
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;
}

// Function to check if the projectile has hit the ground
int hasHitGround(Projectile* p) {
    return p->y < 0;
}

int main() {
    double initialSpeed, angle;
    printf("Welcome to the Surprise Projectile Simulation!\n");
    printf("Enter the initial speed (m/s): ");
    scanf("%lf", &initialSpeed);
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &angle);
    angle = angle * (M_PI / 180.0); // Convert angle to radians

    Projectile projectile;
    initializeProjectile(&projectile, initialSpeed, angle);

    printf("Let's see how your projectile flies!\n");
    printf("Simulation in progress...\n");

    double timePassed = 0.0;
    while (timePassed < MAX_TIME && !hasHitGround(&projectile)) {
        printf("Time: %.2f s | Position: (%.2f, %.2f) m | Velocity: (%.2f, %.2f) m/s\n",
               timePassed, projectile.x, projectile.y, projectile.vx, projectile.vy);
        
        // Update the projectile
        updateProjectile(&projectile);
        
        // Sleep for a moment to simulate real-time observation
        usleep(100000); // 100 ms
        timePassed += TIME_STEP;
    }

    if (hasHitGround(&projectile)) {
        printf("Oops! Your projectile has hit the ground!\n");
    } else {
        printf("Time's up! The projectile didn't hit the ground yet!\n");
    }

    printf("Final Position: (%.2f, %.2f) m\n", projectile.x, projectile.y);
    return 0;
}