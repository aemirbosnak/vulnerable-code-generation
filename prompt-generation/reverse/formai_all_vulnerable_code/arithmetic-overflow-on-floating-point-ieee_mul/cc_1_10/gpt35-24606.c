//FormAI DATASET v1.0 Category: Physics simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G_CONST 6.674e-11  /* Universal gravitational constant G */

/* Define the structure of a celestial body */
typedef struct {
    double mass;
    double position[3];  /* x, y, z position */
    double velocity[3];  /* x, y, z velocity */
} celestial_body;

/* Implement the function to calculate the gravitational force between two celestial bodies */
void calculate_force(celestial_body *body1, celestial_body *body2, double *force) {
    double dist_sq = 0.0;  /* Distance between the two bodies, squared */
    double dist = 0.0;  /* Distance between the two bodies */
    double grav_force = 0.0;  /* Gravitational force between the two bodies */ 

    for (int i = 0; i < 3; i++) {
        dist_sq += pow((body1->position[i] - body2->position[i]), 2);  /* Calculate distance squared */
    }
    dist = sqrt(dist_sq);
    grav_force = (G_CONST * body1->mass * body2->mass) / pow(dist, 2);  /* Calculate gravitational force */

    /* Calculate the x, y, z components of the gravitational force exerted on body1 by body2 */
    for (int i = 0; i < 3; i++) {
        force[i] = grav_force * (body2->position[i] - body1->position[i]) / dist;
    }
}

/* Implement the function to update the velocity and position of a celestial body */
void update_body(celestial_body *body, double *force, double time_step) {
    double acceleration[3];  /* Acceleration of the body */

    /* Calculate the x, y, z components of the acceleration of the body */
    for (int i = 0; i < 3; i++) {
        acceleration[i] = force[i] / body->mass;
        body->velocity[i] += acceleration[i] * time_step;  /* Update velocity */
        body->position[i] += body->velocity[i] * time_step;  /* Update position */
    }
}

int main() {
    srand(time(NULL));  /* Seed the random number generator */

    /* Initialize an array of celestial bodies */
    const int num_bodies = 3;
    celestial_body bodies[num_bodies];
    bodies[0].mass = 5.97e24;  /* Earth */
    bodies[0].position[0] = 0.0;
    bodies[0].position[1] = 0.0;
    bodies[0].position[2] = 0.0;
    bodies[0].velocity[0] = 0.0;
    bodies[0].velocity[1] = 0.0;
    bodies[0].velocity[2] = 0.0;
    bodies[1].mass = 1.99e30;  /* Sun */
    bodies[1].position[0] = 1.496e11;
    bodies[1].position[1] = 0.0;
    bodies[1].position[2] = 0.0;
    bodies[1].velocity[0] = 0.0;
    bodies[1].velocity[1] = 3.029e4;
    bodies[1].velocity[2] = 0.0;
    bodies[2].mass = 7.35e22;  /* Moon */
    bodies[2].position[0] = 3.844e8;
    bodies[2].position[1] = 0.0;
    bodies[2].position[2] = 0.0;
    bodies[2].velocity[0] = 0.0;
    bodies[2].velocity[1] = 1.022e3 + (double)rand() / RAND_MAX * 500;
    bodies[2].velocity[2] = 0.0;

    /* Set the time step and simulation duration */
    const double time_step = 3600.0;
    const double sim_duration = 365.25 * 24.0 * 3600.0;

    /* Simulate the motion of the celestial bodies */
    const int num_time_steps = (int)(sim_duration / time_step);
    for (int i = 0; i < num_time_steps; i++) {
        /* Calculate the gravitational forces between all pairs of celestial bodies */
        double force[num_bodies][3];  /* Array to store the forces on each body */
        for (int j = 0; j < num_bodies; j++) {
            for (int k = j+1; k < num_bodies; k++) {
                double f[3] = {0};
                calculate_force(&bodies[j], &bodies[k], f);
                force[j][0] += f[0];
                force[j][1] += f[1];
                force[j][2] += f[2];
                force[k][0] -= f[0];
                force[k][1] -= f[1];
                force[k][2] -= f[2];
            }
        }

        /* Update the position and velocity of each celestial body based on the gravitational forces */
        for (int j = 0; j < num_bodies; j++) {
            update_body(&bodies[j], force[j], time_step);
        }
    }

    /* Print the final positions and velocities of the celestial bodies */
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d:\n", i);
        printf("  Mass: %g kg\n", bodies[i].mass);
        printf("  Position: (%g, %g, %g) m\n", bodies[i].position[0], bodies[i].position[1], bodies[i].position[2]);
        printf("  Velocity: (%g, %g, %g) m/s\n", bodies[i].velocity[0], bodies[i].velocity[1], bodies[i].velocity[2]);
    }

    return 0;
}