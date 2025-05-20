//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} vector2d;

typedef struct {
    vector2d position;
    vector2d velocity;
    double mass;
} body;

vector2d make_vector(double x, double y) {
    vector2d v;
    v.x = x;
    v.y = y;
    return v;
}

body make_body(vector2d position, vector2d velocity, double mass) {
    body b;
    b.position = position;
    b.velocity = velocity;
    b.mass = mass;
    return b;
}

double distance(vector2d v1, vector2d v2) {
    double x = v2.x - v1.x;
    double y = v2.y - v1.y;
    return sqrt(x*x + y*y);
}

vector2d subtract_vectors(vector2d v1, vector2d v2) {
    vector2d v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    return v;
}

vector2d add_vectors(vector2d v1, vector2d v2) {
    vector2d v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}

vector2d multiply_vector(vector2d v, double scalar) {
    vector2d result = v;
    result.x *= scalar;
    result.y *= scalar;
    return result;
}

vector2d gravity(body b1, body b2, double G) {
    double d = distance(b1.position, b2.position);
    double scalar = G * b1.mass * b2.mass / (d * d);
    vector2d direction = subtract_vectors(b2.position, b1.position);
    return multiply_vector(direction, scalar / d);
}

void update_velocity(body* b, vector2d force, double dt) {
    vector2d acceleration = multiply_vector(force, 1 / b->mass);
    b->velocity = add_vectors(b->velocity, multiply_vector(acceleration, dt));
}

void update_position(body* b, double dt) {
    b->position = add_vectors(b->position, multiply_vector(b->velocity, dt));
}

void simulate(body* bodies, int num_bodies, double G, double dt, int num_steps) {
    int i, j, step;
    vector2d force;
    
    for (step = 0; step < num_steps; step++) {
        for (i = 0; i < num_bodies; i++) {
            force.x = force.y = 0;
            for (j = 0; j < num_bodies; j++) {
                if (i != j) {
                    force = add_vectors(force, gravity(bodies[i], bodies[j], G));
                }
            }
            update_velocity(&bodies[i], force, dt);
        }
        for (i = 0; i < num_bodies; i++) {
            update_position(&bodies[i], dt);
        }
    }
}

int main() {
    const int num_bodies = 3;
    body bodies[num_bodies];
    double G = 6.674e-11;
    double dt = 60 * 60 * 24;
    int num_steps = 365;
    
    // Body 1: Earth
    vector2d pos1 = make_vector(0, 0);
    vector2d vel1 = make_vector(0, 0);
    double mass1 = 5.97e24;
    bodies[0] = make_body(pos1, vel1, mass1);
    
    // Body 2: Moon
    vector2d pos2 = make_vector(3.84e8, 0);
    vector2d vel2 = make_vector(0, 1022);
    double mass2 = 7.35e22;
    bodies[1] = make_body(pos2, vel2, mass2);
    
    // Body 3: Sun
    vector2d pos3 = make_vector(0, 0);
    vector2d vel3 = make_vector(0, 0);
    double mass3 = 1.989e30;
    bodies[2] = make_body(pos3, vel3, mass3);
    
    simulate(bodies, num_bodies, G, dt, num_steps);
    
    printf("Final position of Earth: (%.2f, %.2f)\n", bodies[0].position.x, bodies[0].position.y);
    printf("Final position of Moon: (%.2f, %.2f)\n", bodies[1].position.x, bodies[1].position.y);
    
    return 0;
}