//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: calm
/*
 * Gravitational Simulation
 *
 * Simulates the motion of a collection of point masses under the influence of gravity.
 *
 * Usage:
 *   ./gravitational_simulation <input_file> <output_file> <timesteps>
 *
 * Input file format:
 *   The first line contains the number of particles.
 *   Each subsequent line contains the mass, initial position, and initial velocity of a particle, in the following format:
 *     mass x y z vx vy vz
 *
 * Output file format:
 *   Each line contains the time, and the position and velocity of each particle, in the following format:
 *     time x y z vx vy vz
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant (N m^2 kg^-2)

typedef struct {
    double mass;
    double x, y, z;  // Position (m)
    double vx, vy, vz; // Velocity (m/s)
} Particle;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <timesteps>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the input file.
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    int num_particles;
    fscanf(input_file, "%d", &num_particles);

    Particle *particles = malloc(num_particles * sizeof(Particle));
    if (particles == NULL) {
        perror("Error allocating memory for particles");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_particles; i++) {
        fscanf(input_file, "%lf %lf %lf %lf %lf %lf %lf",
            &particles[i].mass,
            &particles[i].x, &particles[i].y, &particles[i].z,
            &particles[i].vx, &particles[i].vy, &particles[i].vz);
    }

    fclose(input_file);

    // Open the output file.
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Get the number of timesteps.
    int timesteps = atoi(argv[3]);

    // Time step (s)
    double dt = 0.001;

    // Simulate the motion of the particles.
    for (int t = 0; t < timesteps; t++) {
        // Calculate the gravitational forces on each particle.
        for (int i = 0; i < num_particles; i++) {
            particles[i].vx = 0;
            particles[i].vy = 0;
            particles[i].vz = 0;
            for (int j = 0; j < num_particles; j++) {
                if (i == j) {
                    continue;
                }

                // Calculate the distance between the particles.
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double dz = particles[j].z - particles[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);

                // Calculate the gravitational force between the particles.
                double f = G * particles[i].mass * particles[j].mass / (r * r);

                // Calculate the acceleration on particle i due to particle j.
                double ax = f * dx / r;
                double ay = f * dy / r;
                double az = f * dz / r;

                // Update the velocity of particle i.
                particles[i].vx += ax * dt;
                particles[i].vy += ay * dt;
                particles[i].vz += az * dt;
            }
        }

        // Update the positions of the particles.
        for (int i = 0; i < num_particles; i++) {
            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;
            particles[i].z += particles[i].vz * dt;
        }

        fprintf(output_file, "%d", t);
        for (int i = 0; i < num_particles; i++) {
            fprintf(output_file, " %lf %lf %lf %lf %lf %lf",
                particles[i].x, particles[i].y, particles[i].z,
                particles[i].vx, particles[i].vy, particles[i].vz);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    free(particles);

    return EXIT_SUCCESS;
}