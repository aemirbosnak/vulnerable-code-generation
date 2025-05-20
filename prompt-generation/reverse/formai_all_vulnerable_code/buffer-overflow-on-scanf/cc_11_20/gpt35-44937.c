//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num_planets;
    printf("How many planets in the simulation? ");
    scanf("%d", &num_planets);

    double G = 6.674e-11;
    double dt = 60*60*24; // 1 day in seconds
    double time = 0;
    double distances[num_planets][num_planets];
    double velocities[num_planets][3];
    double positions[num_planets][3];
    double masses[num_planets];
    char planet_names[num_planets][20];

    // get planet data
    for(int i = 0; i < num_planets; i++) {
        printf("Planet %d:\n", i+1);
        printf("Name: ");
        scanf("%s", planet_names[i]);
        printf("Mass (kg): ");
        scanf("%lf", &masses[i]);
        printf("Position (x y z meters): ");
        scanf("%lf %lf %lf", &positions[i][0], &positions[i][1], &positions[i][2]);
        printf("Velocity (x y z m/s): ");
        scanf("%lf %lf %lf", &velocities[i][0], &velocities[i][1], &velocities[i][2]);
    }

    // calculate initial distances and energies
    double init_total_energy = 0;
    for(int i = 0; i < num_planets; i++) {
        for(int j = 0; j < num_planets; j++) {
            double dx = positions[j][0] - positions[i][0];
            double dy = positions[j][1] - positions[i][1];
            double dz = positions[j][2] - positions[i][2];
            double dist = sqrt(dx*dx + dy*dy + dz*dz);
            distances[i][j] = dist;
            if(i != j) {
                double energy = (-G * masses[i] * masses[j]) / dist;
                init_total_energy += energy;
            }
        }
    }

    // start simulation loop
    double total_energy = init_total_energy;
    while(time < 365*24*60*60) { // simulate for 1 year
        // calculate new positions
        for(int i = 0; i < num_planets; i++) {
            for(int j = 0; j < 3; j++) {
                positions[i][j] += velocities[i][j] * dt;
            }
        }

        // calculate new velocities
        total_energy = 0;
        for(int i = 0; i < num_planets; i++) {
            for(int j = 0; j < num_planets; j++) {
                if(i != j) {
                    double dx = positions[j][0] - positions[i][0];
                    double dy = positions[j][1] - positions[i][1];
                    double dz = positions[j][2] - positions[i][2];
                    double dist = sqrt(dx*dx + dy*dy + dz*dz);
                    double f = (G * masses[i] * masses[j]) / (dist*dist);
                    double fx = f*dx/dist;
                    double fy = f*dy/dist;
                    double fz = f*dz/dist;
                    velocities[i][0] += fx * dt / masses[i];
                    velocities[i][1] += fy * dt / masses[i];
                    velocities[i][2] += fz * dt / masses[i];
                    total_energy += (-G * masses[i] * masses[j]) / dist;
                }
            }
        }

        // print current positions and total energy
        printf("Time: %lf s\n", time);
        printf("Total Energy: %lf J\n", total_energy);
        for(int i = 0; i < num_planets; i++) {
            printf("%s: %lf %lf %lf m\n", planet_names[i], positions[i][0], positions[i][1], positions[i][2]);
        }

        time += dt;
    }

    return 0;
}