//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <math.h>

#define MAX_PLANETS 10

struct planet {
    char name[20];
    float mass;
    float position[3];
    float velocity[3];
} planets[MAX_PLANETS];

const float G = 6.674e-11;

void initialize_planets();
void update_positions(float time_step);
void update_velocities(float time_step);
float distance(float* p1, float* p2);

int main() {
    initialize_planets();
    float time_step = 1.0; // in seconds
    int num_time_steps = 1000;
    for (int i = 0; i < num_time_steps; i++) {
        update_positions(time_step);
        update_velocities(time_step);
    }
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%s's position: (%f, %f, %f)\n", planets[i].name, 
               planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    }
    return 0;
}

void initialize_planets() {
    struct planet sun = {"Sun", 1.989e30, {0, 0, 0}, {0, 0, 0}};
    planets[0] = sun;
    struct planet mercury = {"Mercury", 3.301e23, {5.791e10, 0, 0}, {0, 4.74e4, 0}};
    planets[1] = mercury;
    struct planet venus = {"Venus", 4.867e24, {1.082e11, 0, 0}, {0, 3.5e4, 0}};
    planets[2] = venus;
    struct planet earth = {"Earth", 5.9736e24, {1.496e11, 0, 0}, {0, 2.9783e4, 0}};
    planets[3] = earth;
    struct planet mars = {"Mars", 6.4185e23, {2.279e11, 0, 0}, {0, 2.41e4, 0}};
    planets[4] = mars;
    struct planet jupiter = {"Jupiter", 1.898e27, {7.786e11, 0, 0}, {0, 1.307e4, 0}};
    planets[5] = jupiter;
    struct planet saturn = {"Saturn", 5.683e26, {1.433e12, 0, 0}, {0, 9.69e3, 0}};
    planets[6] = saturn;
    struct planet uranus = {"Uranus", 8.681e25, {2.877e12, 0, 0}, {0, 6.8e3, 0}};
    planets[7] = uranus;
    struct planet neptune = {"Neptune", 1.024e26, {4.503e12, 0, 0}, {0, 5.43e3, 0}};
    planets[8] = neptune;
    struct planet pluto = {"Pluto", 1.309e22, {5.906e12, 0, 0}, {0, 4.67e3, 0}};
    planets[9] = pluto;
}

void update_positions(float time_step) {
    for (int i = 0; i < MAX_PLANETS; i++) {
        float dv[3] = {0, 0, 0};
        for (int j = 0; j < MAX_PLANETS; j++) {
            if (i == j) continue;
            float r = distance(planets[i].position, planets[j].position);
            float force = G * planets[i].mass * planets[j].mass / (r * r);
            float unit_vector[3] = {
                (planets[j].position[0] - planets[i].position[0]) / r,
                (planets[j].position[1] - planets[i].position[1]) / r,
                (planets[j].position[2] - planets[i].position[2]) / r
            };
            dv[0] += force * unit_vector[0] / planets[i].mass * time_step;
            dv[1] += force * unit_vector[1] / planets[i].mass * time_step;
            dv[2] += force * unit_vector[2] / planets[i].mass * time_step;
        }
        planets[i].velocity[0] += dv[0];
        planets[i].velocity[1] += dv[1];
        planets[i].velocity[2] += dv[2];
        planets[i].position[0] += planets[i].velocity[0] * time_step;
        planets[i].position[1] += planets[i].velocity[1] * time_step;
        planets[i].position[2] += planets[i].velocity[2] * time_step;
    }
}

void update_velocities(float time_step) {
    // velocities are already updated in update_positions()
}

float distance(float* p1, float* p2) {
    float dx = p2[0] - p1[0];
    float dy = p2[1] - p1[1];
    float dz = p2[2] - p1[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}