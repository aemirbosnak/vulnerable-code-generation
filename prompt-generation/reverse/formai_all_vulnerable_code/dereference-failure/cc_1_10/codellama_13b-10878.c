//Code Llama-13B DATASET v1.0 Category: Physics simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the structs for the particles and the simulation
struct particle {
    double x;
    double y;
    double vx;
    double vy;
};

struct simulation {
    struct particle *particles;
    int num_particles;
    double time_step;
    double time_total;
};

// Function to initialize the simulation
void init_simulation(struct simulation *sim) {
    sim->num_particles = 1000;
    sim->particles = malloc(sim->num_particles * sizeof(struct particle));
    for (int i = 0; i < sim->num_particles; i++) {
        sim->particles[i].x = (double)rand() / RAND_MAX * 100.0 - 50.0;
        sim->particles[i].y = (double)rand() / RAND_MAX * 100.0 - 50.0;
        sim->particles[i].vx = (double)rand() / RAND_MAX * 2.0 - 1.0;
        sim->particles[i].vy = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }
    sim->time_step = 0.01;
    sim->time_total = 100.0;
}

// Function to update the position and velocity of each particle
void update_particles(struct simulation *sim) {
    for (int i = 0; i < sim->num_particles; i++) {
        sim->particles[i].x += sim->particles[i].vx * sim->time_step;
        sim->particles[i].y += sim->particles[i].vy * sim->time_step;
        sim->particles[i].vx += (double)rand() / RAND_MAX * 0.01 - 0.005;
        sim->particles[i].vy += (double)rand() / RAND_MAX * 0.01 - 0.005;
    }
}

// Function to calculate the potential energy of the system
double calc_potential_energy(struct simulation *sim) {
    double energy = 0.0;
    for (int i = 0; i < sim->num_particles; i++) {
        for (int j = i + 1; j < sim->num_particles; j++) {
            double dx = sim->particles[i].x - sim->particles[j].x;
            double dy = sim->particles[i].y - sim->particles[j].y;
            double r = sqrt(dx * dx + dy * dy);
            energy += 1.0 / r;
        }
    }
    return energy;
}

// Function to calculate the kinetic energy of the system
double calc_kinetic_energy(struct simulation *sim) {
    double energy = 0.0;
    for (int i = 0; i < sim->num_particles; i++) {
        energy += 0.5 * (sim->particles[i].vx * sim->particles[i].vx + sim->particles[i].vy * sim->particles[i].vy);
    }
    return energy;
}

// Function to calculate the total energy of the system
double calc_total_energy(struct simulation *sim) {
    return calc_potential_energy(sim) + calc_kinetic_energy(sim);
}

// Function to calculate the temperature of the system
double calc_temperature(struct simulation *sim) {
    return 2.0 * calc_kinetic_energy(sim) / (3.0 * sim->num_particles);
}

// Function to print the simulation data
void print_simulation(struct simulation *sim) {
    printf("Simulation: %d particles, time step = %f, total time = %f\n", sim->num_particles, sim->time_step, sim->time_total);
    printf("Potential energy = %f, kinetic energy = %f, total energy = %f\n", calc_potential_energy(sim), calc_kinetic_energy(sim), calc_total_energy(sim));
    printf("Temperature = %f\n", calc_temperature(sim));
}

// Main function
int main() {
    struct simulation sim;
    init_simulation(&sim);
    for (int i = 0; i < sim.time_total / sim.time_step; i++) {
        update_particles(&sim);
        print_simulation(&sim);
    }
    return 0;
}