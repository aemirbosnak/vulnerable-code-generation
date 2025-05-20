//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.674e-11  //Gravitational constant
#define TIMESTEP 0.1          //Simulation time step

typedef struct Vector {
    double x, y;
} Vector;

typedef struct Body {
    Vector position, velocity, acceleration;
    double mass;
} Body;

//Function to calculate the force acting on a body from all other bodies
Vector calculate_net_force(Body body, Body* bodies, int num_bodies) {
    Vector net_force = { 0, 0 };
    for (int i = 0; i < num_bodies; i++) {
        if (&body != &bodies[i]) {
            double distance = sqrt(pow(body.position.x - bodies[i].position.x, 2) + pow(body.position.y - bodies[i].position.y, 2));
            double force = GRAV_CONST * body.mass * bodies[i].mass / pow(distance, 2);
            Vector direction = { (bodies[i].position.x - body.position.x) / distance, (bodies[i].position.y - body.position.y) / distance };
            net_force.x += force * direction.x;
            net_force.y += force * direction.y;
        }
    }
    return net_force;
}

//Function to perform the simulation of all bodies
void simulate(Body* bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].acceleration = calculate_net_force(bodies[i], bodies, num_bodies);
        bodies[i].velocity.x += bodies[i].acceleration.x * TIMESTEP;
        bodies[i].velocity.y += bodies[i].acceleration.y * TIMESTEP;
        bodies[i].position.x += bodies[i].velocity.x * TIMESTEP;
        bodies[i].position.y += bodies[i].velocity.y * TIMESTEP;
    }
}

int main(void) {
    Body bodies[3] = { { {0, 0}, {0, 0}, {0, 0}, 1000 }, { {50, 0}, {0, 50}, {0, 0}, 100 }, { {0, 50}, {-50, 0}, {0, 0}, 10 } };

    for (int i = 0; i < 100; i++) {
        simulate(bodies, 3);
        printf("Body 1: x=%lf, y=%lf\n", bodies[0].position.x, bodies[0].position.y);
        printf("Body 2: x=%lf, y=%lf\n", bodies[1].position.x, bodies[1].position.y);
        printf("Body 3: x=%lf, y=%lf\n\n", bodies[2].position.x, bodies[2].position.y);
    }

    return EXIT_SUCCESS;
}