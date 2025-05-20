//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: Alan Turing
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 9.81 // Gravitational constant
#define TIME_STEP 0.1 // Time interval for simulation
#define MAX_TIME 20.0 // Maximum time to simulate

typedef struct {
    double x;   // x position
    double y;   // y position
} Position;

typedef struct {
    double vx;  // x velocity
    double vy;  // y velocity
} Velocity;

Position calculate_position(double initial_velocity, double angle_degrees, double time) {
    // Convert degrees to radians for calculations
    double angle_radians = angle_degrees * (M_PI / 180.0);
    Position pos;
    
    // Calculate the position using the projectile motion equations
    pos.x = initial_velocity * cos(angle_radians) * time;
    pos.y = (initial_velocity * sin(angle_radians) * time) - (0.5 * G * time * time);
    
    return pos;
}

void simulate_projectile(double initial_velocity, double angle_degrees) {
    printf("Simulating projectile motion with initial velocity: %.2f m/s, angle: %.2f degrees\n", 
            initial_velocity, angle_degrees);
    
    double time;
    Position pos;

    for (time = 0; time <= MAX_TIME; time += TIME_STEP) {
        pos = calculate_position(initial_velocity, angle_degrees, time);
        
        // Stop simulation if projectile hits the ground
        if (pos.y < 0) {
            break;
        }

        printf("Time: %.2f s | Position: (%.2f m, %.2f m)\n", time, pos.x, pos.y);
    }
}

int main() {
    double initial_velocity;
    double angle_degrees;

    printf("Enter the initial velocity of the projectile (m/s): ");
    scanf("%lf", &initial_velocity);
    printf("Enter the launch angle of the projectile (degrees): ");
    scanf("%lf", &angle_degrees);

    simulate_projectile(initial_velocity, angle_degrees);

    return 0;
}