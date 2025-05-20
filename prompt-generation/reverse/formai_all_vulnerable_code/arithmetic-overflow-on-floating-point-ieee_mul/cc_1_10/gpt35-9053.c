//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11        // gravitational constant (m^3/kg*s^2)

typedef struct {
    double x;
    double y;
    double z;
} vector3d;

typedef struct {
    vector3d position;
    vector3d velocity;
    double mass;
} planet;

vector3d calc_gravity(planet *p1, planet *p2) {
    vector3d distance;
    double magnitude;
    vector3d force;

    distance.x = p2->position.x - p1->position.x;
    distance.y = p2->position.y - p1->position.y;
    distance.z = p2->position.z - p1->position.z;

    magnitude = G * p1->mass * p2->mass / pow(sqrt(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z), 2);

    force.x = magnitude * distance.x / sqrt(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);
    force.y = magnitude * distance.y / sqrt(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);
    force.z = magnitude * distance.z / sqrt(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);

    return force;
}

vector3d calc_total_force(planet *planets, int num_planets, int current_planet) {
    int i;
    vector3d total_force = {0, 0, 0};
    vector3d force;
    
    for (i = 0; i < num_planets; i++) {
        if (i != current_planet) {
            force = calc_gravity(&planets[current_planet], &planets[i]);
            total_force.x += force.x;
            total_force.y += force.y;
            total_force.z += force.z;
        }
    }

    return total_force;
}

void update_planet(planet *p, vector3d force, double time_delta) {
    vector3d acceleration;

    acceleration.x = force.x / p->mass;
    acceleration.y = force.y / p->mass;
    acceleration.z = force.z / p->mass;

    p->velocity.x += acceleration.x * time_delta;
    p->velocity.y += acceleration.y * time_delta;
    p->velocity.z += acceleration.z * time_delta;

    p->position.x += p->velocity.x * time_delta;
    p->position.y += p->velocity.y * time_delta;
    p->position.z += p->velocity.z * time_delta;
}

int main() {
    int num_planets = 3;
    double time_delta = 86400;    // 1 day in seconds
    planet planets[3];
    vector3d total_force;
    int i, j;

    // initialize planets
    planets[0].mass = 5.97e24;    // mass of Earth (kg)
    planets[0].position.x = 0;
    planets[0].position.y = 0;
    planets[0].position.z = 0;
    planets[0].velocity.x = 0;
    planets[0].velocity.y = 0;
    planets[0].velocity.z = 0;

    planets[1].mass = 6.39e23;    // mass of Mars (kg)
    planets[1].position.x = 2.279e11;    // distance from Earth to Mars (m)
    planets[1].position.y = 0;
    planets[1].position.z = 0;
    planets[1].velocity.x = 0;
    planets[1].velocity.y = 24051;    // average speed of Mars relative to the Sun (m/s)
    planets[1].velocity.z = 0;

    planets[2].mass = 1.99e30;    // mass of Sun (kg)
    planets[2].position.x = 0;
    planets[2].position.y = 0;
    planets[2].position.z = 0;
    planets[2].velocity.x = 0;
    planets[2].velocity.y = 0;
    planets[2].velocity.z = 0;

    // simulate planetary motion
    for (i = 0; i < num_planets; i++) {
        total_force = calc_total_force(planets, num_planets, i);
        update_planet(&planets[i], total_force, time_delta);
    }

    // print final positions of planets
    for (i = 0; i < num_planets; i++) {
        printf("Planet %d position: (%f, %f, %f)\n", i+1, planets[i].position.x, planets[i].position.y, planets[i].position.z);
    }

    return 0;
}