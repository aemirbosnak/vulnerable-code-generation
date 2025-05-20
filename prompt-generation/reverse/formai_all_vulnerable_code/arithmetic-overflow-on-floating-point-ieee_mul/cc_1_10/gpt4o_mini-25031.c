//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // Acceleration due to gravity in m/s^2
#define TIME_INTERVAL 0.1 // Time interval for simulation in seconds

// Structure to represent the projectile
typedef struct {
    double initialSpeed; // Initial speed in m/s
    double angle; // Launch angle in degrees
    double x; // Horizontal position in meters
    double y; // Vertical position in meters
    double time; // Time in seconds
} Projectile;

// Function to convert degrees to radians
double degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

// Function to initialize the projectile
void initializeProjectile(Projectile* p, double speed, double angle) {
    p->initialSpeed = speed;
    p->angle = angle;
    p->x = 0;
    p->y = 0;
    p->time = 0;
}

// Function to update the position of the projectile
void updatePosition(Projectile* p) {
    p->time += TIME_INTERVAL;
    p->x = p->initialSpeed * cos(degreesToRadians(p->angle)) * p->time;
    p->y = (p->initialSpeed * sin(degreesToRadians(p->angle)) * p->time) - 
           (0.5 * GRAVITY * p->time * p->time);
}

// Function to check if the projectile is still in the air
int isInAir(Projectile* p) {
    return p->y >= 0;
}

// Function to display the trajectory of the projectile
void displayTrajectory(Projectile* p) {
    printf("Time: %.2f s, Position: (%.2f m, %.2f m)\n", p->time, p->x, p->y);
}

int main() {
    double speed, angle;
    Projectile projectile;

    // User input for the initial speed and angle
    printf("Enter the initial speed of the projectile (m/s): ");
    scanf("%lf", &speed);
    printf("Enter the launch angle of the projectile (degrees): ");
    scanf("%lf", &angle);

    // Initialize the projectile
    initializeProjectile(&projectile, speed, angle);

    printf("Projectile launched with speed: %.2f m/s and angle: %.2f degrees\n", speed, angle);
    printf("Trajectory of the projectile:\n");

    // Simulate the projectile motion until it hits the ground
    while (isInAir(&projectile)) {
        updatePosition(&projectile);
        displayTrajectory(&projectile);
        usleep(100000); // Sleep for 0.1 seconds
    }

    printf("The projectile has hit the ground.\n");
    return 0;
}