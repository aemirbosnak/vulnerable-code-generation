//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159265358979323846
#define GRAVITY 9.81
#define TIME_STEP 0.1
#define MAX_TIME 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double initial_velocity;
    double launch_angle;
    Point position;
    double time;
} Projectile;

void initializeProjectile(Projectile *p, double velocity, double angle) {
    p->initial_velocity = velocity;
    p->launch_angle = angle * (PI / 180.0); // Convert angle to radians
    p->position.x = 0;
    p->position.y = 0;
    p->time = 0;
}

void updatePosition(Projectile *p) {
    p->time += TIME_STEP;
    p->position.x = p->initial_velocity * cos(p->launch_angle) * p->time;
    p->position.y = p->initial_velocity * sin(p->launch_angle) * p->time - 0.5 * GRAVITY * pow(p->time, 2);
}

void printTrajectory(Projectile *p) {
    printf("Time: %.2fs | Position: (%.2f, %.2f)\n", p->time, p->position.x, p->position.y);
}

int main() {
    Projectile projectile;
    double initial_velocity, launch_angle;

    printf("Enter the initial velocity of the projectile (m/s): ");
    scanf("%lf", &initial_velocity);
    printf("Enter the launch angle of the projectile (degrees): ");
    scanf("%lf", &launch_angle);

    initializeProjectile(&projectile, initial_velocity, launch_angle);

    printf("Simulating projectile motion...\n");
    printf("---------------------------------------------------------\n");
    printf("Time (s) | X (m) | Y (m)\n");

    while (projectile.position.y >= 0 && projectile.time <= MAX_TIME) {
        printTrajectory(&projectile);
        updatePosition(&projectile);
        usleep(100000); // Sleep for 100 milliseconds for better visibility
    }

    printf("---------------------------------------------------------\n");
    printf("Simulation ended. Maximum height reached: %.2f m\n", projectile.position.y + 0.5 * GRAVITY * pow(projectile.time, 2));

    return 0;
}