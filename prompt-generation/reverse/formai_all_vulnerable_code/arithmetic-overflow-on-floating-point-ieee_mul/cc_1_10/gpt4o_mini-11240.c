//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define G 9.81 // Acceleration due to gravity in m/s^2
#define TIME_STEP 0.01 // Time step for the simulation in seconds
#define MAX_TIME 10.0 // Total time for the simulation in seconds

typedef struct {
    double x; // x position
    double y; // y position
    double vx; // x velocity
    double vy; // y velocity
    double mass; // mass of the object
} Object;

void initObject(Object *obj, double x, double y, double vx, double vy, double mass) {
    obj->x = x;
    obj->y = y;
    obj->vx = vx;
    obj->vy = vy;
    obj->mass = mass;
}

void updatePosition(Object *obj) {
    obj->x += obj->vx * TIME_STEP;
    obj->y += obj->vy * TIME_STEP;
}

void applyGravity(Object *obj) {
    obj->vy -= G * TIME_STEP; // Gravity affects the y velocity
}

void printObjectState(Object *obj, double t) {
    printf("Time: %.2f s | Position: (%.2f, %.2f) | Velocity: (%.2f, %.2f) | Mass: %.2f\n", 
           t, obj->x, obj->y, obj->vx, obj->vy, obj->mass);
}

void simulate(Object *obj) {
    for(double t = 0; t <= MAX_TIME; t += TIME_STEP) {
        applyGravity(obj);
        updatePosition(obj);
        printObjectState(obj, t);
        
        if (obj->y <= 0) { // Stop simulation if the object hits the ground
            printf("Object hit the ground!\n");
            break;
        }
    }
}

int main() {
    Object projectile;
    double initialHeight, initialVelocity, launchAngle, launchVx, launchVy;

    // Input parameters for the projectile
    printf("Enter initial height (in meters): ");
    scanf("%lf", &initialHeight);
    printf("Enter initial velocity (in m/s): ");
    scanf("%lf", &initialVelocity);
    printf("Enter launch angle (in degrees): ");
    scanf("%lf", &launchAngle);

    // Convert launch angle to radians
    launchAngle = launchAngle * (PI / 180.0);
    
    // Calculate initial velocity components
    launchVx = initialVelocity * cos(launchAngle);
    launchVy = initialVelocity * sin(launchAngle);

    // Initialize the object
    initObject(&projectile, 0, initialHeight, launchVx, launchVy, 1.0); // Mass set to 1.0 kg

    // Start the simulation
    simulate(&projectile);

    return 0;
}