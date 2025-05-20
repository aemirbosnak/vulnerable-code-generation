//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.674e-11 // Gravitational Constant

int main() {
    int i, j, k;
    double dt = 0.1; // Timestep
    double sim_time = 100; // Simulation Time
    int num_planets = 3; // Number of Planets
    double mass[num_planets]; // Array to Store Mass
    double pos[num_planets][3]; // Array to Store Position
    double vel[num_planets][3]; // Array to Store Velocity
    double acc[num_planets][3]; // Array to Store Acceleration

    // User Input - Mass, Initial Position, and Velocity
    for (i = 0; i < num_planets; i++) {
        printf("Planet %d - Mass, Initial Position (x, y, z), Initial Velocity (vx, vy, vz): \n", i+1);
        scanf("%lf %lf %lf %lf %lf %lf %lf", &mass[i], &pos[i][0], &pos[i][1], &pos[i][2], &vel[i][0], &vel[i][1], &vel[i][2]);
    }

    // Simulation Loop
    for (k = 0; k < sim_time/dt; k++) {
        // Calculate Acceleration for Each Planet
        for (i = 0; i < num_planets; i++) {
            acc[i][0] = 0;
            acc[i][1] = 0;
            acc[i][2] = 0;
            for (j = 0; j < num_planets; j++) {
                if (i != j) {
                    double distance = sqrt(pow(pos[j][0]-pos[i][0], 2) + pow(pos[j][1]-pos[i][1], 2) + pow(pos[j][2]-pos[i][2], 2));
                    double force = G*mass[i]*mass[j]/pow(distance, 2);
                    acc[i][0] += force*(pos[j][0]-pos[i][0])/distance/mass[i];
                    acc[i][1] += force*(pos[j][1]-pos[i][1])/distance/mass[i];
                    acc[i][2] += force*(pos[j][2]-pos[i][2])/distance/mass[i];
                }
            }
        }

        // Update Position and Velocity for Each Planet
        for (i = 0; i < num_planets; i++) {
            pos[i][0] += vel[i][0]*dt + 0.5*acc[i][0]*pow(dt, 2);
            pos[i][1] += vel[i][1]*dt + 0.5*acc[i][1]*pow(dt, 2);
            pos[i][2] += vel[i][2]*dt + 0.5*acc[i][2]*pow(dt, 2);
            vel[i][0] += acc[i][0]*dt;
            vel[i][1] += acc[i][1]*dt;
            vel[i][2] += acc[i][2]*dt;
        }

        // Print Current Position and Velocity
        for (i = 0; i < num_planets; i++) {
            printf("Planet %d - Position (x, y, z): (%lf, %lf, %lf) | Velocity (vx, vy, vz): (%lf, %lf, %lf)\n", i+1, pos[i][0], pos[i][1], pos[i][2], vel[i][0], vel[i][1], vel[i][2]);
        }
        printf("\n");
    }
    return 0;
}