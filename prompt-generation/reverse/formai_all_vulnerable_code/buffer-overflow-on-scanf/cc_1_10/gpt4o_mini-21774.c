//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define GRAVITY 9.81     // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.01   // Time step for simulation (s)
#define MAX_TIME 10      // Maximum simulation time (s)

typedef struct {
    float x;           // Horizontal position (m)
    float y;           // Vertical position (m)
    float vx;          // Horizontal velocity (m/s)
    float vy;          // Vertical velocity (m/s)
} Projectile;

void initialize_projectile(Projectile *p, float angle, float speed) {
    p->x = 0.0;  // Start at origin
    p->y = 0.0;  // Ground level
    p->vx = speed * cos(angle); // Calculate x velocity
    p->vy = speed * sin(angle); // Calculate y velocity
}

void update_position(Projectile *p) {
    p->x += p->vx * TIME_STEP; // Update horizontal position
    p->y += p->vy * TIME_STEP; // Update vertical position

    // Update vertical velocity due to gravity
    p->vy -= GRAVITY * TIME_STEP;

    // Check if projectile hits the ground
    if (p->y < 0) {
        p->y = 0;
        p->vy = 0; // Stop the projectile
    }
}

void print_trajectory(Projectile *p, float time) {
    printf("Time: %.2f s | X: %.2f m | Y: %.2f m \n", time, p->x, p->y);
}

int main() {
    float angle, speed;
    printf("Enter launch angle (degrees): ");
    scanf("%f", &angle);
    angle = angle * (M_PI / 180.0); // Convert to radians

    printf("Enter launch speed (m/s): ");
    scanf("%f", &speed);

    Projectile projectile;
    initialize_projectile(&projectile, angle, speed);

    printf("Simulating projectile motion...\n");

    for (float t = 0; t <= MAX_TIME; t += TIME_STEP) {
        update_position(&projectile);
        print_trajectory(&projectile, t);
        usleep(100000); // Sleep for 100 milliseconds to simulate real-time
    }

    return 0;
}