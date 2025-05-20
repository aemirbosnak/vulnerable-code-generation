//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 9.81 // Acceleration due to gravity (m/s^2)
#define DT 0.01 // Time step (s)

// Define a structure for a projectile
typedef struct {
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
} Projectile;

// Function to initialize the projectile's parameters
void initializeProjectile(Projectile* p, double initialVelocity, double angleInDegrees) {
    p->positionX = 0.0;
    p->positionY = 0.0;
    p->velocityX = initialVelocity * cos(angleInDegrees * (M_PI / 180.0));
    p->velocityY = initialVelocity * sin(angleInDegrees * (M_PI / 180.0));
}

// Function to update the position of the projectile
void updateProjectile(Projectile* p) {
    p->positionX += p->velocityX * DT;
    p->velocityY += -G * DT; // Update velocity due to gravity
    p->positionY += p->velocityY * DT;
}

// Function to display the projectile's state
void displayProjectile(Projectile* p) {
    printf("Position - X: %.2f m, Y: %.2f m\n", p->positionX, p->positionY);
}

// Main function
int main() {
    double initialVelocity, angle;
    
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);
    
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &angle);
    
    Projectile p;
    initializeProjectile(&p, initialVelocity, angle);

    while (p.positionY >= 0) {
        displayProjectile(&p);
        updateProjectile(&p);
        usleep(100000); // Sleep for 0.1 seconds to simulate passage of time
    }
    
    printf("The projectile has hit the ground.\n");
    return 0;
}