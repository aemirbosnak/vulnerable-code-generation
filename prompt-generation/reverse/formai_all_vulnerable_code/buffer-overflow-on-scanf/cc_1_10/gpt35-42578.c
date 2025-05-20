//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include <stdio.h>
#include <math.h>

int main() {

    int num_planets;

    printf("Welcome to the planet gravity simulation program!\n");
    printf("How many planets would you like to simulate? ");
    scanf("%d", &num_planets);
    printf("Excellent, we will simulate %d planets.\n\n", num_planets);

    double positions[num_planets][2]; // stores x and y positions
    double velocities[num_planets][2]; // stores x and y velocities
    double masses[num_planets];
    const double GRAVITATIONAL_CONSTANT = 6.67e-11;

    // Get planet positions and masses from user
    for (int i = 0; i < num_planets; i++) {
        double x, y, mass;
        printf("Enter the x and y coordinates for planet #%d: ", i+1);
        scanf("%lf %lf", &x, &y);
        positions[i][0] = x;
        positions[i][1] = y;
        printf("Enter the mass for planet #%d (in kg): ", i+1);
        scanf("%lf", &mass);
        masses[i] = mass;
        printf("Planet #%d has been added to the simulation!\n\n", i+1);
    }

    // Get initial velocities for each planet
    for (int i = 0; i < num_planets; i++) {
        double vx, vy;
        printf("Enter the initial x and y velocities for planet #%d (in m/s): ", i+1);
        scanf("%lf %lf", &vx, &vy);
        velocities[i][0] = vx;
        velocities[i][1] = vy;
        printf("Planet #%d has been initialized with the given velocity!\n\n", i+1);
    }

    // Simulate the planets' motion over time
    const int SIMULATION_DURATION = 10000; // in seconds
    const int TIME_INCREMENT = 1; // in seconds
    const int STEPS = SIMULATION_DURATION / TIME_INCREMENT;

    for (int step = 0; step < STEPS; step++) {
        for (int i = 0; i < num_planets; i++) {
            double fx = 0, fy = 0; 
            for (int j = 0; j < num_planets; j++) {
                if (j == i) continue;
                double dx = positions[j][0] - positions[i][0];
                double dy = positions[j][1] - positions[i][1];
                double distance = sqrt(dx*dx + dy*dy);
                double force = GRAVITATIONAL_CONSTANT * masses[j] * masses[i] / (distance*distance);
                double theta = atan2(dy, dx); // angle between two planets
                fx += force * cos(theta); // x component of force
                fy += force * sin(theta); // y component of force
            }
            double ax = fx / masses[i]; // x component of acceleration
            double ay = fy / masses[i]; // y component of acceleration
            velocities[i][0] += ax * TIME_INCREMENT; // update x velocity
            velocities[i][1] += ay * TIME_INCREMENT; // update y velocity
            positions[i][0] += velocities[i][0] * TIME_INCREMENT; // update x position
            positions[i][1] += velocities[i][1] * TIME_INCREMENT; // update y position
        }
    }

    // Print final positions of planets
    printf("Final positions of planets after %d seconds:\n", SIMULATION_DURATION);
    for (int i = 0; i < num_planets; i++) {
        printf("Planet #%d: (%.2lf, %.2lf)\n", i+1, positions[i][0], positions[i][1]);
    }
    printf("\n");

    return 0;
}