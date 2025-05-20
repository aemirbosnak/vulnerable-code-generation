//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: calm
#include <stdio.h>
#include <math.h>
#include <unistd.h>  // for usleep
#include <stdlib.h>

#define GRAVITY 9.81  // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1 // Time interval for simulation updates (s)

typedef struct {
    double x; // Horizontal position
    double y; // Vertical position
    double vx; // Horizontal velocity
    double vy; // Vertical velocity
    double time; // Total time elapsed
} Projectile;

void initialize_projectile(Projectile* p, double angle, double velocity) {
    p->x = 0.0;
    p->y = 0.0;
    p->time = 0.0;
    p->vx = velocity * cos(angle); // Initial horizontal velocity
    p->vy = velocity * sin(angle); // Initial vertical velocity
}

void update_projectile(Projectile* p) {
    p->time += TIME_STEP; // Increment time
    p->x += p->vx * TIME_STEP; // Update horizontal position
    p->vy -= GRAVITY * TIME_STEP; // Update vertical velocity (gravity acts downwards)
    p->y += p->vy * TIME_STEP; // Update vertical position
}

void print_position(const Projectile* p) {
    printf("Time: %.2f s | Position: (%.2f m, %.2f m)\n", p->time, p->x, p->y);
}

int main() {
    double angle_degrees, initial_velocity;
    
    printf("Welcome to the Projectile Motion Simulator!\n");
    printf("Please enter the launch angle (in degrees): ");
    scanf("%lf", &angle_degrees);
    printf("Please enter the initial velocity (in m/s): ");
    scanf("%lf", &initial_velocity);
    
    // Convert angle to radians
    double angle_radians = angle_degrees * (M_PI / 180.0);
    
    Projectile projectile;
    initialize_projectile(&projectile, angle_radians, initial_velocity);

    printf("\nSimulating projectile motion...\n");
    printf("------------------------------------------------\n");
    printf("Time (s) | Position (m)\n");
    printf("------------------------------------------------\n");

    while (projectile.y >= 0) { // Continue until projectile hits the ground
        print_position(&projectile);
        update_projectile(&projectile);
        usleep(100000); // Pause for 0.1 seconds
    }

    printf("------------------------------------------------\n");
    printf("The projectile has hit the ground.\n");
    return 0;
}