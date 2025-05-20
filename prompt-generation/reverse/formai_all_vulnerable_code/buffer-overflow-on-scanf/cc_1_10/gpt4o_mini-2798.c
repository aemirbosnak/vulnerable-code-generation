//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define G 9.81 // Gravitational acceleration in m/s^2
#define TIME_STEP 0.01 // Time step for simulation
#define MAX_PARTICLES 100 // Maximum number of particles

typedef struct {
    double mass; // Mass of the particle
    double x;    // Position in the x-axis
    double y;    // Position in the y-axis
    double vx;   // Velocity in the x-axis
    double vy;   // Velocity in the y-axis
} Particle;

Particle particles[MAX_PARTICLES];
int particle_count = 0;

void initialize_particle(double mass, double x, double y, double vx, double vy) {
    if (particle_count < MAX_PARTICLES) {
        particles[particle_count].mass = mass;
        particles[particle_count].x = x;
        particles[particle_count].y = y;
        particles[particle_count].vx = vx;
        particles[particle_count].vy = vy;
        particle_count++;
    } else {
        printf("Maximum particle limit reached!\n");
    }
}

void update_particle(Particle *p) {
    // Update the velocity and position of the particle
    p->vy -= G * TIME_STEP; // Apply gravity
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;

    // Simple ground collision
    if (p->y < 0) {
        p->y = 0;
        p->vy *= -0.5; // Reverse velocity and lose energy
    }
}

void print_particles() {
    for (int i = 0; i < particle_count; i++) {
        printf("Particle %d: Mass: %.2f kg, Position: (%.2f, %.2f), Velocity: (%.2f, %.2f)\n", 
            i, 
            particles[i].mass,
            particles[i].x, 
            particles[i].y, 
            particles[i].vx, 
            particles[i].vy
        );
    }
}

void run_simulation(double duration) {
    double time = 0;
    while (time < duration) {
        printf("\nTime: %.2f s\n", time);
        for (int i = 0; i < particle_count; i++) {
            update_particle(&particles[i]);
        }
        print_particles();
        usleep(100000); // Sleep for 100 milliseconds for better readability
        time += TIME_STEP;
    }
}

int main() {
    double mass, x, y, vx, vy;

    // Sample input for particle initialization
    printf("Enter properties for particles (mass, x, y, vx, vy). Enter -1 to stop:\n");
    while (1) {
        printf("Particle %d -> ", particle_count + 1);
        scanf("%lf", &mass);
        if (mass == -1) break; // Exit condition
        scanf("%lf %lf %lf %lf", &x, &y, &vx, &vy);
        initialize_particle(mass, x, y, vx, vy);
    }

    // Run the simulation for 5 seconds
    run_simulation(5.0);

    return 0;
}