//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: medieval
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define GRAVITY 9.81
#define TIME_STEP 0.1
#define MAX_ITERATIONS 1000

typedef struct {
    double x;       // X position
    double y;       // Y position
    double vx;      // Velocity in X
    double vy;      // Velocity in Y
    double mass;    // Mass of the object
} Projectile;

void initialize_projectile(Projectile *p, double x, double y, double speed, double angle, double mass) {
    p->x = x;
    p->y = y;
    p->vx = speed * cos(angle);
    p->vy = speed * sin(angle);
    p->mass = mass;
}

void update_position(Projectile *p) {
    p->vy -= GRAVITY * TIME_STEP; // Update vertical velocity
    p->x += p->vx * TIME_STEP;     // Update horizontal position
    p->y += p->vy * TIME_STEP;     // Update vertical position

    // If the projectile falls below the ground level (y=0), make it 'land'
    if (p->y < 0) {
        p->y = 0;
        p->vy = 0; // Stop vertical movement upon landing
    }
}

void print_position(int iteration, Projectile *p) {
    printf("Iteration: %3d | Position: (%.2f, %.2f) | Velocity: (%.2f, %.2f)\n",
           iteration, p->x, p->y, p->vx, p->vy);
}

int main() {
    Projectile cannonball;
    double launch_speed, launch_angle, initial_x, initial_y;

    // Medieval artillery simulation setup
    printf("Enter the initial position (x y) of the cannonball (in meters): ");
    scanf("%lf %lf", &initial_x, &initial_y);
    
    printf("Enter the launch speed (in meters/second): ");
    scanf("%lf", &launch_speed);
    
    printf("Enter the launch angle (in degrees): ");
    scanf("%lf", &launch_angle);
    
    // Convert angle to radians
    launch_angle = launch_angle * (M_PI / 180.0);
    
    // Initialize cannonball
    initialize_projectile(&cannonball, initial_x, initial_y, launch_speed, launch_angle, 1.0);

    printf("\nThe cannonball is launched!\n");
    
    // Begin simulation
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        print_position(i, &cannonball);
        update_position(&cannonball);
        
        // Pause for visual clarity
        usleep(100000); // 100 ms delay

        // Break out of the loop if it has landed
        if (cannonball.y == 0) {
            printf("The cannonball has landed safely!\n");
            break;
        }
    }

    printf("Final Position after %d iterations: (%.2f, %.2f)\n", 
           MAX_ITERATIONS, cannonball.x, cannonball.y);
    
    return 0;
}