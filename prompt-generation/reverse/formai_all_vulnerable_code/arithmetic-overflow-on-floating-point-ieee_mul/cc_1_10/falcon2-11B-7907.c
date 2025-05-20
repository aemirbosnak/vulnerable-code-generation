//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <math.h>

int main() {
    // Solar System Parameters
    const float G = 6.67408f * pow(10, -11); // gravitational constant
    const float AU = 1.496e11; // astronomical unit (average distance from Earth to Sun)
    const float earth_mass = 5.972e24; // Earth mass in kg
    const float earth_radius = 6371; // Earth radius in km
    const float sun_mass = 1.989e30; // Sun mass in kg
    const float sun_radius = 695.5e3; // Sun radius in km
    const float moon_mass = 7.348e22; // Moon mass in kg
    const float moon_radius = 1737.4; // Moon radius in km
    const float earth_velocity = 29.78; // Earth orbital velocity in km/s

    // Initial conditions
    float earth_x, earth_y, earth_z, earth_vx, earth_vy, earth_vz;
    float moon_x, moon_y, moon_z, moon_vx, moon_vy, moon_vz;

    // Set initial conditions
    earth_x = 0;
    earth_y = 0;
    earth_z = 0;
    earth_vx = 0;
    earth_vy = 0;
    earth_vz = 0;

    moon_x = 0;
    moon_y = 0;
    moon_z = 0;
    moon_vx = 0;
    moon_vy = 0;
    moon_vz = 0;

    // Simulation loop
    float dt = 0.01; // simulation time step
    for (int i = 0; i < 1000000; i++) {
        // Update positions
        earth_x += earth_vx * dt;
        earth_y += earth_vy * dt;
        earth_z += earth_vz * dt;
        moon_x += moon_vx * dt;
        moon_y += moon_vy * dt;
        moon_z += moon_vz * dt;

        // Update velocities
        earth_vx += earth_x * dt / (AU * AU);
        earth_vy += earth_y * dt / (AU * AU);
        earth_vz += earth_z * dt / (AU * AU);
        moon_vx += moon_x * dt / (AU * AU);
        moon_vy += moon_y * dt / (AU * AU);
        moon_vz += moon_z * dt / (AU * AU);

        // Calculate gravitational forces
        float earth_force = -G * earth_mass * moon_mass / (pow(earth_radius + moon_radius, 3) * pow(AU, 2));
        float moon_force = earth_force;

        // Update velocities due to gravity
        earth_vx += earth_force * moon_x / earth_mass;
        earth_vy += earth_force * moon_y / earth_mass;
        earth_vz += earth_force * moon_z / earth_mass;
        moon_vx += earth_force * earth_x / moon_mass;
        moon_vy += earth_force * earth_y / moon_mass;
        moon_vz += earth_force * earth_z / moon_mass;
    }

    // Output results
    printf("Earth position: (%f, %f, %f)\n", earth_x, earth_y, earth_z);
    printf("Moon position: (%f, %f, %f)\n", moon_x, moon_y, moon_z);

    return 0;
}