//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: portable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    // Define the parameters for the simulation
    double radius = 5.0;
    double m1 = 1.0;
    double m2 = 1.0;
    double G = 6.67430 * pow(10,-11);
    double dt = 0.001;
    int nsteps = 1000000;

    // Initialize the positions and velocities of the planets
    double x1, y1, vx1, vy1;
    double x2, y2, vx2, vy2;
    x1 = y1 = 0;
    vx1 = vy1 = 0;
    x2 = y2 = 0;
    vx2 = vy2 = 0;

    // Run the simulation
    for (int i = 0; i < nsteps; i++) {
        // Update the positions and velocities of the planets
        x1 += vx1 * dt;
        y1 += vy1 * dt;
        vx1 += (G * m2 / (pow(x1 - x2, 2) + pow(y1 - y2, 2))) * dt;
        vy1 += (G * m2 / (pow(x1 - x2, 2) + pow(y1 - y2, 2))) * dt;
        x2 += vx2 * dt;
        y2 += vy2 * dt;
        vx2 += (G * m1 / (pow(x2 - x1, 2) + pow(y2 - y1, 2))) * dt;
        vy2 += (G * m1 / (pow(x2 - x1, 2) + pow(y2 - y1, 2))) * dt;

        // Print the positions and velocities of the planets
        printf("x1: %.2f, y1: %.2f, vx1: %.2f, vy1: %.2f\n", x1, y1, vx1, vy1);
        printf("x2: %.2f, y2: %.2f, vx2: %.2f, vy2: %.2f\n", x2, y2, vx2, vy2);

        // Check for convergence
        if (fabs(x1 - x2) < 0.001 && fabs(y1 - y2) < 0.001 && fabs(vx1) < 0.001 && fabs(vy1) < 0.001 && fabs(vx2) < 0.001 && fabs(vy2) < 0.001) {
            printf("Simulation converged after %d steps.\n", i);
            break;
        }

        // Adjust the time step if the simulation is not converging
        if (fabs(x1 - x2) > 0.1 || fabs(y1 - y2) > 0.1 || fabs(vx1) > 0.1 || fabs(vy1) > 0.1 || fabs(vx2) > 0.1 || fabs(vy2) > 0.1) {
            dt *= 0.5;
            printf("Adjusting time step to %.2f\n", dt);
        }
    }

    return 0;
}