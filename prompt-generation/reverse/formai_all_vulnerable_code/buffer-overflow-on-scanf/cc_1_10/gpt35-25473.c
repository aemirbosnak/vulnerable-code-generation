//FormAI DATASET v1.0 Category: Physics simulation ; Style: accurate
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // Universal Gravitational constant 

struct planet {
    char name[10];
    double mass;
    double pos_x, pos_y;
    double vel_x, vel_y;
    double acc_x, acc_y;
};

int main() {
    int n;
    printf("Enter the number of planets: ");
    scanf("%d", &n);

    struct planet planets[n];

    // User input for planet data
    for(int i=0; i<n; i++) {
        printf("Enter the name of planet %d: ", i+1);
        scanf("%s", planets[i].name);
        printf("Enter the mass of planet %d (in kg): ", i+1);
        scanf("%lf", &planets[i].mass);
        printf("Enter the initial x-position of planet %d (in m): ", i+1);
        scanf("%lf", &planets[i].pos_x);
        printf("Enter the initial y-position of planet %d (in m): ", i+1);
        scanf("%lf", &planets[i].pos_y);
        printf("Enter the initial x-velocity of planet %d (in m/s): ", i+1);
        scanf("%lf", &planets[i].vel_x);
        printf("Enter the initial y-velocity of planet %d (in m/s): ", i+1);
        scanf("%lf", &planets[i].vel_y);
    }

    double time_step;
    printf("Enter the time step (in s): ");
    scanf("%lf", &time_step);

    int num_steps;
    printf("Enter the number of time steps: ");
    scanf("%d", &num_steps);

    // Simulation loop
    for(int step=0; step<num_steps; step++) {
        for(int i=0; i<n; i++) {
            // Reset acceleration
            planets[i].acc_x = 0;
            planets[i].acc_y = 0;

            for(int j=0; j<n; j++) {
                if(i != j) { // Don't calculate force on itself
                    double dx = planets[j].pos_x - planets[i].pos_x;
                    double dy = planets[j].pos_y - planets[i].pos_y;
                    double r = sqrt(dx*dx + dy*dy); // Distance between planets
                    double f = G * planets[i].mass * planets[j].mass / (r*r); // Magnitude of gravitational force
                    double theta = atan2(dy, dx); // Angle between planets

                    // Update acceleration
                    planets[i].acc_x += f * cos(theta) / planets[i].mass;
                    planets[i].acc_y += f * sin(theta) / planets[i].mass;
                }
            }

            // Update velocity and position
            planets[i].vel_x += planets[i].acc_x * time_step;
            planets[i].vel_y += planets[i].acc_y * time_step;
            planets[i].pos_x += planets[i].vel_x * time_step;
            planets[i].pos_y += planets[i].vel_y * time_step;
        }
    }

    // Output final positions
    for(int i=0; i<n; i++) {
        printf("Final position of planet %s: (%.2lf, %.2lf)\n", planets[i].name, planets[i].pos_x, planets[i].pos_y);
    }

    return 0;
}