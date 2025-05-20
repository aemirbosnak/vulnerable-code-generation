//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define DELTA_T 0.01
#define G 6.67430e-11

struct Vector {
    double x, y, z;
};

struct Body {
    char name[30];
    struct Vector position;
    struct Vector velocity;
    double mass;
};

struct Force {
    double x, y, z;
};

void print_body(struct Body *body) {
    printf("%s: (%.2f, %.2f, %.2f)\n", body->name, body->position.x, body->position.y, body->position.z);
}

struct Force calculate_gravity(struct Body *body1, struct Body *body2) {
    double r = sqrt(pow((body2->position.x - body1->position.x), 2) + pow((body2->position.y - body1->position.y), 2) + pow((body2->position.z - body1->position.z), 2));
    double f = (G * body1->mass * body2->mass) / pow(r, 2);

    struct Force force;
    force.x = f * (body2->position.x - body1->position.x) / r; 
    force.y = f * (body2->position.y - body1->position.y) / r; 
    force.z = f * (body2->position.z - body1->position.z) / r; 

    return force;
}

void calculate_forces(struct Body bodies[], struct Force forces[], int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        forces[i].x = 0;
        forces[i].y = 0;
        forces[i].z = 0;

        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }

            struct Force force = calculate_gravity(&bodies[i], &bodies[j]);
            forces[i].x += force.x;
            forces[i].y += force.y;
            forces[i].z += force.z;
        }
    }
}

void update_bodies(struct Body bodies[], struct Force forces[], int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position.x += DELTA_T * bodies[i].velocity.x;
        bodies[i].position.y += DELTA_T * bodies[i].velocity.y;
        bodies[i].position.z += DELTA_T * bodies[i].velocity.z;

        bodies[i].velocity.x += DELTA_T * forces[i].x / bodies[i].mass;
        bodies[i].velocity.y += DELTA_T * forces[i].y / bodies[i].mass;
        bodies[i].velocity.z += DELTA_T * forces[i].z / bodies[i].mass;
    }
}

int main() {
    struct Body sun = {"Sun", {0, 0, 0}, {0, 0, 0}, 1.989e30};
    struct Body earth = {"Earth", {147e9, 0, 0}, {0, 30.29e3, 0}, 5.97e24};
    struct Body moon = {"Moon", {147e9 + 384.4e6, 0, 0}, {0, 30.29e3 + 1.02e3, 0}, 7.342e22};

    struct Body bodies[] = {sun, earth, moon};

    int num_bodies = sizeof(bodies) / sizeof(struct Body);

    struct Force forces[num_bodies];

    for (int i = 0; i < 365 * 24 * 60 * 60; i++) {
        calculate_forces(bodies, forces, num_bodies);
        update_bodies(bodies, forces, num_bodies);

        if (i % 86400 == 0) {
            printf("Day %d:\n", i / 86400);
            for (int j = 0; j < num_bodies; j++) {
                print_body(&bodies[j]);
            }
        }
    }

    return 0;
}