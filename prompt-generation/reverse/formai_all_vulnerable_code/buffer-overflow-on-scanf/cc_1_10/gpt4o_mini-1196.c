//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define constants
#define GRAVITY 9.81
#define PI 3.14159265358979323846

// Structure to hold projectile data
typedef struct {
    double initial_velocity; // in m/s
    double launch_angle;     // in degrees
    double time;             // in seconds
    double x_position;       // x position (horizontal)
    double y_position;       // y position (vertical)
} Projectile;

// Function to initialize the projectile
void initialize_projectile(Projectile *p, double velocity, double angle) {
    p->initial_velocity = velocity;
    p->launch_angle = angle;
    p->time = 0.0;
    p->x_position = 0.0;
    p->y_position = 0.0;
}

// Function to update projectile's position based on time
void update_position(Projectile *p, double delta_t) {
    p->time += delta_t;
    double angle_rad = p->launch_angle * (PI / 180); // Convert degrees to radians
    p->x_position = p->initial_velocity * cos(angle_rad) * p->time;
    p->y_position = (p->initial_velocity * sin(angle_rad) * p->time) - (0.5 * GRAVITY * p->time * p->time);
}

// Function to check if the projectile hit the ground
int check_ground(Projectile *p) {
    return p->y_position < 0;
}

// Function to run the simulation
void run_simulation(double initial_velocity, double launch_angle, double delta_t) {
    Projectile p;
    initialize_projectile(&p, initial_velocity, launch_angle);
    
    printf("Initial Velocity: %.2f m/s\n", initial_velocity);
    printf("Launch Angle: %.2f degrees\n", launch_angle);
    printf("Time(s)\tX(m)\tY(m)\n");
    
    while (!check_ground(&p)) {
        printf("%.2f\t%.2f\t%.2f\n", p.time, p.x_position, p.y_position);
        update_position(&p, delta_t);
    }
    
    printf("Projectile hit the ground at x = %.2f m after %.2f seconds\n", p.x_position, p.time);
}

// Main function
int main() {
    double initial_velocity, launch_angle, delta_t;
    
    // Get user input for the simulation parameters
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &initial_velocity);
    
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &launch_angle);
    
    printf("Enter time step for simulation (s): ");
    scanf("%lf", &delta_t);
    
    // Run the simulation
    run_simulation(initial_velocity, launch_angle, delta_t);
    
    return 0;
}