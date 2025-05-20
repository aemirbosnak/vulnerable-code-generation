//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: complete
#include <stdio.h>
#include <math.h>
#include <unistd.h> // For usleep function

#define GRAVITY 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_INCREMENT 0.1 // Time increment for simulation update (s)

typedef struct {
    double x; // horizontal position
    double y; // vertical position
    double angle; // launch angle in degrees
    double velocity; // initial velocity in m/s
    double time; // current time
} Projectile;

void initializeProjectile(Projectile *p) {
    p->x = 0;
    p->y = 0;
    p->time = 0;
}

void updatePosition(Projectile *p) {
    // Convert angle to radians for computation
    double angleRad = p->angle * (M_PI / 180.0);
    double initialVelocityY = p->velocity * sin(angleRad);
    double initialVelocityX = p->velocity * cos(angleRad);
    
    // Update time
    p->time += TIME_INCREMENT;

    // Update projectile's position using kinematic equations
    p->x = initialVelocityX * p->time;
    p->y = initialVelocityY * p->time - 0.5 * GRAVITY * p->time * p->time;
}

void printPosition(Projectile *p) {
    printf("Time: %.2fs | Position -> X: %.2fm, Y: %.2fm\n", p->time, p->x, p->y);
}

int main() {
    Projectile p;
    
    // User input for projectile parameters
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &p.velocity);
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &p.angle);

    initializeProjectile(&p);

    // Simulation loop
    printf("Starting projectile motion simulation...\n");
    while (p.y >= 0) {
        updatePosition(&p);
        printPosition(&p);
        usleep(100000); // Sleep for 100 milliseconds to simulate time increment
    }

    printf("Projectile has hit the ground.\n");
    return 0;
}