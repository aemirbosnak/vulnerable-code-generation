//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: imaginative
#include <stdio.h>
#include <math.h>

// Define Gravitational constant
#define G 6.67e-11

// Define structure of a planet
struct Planet {
    double mass; // in kg
    double radius; // in m
    double x; // x-coordinates in m
    double y; // y-coordinates in m
    double z; // z-coordinates in m
    double vx; // x component of velocity in m/s
    double vy; // y component of velocity in m/s
    double vz; // z component of velocity in m/s
};

int main() {
    // Define an array of planets
    struct Planet planets[5];
    
    // Initialize the first planet (Sun)
    planets[0].mass = 1.989e30; // mass of Sun
    planets[0].radius = 696340000; // radius of Sun
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;
    
    // Initialize the second planet (Earth)
    planets[1].mass = 5.972e24; // mass of Earth
    planets[1].radius = 6371000; // radius of Earth
    planets[1].x = 147098290000; // aphelion distance from the Sun
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 30290; // velocity at aphelion
    planets[1].vz = 0;
    
    // Initialize the third planet (Mars)
    planets[2].mass = 6.39e23; // mass of Mars
    planets[2].radius = 3389500; // radius of Mars
    planets[2].x = 206655215000; // aphelion distance from the Sun
    planets[2].y = 0;
    planets[2].z = 0;
    planets[2].vx = 0;
    planets[2].vy = 26500; // velocity at aphelion
    planets[2].vz = 0;
    
    // Initialize the fourth planet (Jupiter)
    planets[3].mass = 1.898e27; // mass of Jupiter
    planets[3].radius = 69911000; // radius of Jupiter
    planets[3].x = 816520800000; // aphelion distance from the Sun
    planets[3].y = 0;
    planets[3].z = 0;
    planets[3].vx = 0;
    planets[3].vy = 13720; // velocity at aphelion
    planets[3].vz = 0;
    
    // Initialize the fifth planet (Saturn)
    planets[4].mass = 5.683e26; // mass of Saturn
    planets[4].radius = 58232000; // radius of Saturn
    planets[4].x = 1513325783000; // aphelion distance from the Sun
    planets[4].y = 0;
    planets[4].z = 0;
    planets[4].vx = 0;
    planets[4].vy = 10180; // velocity at aphelion
    planets[4].vz = 0;
    
    // Define simulation parameters
    double t = 0; // current time
    double dt = 86400; // time step size (1 day)
    double T = 300*365*86400; // total simulation time (300 years)
    int n = 5; // number of planets
    
    // Define variables for calculation
    double dx, dy, dz, r, Fx, Fy, Fz, ax, ay, az;
    
    // Start the simulation using Euler's method
    while (t <= T) {
        // Calculate forces on each planet
        for (int i = 0; i < n; i++) {
            Fx = 0;
            Fy = 0;
            Fz = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    dx = planets[j].x - planets[i].x;
                    dy = planets[j].y - planets[i].y;
                    dz = planets[j].z - planets[i].z;
                    r = sqrt(dx*dx + dy*dy + dz*dz);
                    Fx += G*planets[i].mass*planets[j].mass*dx/(r*r*r);
                    Fy += G*planets[i].mass*planets[j].mass*dy/(r*r*r);
                    Fz += G*planets[i].mass*planets[j].mass*dz/(r*r*r);
                }
            }
            // Calculate accelerations on each planet
            ax = Fx/planets[i].mass;
            ay = Fy/planets[i].mass;
            az = Fz/planets[i].mass;
            // Update velocities of each planet
            planets[i].vx += ax*dt;
            planets[i].vy += ay*dt;
            planets[i].vz += az*dt;
        }
        // Update positions of each planet
        for (int i = 0; i < n; i++) {
            planets[i].x += planets[i].vx*dt;
            planets[i].y += planets[i].vy*dt;
            planets[i].z += planets[i].vz*dt;
        }
        // Update time
        t += dt;
    }
    
    // Print the final position of each planet
    printf("Final positions:\n");
    for (int i = 0; i < n; i++) {
        printf("Planet %d:\n", i+1);
        printf("x = %f m\n", planets[i].x);
        printf("y = %f m\n", planets[i].y);
        printf("z = %f m\n", planets[i].z);
        printf("\n");
    }
    
    return 0;
}