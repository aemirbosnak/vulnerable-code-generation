//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define G 6.67e-11

typedef struct planet {
    double x;           // x position
    double y;           // y position
    double z;           // z position
    double vx;          // x velocity
    double vy;          // y velocity
    double vz;          // z velocity
    double mass;        // mass
} planet;

planet calculate_acceleration(planet this_planet, planet other_planet) {
    double distance = sqrt(pow(this_planet.x - other_planet.x, 2) + pow(this_planet.y - other_planet.y, 2) + pow(this_planet.z - other_planet.z, 2));
    double force = G * this_planet.mass * other_planet.mass / pow(distance, 2);
    double ax = force * (other_planet.x - this_planet.x) / distance / this_planet.mass;
    double ay = force * (other_planet.y - this_planet.y) / distance / this_planet.mass;
    double az = force * (other_planet.z - this_planet.z) / distance / this_planet.mass;
    planet acceleration = {ax, ay, az};
    return acceleration;
}

void update_position(planet* this_planet, double time_step) {
    this_planet->x += this_planet->vx * time_step;
    this_planet->y += this_planet->vy * time_step;
    this_planet->z += this_planet->vz * time_step;
}

void update_velocity(planet* this_planet, planet acceleration, double time_step) {
    this_planet->vx += acceleration.x * time_step;
    this_planet->vy += acceleration.y * time_step;
    this_planet->vz += acceleration.z * time_step;
}

int main() {
    planet sun = {0, 0, 0, 0, 0, 0, 1.989e30};
    planet earth = {1.5e11, 0, 0, 0, 3e4, 0, 5.972e24};
    double time_step = 3600 * 24;     // one day
    int num_steps = 365;              // one year

    // simulate planet orbit for one year
    for (int i = 0; i < num_steps; i++) {
        planet earth_acceleration = calculate_acceleration(earth, sun);
        update_velocity(&earth, earth_acceleration, time_step);
        update_position(&earth, time_step);

        printf("Day %d: Earth position = (%.5e, %.5e, %.5e) | Earth velocity = (%.5e, %.5e, %.5e)\n", 
                i+1, earth.x, earth.y, earth.z, earth.vx, earth.vy, earth.vz);
    }

    return 0;
}