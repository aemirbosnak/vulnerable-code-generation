//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define GRAVITY 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1 // Time step for simulation (seconds)

typedef struct {
    double x; // x position
    double y; // y position
    double vx; // x velocity
    double vy; // y velocity
} Projectile;

void initializeProjectile(Projectile *p, double angle, double speed) {
    p->x = 0.0;
    p->y = 0.0;
    p->vx = speed * cos(angle);
    p->vy = speed * sin(angle);
}

void updateProjectile(Projectile *p) {
    p->vx = p->vx; // x velocity remains constant
    p->vy = p->vy - GRAVITY * TIME_STEP; // update y velocity
    p->x += p->vx * TIME_STEP; // update x position
    p->y += p->vy * TIME_STEP; // update y position
}

void printPosition(const Projectile *p) {
    printf("Position: (%.2f, %.2f)\n", p->x, p->y);
}

int main() {
    double angle, speed;

    printf("Welcome to the Projectile Motion Simulator!\n");
    printf("Enter the initial speed of the projectile (in m/s): ");
    scanf("%lf", &speed);
    printf("Enter the launch angle of the projectile (in degrees): ");
    scanf("%lf", &angle);

    // Convert angle from degrees to radians
    angle = angle * (M_PI / 180.0);

    Projectile p;
    initializeProjectile(&p, angle, speed);

    printf("Launching projectile...\n");
    
    while (p.y >= 0) {
        printPosition(&p);
        updateProjectile(&p);
        usleep(100000); // sleep for 0.1 seconds (100000 microseconds)
    }

    printf("Projectile has hit the ground.\n");
    return 0;
}