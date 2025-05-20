//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Structure to represent a particle
typedef struct {
    double mass;         // Mass of the particle in kg
    double x;            // x-coordinate of the particle in meters
    double y;            // y-coordinate of the particle in meters
    double z;            // z-coordinate of the particle in meters
    double vx;           // x-component of the particle's velocity in m/s
    double vy;           // y-component of the particle's velocity in m/s
    double vz;           // z-component of the particle's velocity in m/s
    double fx;           // x-component of the force acting on the particle in N
    double fy;           // y-component of the force acting on the particle in N
    double fz;           // z-component of the force acting on the particle in N
} Particle;

// Function to initialize a particle
void initialize_particle(Particle *particle, double mass, double x, double y, double z, double vx, double vy, double vz) {
    particle->mass = mass;
    particle->x = x;
    particle->y = y;
    particle->z = z;
    particle->vx = vx;
    particle->vy = vy;
    particle->vz = vz;
    particle->fx = 0;
    particle->fy = 0;
    particle->fz = 0;
}

// Function to calculate the force acting on a particle due to gravity
void calculate_gravity_force(Particle *particle, double gravitational_constant, double earth_mass) {
    double distance = sqrt(particle->x * particle->x + particle->y * particle->y + particle->z * particle->z);
    double force = gravitational_constant * earth_mass * particle->mass / (distance * distance);
    particle->fx = -force * particle->x / distance;
    particle->fy = -force * particle->y / distance;
    particle->fz = -force * particle->z / distance;
}

// Function to integrate the equations of motion for a particle
void integrate_equations_of_motion(Particle *particle, double timestep) {
    // Update the particle's position
    particle->x += particle->vx * timestep;
    particle->y += particle->vy * timestep;
    particle->z += particle->vz * timestep;

    // Update the particle's velocity
    particle->vx += particle->fx / particle->mass * timestep;
    particle->vy += particle->fy / particle->mass * timestep;
    particle->vz += particle->fz / particle->mass * timestep;
}

// Function to simulate the motion of a particle for a given number of timesteps
void simulate_particle_motion(Particle *particle, double timestep, int num_timesteps) {
    for (int i = 0; i < num_timesteps; i++) {
        // Calculate the force acting on the particle due to gravity
        calculate_gravity_force(particle, 6.674e-11, 5.972e24);

        // Integrate the equations of motion for the particle
        integrate_equations_of_motion(particle, timestep);
    }
}

// Main function
int main() {
    // Initialize the particle
    Particle particle;
    initialize_particle(&particle, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

    // Set the simulation parameters
    double timestep = 1.0;
    int num_timesteps = 1000;

    // Simulate the motion of the particle
    simulate_particle_motion(&particle, timestep, num_timesteps);

    // Print the final position of the particle
    printf("Final position of the particle: (%.2f, %.2f, %.2f)\n", particle.x, particle.y, particle.z);

    return 0;
}