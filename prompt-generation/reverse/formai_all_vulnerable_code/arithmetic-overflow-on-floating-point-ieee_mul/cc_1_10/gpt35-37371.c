//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: recursive
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11	// gravitational constant 

struct Vector {
    double x, y, z;
};

struct Planet {
    char name[20];
    double mass;
    double radius;
    struct Vector position;
    struct Vector velocity;
    struct Vector acceleration;
};

typedef struct Planet Planet;
typedef struct Vector Vector;

// returns the distance between two planets
double distance(Planet* a, Planet* b) {
    double dx = a->position.x - b->position.x;
    double dy = a->position.y - b->position.y;
    double dz = a->position.z - b->position.z;
    return sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
}

// calculates the gravitational force between two planets
Vector gravitational_force(Planet* a, Planet* b) {
    Vector force;
    double r = distance(a, b);
    double f = G * a->mass * b->mass / pow(r, 2);
    force.x = f * (b->position.x - a->position.x) / r;
    force.y = f * (b->position.y - a->position.y) / r;
    force.z = f * (b->position.z - a->position.z) / r;
    return force;
}

// calculates the acceleration of a planet due to gravitational forces from all other planets
Vector calculate_acceleration(Planet* p, Planet* planets, int n) {
    Vector acceleration = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        if (p != &planets[i]) {
            Vector force = gravitational_force(p, &planets[i]);
            acceleration.x += force.x / p->mass;
            acceleration.y += force.y / p->mass;
            acceleration.z += force.z / p->mass;
        }
    }
    return acceleration;
}

// updates the position and velocity of a planet based on its acceleration
void update_position_and_velocity(Planet* p, double dt) {
    p->position.x += p->velocity.x * dt + 0.5 * p->acceleration.x * pow(dt, 2);
    p->position.y += p->velocity.y * dt + 0.5 * p->acceleration.y * pow(dt, 2);
    p->position.z += p->velocity.z * dt + 0.5 * p->acceleration.z * pow(dt, 2);
    
    p->velocity.x += p->acceleration.x * dt;
    p->velocity.y += p->acceleration.y * dt;
    p->velocity.z += p->acceleration.z * dt;
}

// displays the information of a planet
void print_planet(Planet* p) {
    printf("%-10s%-15.3e%-15.3e(%10.3e,%10.3e,%10.3e)(%10.3e,%10.3e,%10.3e)\n",
           p->name, p->mass, p->radius, p->position.x, p->position.y, p->position.z,
           p->velocity.x, p->velocity.y, p->velocity.z);
}

// simulates the solar system for a given time and time step
void simulate(Planet* planets, int n, double t, double dt) {
    printf("%-10s%-15s%-30s%-30s\n", "Name", "Mass", "Position", "Velocity");
    for (double time = 0; time <= t; time += dt) {
        for (int i = 0; i < n; i++) {
            Planet* p = &planets[i];
            p->acceleration = calculate_acceleration(p, planets, n);
            update_position_and_velocity(p, dt);
        }
        if ((int)time % 86400 == 0) {	// print every day
            for (int i = 0; i < n; i++) {
                print_planet(&planets[i]);
            }
            printf("=============================================================\n");
        }
    }
}

int main() {
    Planet planets[] = {
        {"Sun", 1.989e30, 696340000, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {"Mercury", 3.285e23, 2439700, {-5.791e10, 0, 0}, {0, 0, 47870}, {0, 0, 0}},
        {"Venus", 4.867e24, 6051800, {0, 1.078e11, 0}, {-35020, 0, 0}, {0, 0, 0}},
        {"Earth", 5.972e24, 6371000, {1.496e11, 0, 0}, {0, 29784, 0}, {0, 0, 0}},
        {"Mars", 6.39e23, 3389500, {0, 0, 2.279e11}, {24007, 0, 0}, {0, 0, 0}},
        {"Jupiter", 1.898e27, 69911000, {0, 0, -7.785e11}, {13069, 0, 0}, {0, 0, 0}},
        {"Saturn", 5.683e26, 58232000, {0, 0, 1.427e12}, {9026, 0, 0}, {0, 0, 0}},
        {"Uranus", 8.681e25, 25362000, {0, 0, -2.871e12}, {6315, 0, 0}, {0, 0, 0}},
        {"Neptune", 1.024e26, 24622000, {0, 0, 4.48e12}, {5175, 0, 0}, {0, 0, 0}}
    };
    int n = sizeof(planets) / sizeof(Planet);
    double t = 365 * 24 * 60 * 60;	// one year
    double dt = 3600;	// one hour
    simulate(planets, n, t, dt);
    return 0;
}