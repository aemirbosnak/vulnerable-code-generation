//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

// Constants for physics simulation
#define GRAVITY 9.81 // Acceleration due to gravity in m/s^2
#define TIME_STEP 0.01 // Time step for simulation in seconds

// Structure to hold information about the projectile
typedef struct {
    double position_x; // x position
    double position_y; // y position
    double velocity_x; // x velocity
    double velocity_y; // y velocity
} Projectile;

// Function to initialize the projectile with given parameters
void initialize_projectile(Projectile *p, double initial_velocity, double angle) {
    p->position_x = 0.0; // Start at the origin
    p->position_y = 0.0; // Start at the origin
    // Convert angle to radians and calculate initial velocities
    double angle_rad = angle * (M_PI / 180.0);
    p->velocity_x = initial_velocity * cos(angle_rad);
    p->velocity_y = initial_velocity * sin(angle_rad);
}

// Function to update the projectile's position and velocity
void update_projectile(Projectile *p) {
    // Update position
    p->position_x += p->velocity_x * TIME_STEP;
    p->position_y += p->velocity_y * TIME_STEP;

    // Update velocity due to gravity
    p->velocity_y -= GRAVITY * TIME_STEP;

    // Check for ground collision
    if (p->position_y < 0) {
        p->position_y = 0; // Reset to ground level
        p->velocity_y = 0; // Stop the projectile
    }
}

// Function to print the current state of the simulation
void print_simulation_state(int step, Projectile *p) {
    printf("Step: %d | Position: (%.2f, %.2f) | Velocity: (%.2f, %.2f)\n", 
           step, p->position_x, p->position_y, p->velocity_x, p->velocity_y);
}

// Sherlock Holmes style simulation of a projectile
void sherlock_holmes_simulation(double initial_velocity, double launch_angle) {
    // Creating a Projectile instance
    Projectile p;
    initialize_projectile(&p, initial_velocity, launch_angle);
    
    // Simulation loop
    int step = 0;
    while (p.position_y >= 0) {
        print_simulation_state(step, &p);
        update_projectile(&p);
        step++;
    }

    printf("The projectile has come to rest after %d steps.\n", step);
}

int main() {
    double initial_velocity, launch_angle;
    
    // Retrieve input from the user
    printf("Enter initial velocity of the projectile (m/s): ");
    scanf("%lf", &initial_velocity);
    
    printf("Enter launch angle of the projectile (degrees): ");
    scanf("%lf", &launch_angle);
    
    // Start the simulation
    printf("Initiating Sherlock Holmes' projectile analysis...\n");
    sherlock_holmes_simulation(initial_velocity, launch_angle);
    
    return 0;
}