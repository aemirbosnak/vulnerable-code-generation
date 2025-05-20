//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: invasive
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GRAVITY 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_INTERVAL 0.1 // Time interval for simulation (seconds)
#define MAX_TIME 10.0 // Maximum simulation time (seconds)

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
} Projectile;

void initializeProjectile(Projectile* proj, double angle, double speed) {
    proj->position.x = 0.0;
    proj->position.y = 0.0;
    proj->velocity.x = speed * cos(angle);
    proj->velocity.y = speed * sin(angle);
}

void updateProjectile(Projectile* proj, double dt) {
    proj->position.x += proj->velocity.x * dt;
    proj->position.y += proj->velocity.y * dt;
    proj->velocity.y -= GRAVITY * dt; // Update velocity due to gravity
}

void displayProjectileTrajectory(Projectile* proj, double time) {
    int height = (int)(proj->position.y / 2); // Scale for ASCII display
    if (height < 0) height = 0; // Ensure non-negative height

    printf("Time: %.2f s | ", time);
    for (int i = 0; i < (int)proj->position.x; i++) {
        printf(" ");
    }
    printf("o\n"); // Marks the projectile position
}

int main() {
    double angle_deg, speed;
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &angle_deg);
    printf("Enter launch speed (m/s): ");
    scanf("%lf", &speed);

    // Convert angle from degrees to radians
    double angle_rad = angle_deg * (M_PI / 180.0);

    Projectile projectile;
    initializeProjectile(&projectile, angle_rad, speed);

    double totalTime = 0.0;

    printf("\nProjectile Trajectory:\n");
    printf("-----------------------\n");

    while (projectile.position.y >= 0 && totalTime <= MAX_TIME) {
        displayProjectileTrajectory(&projectile, totalTime);
        updateProjectile(&projectile, TIME_INTERVAL);
        totalTime += TIME_INTERVAL;
    }

    printf("\nSimulation complete!\n");
    printf("Final position: (%.2f, %.2f)\n", projectile.position.x, projectile.position.y);
    return 0;
}