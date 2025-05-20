//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: modular
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11   // gravitational constant G

// Define a structure to represent a celestial body
typedef struct {
    char name[20];
    double mass;
    double x, y, z;     // position coordinates
    double vx, vy, vz;  // velocity components
    double ax, ay, az;  // acceleration components
} CelestialBody;

// Calculate the distance between two celestial bodies
double distance(CelestialBody body1, CelestialBody body2) {
    double dx = body2.x - body1.x;
    double dy = body2.y - body1.y;
    double dz = body2.z - body1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Calculate the gravitational force between two celestial bodies
double force(CelestialBody body1, CelestialBody body2) {
    double r = distance(body1, body2);
    return G * body1.mass * body2.mass / (r*r);
}

int main() {
    // Define the celestial bodies in our solar system
    CelestialBody sun = {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    CelestialBody earth = {"Earth", 5.972e24, 149.6e9, 0, 0, 0, 29.78e3, 0, 0, 0, 0};
    CelestialBody moon = {"Moon", 7.342e22, 149.6e9, 0, 0, 0, 29.78e3 + 1.022e3, 0, 0, 0, 0};
    
    // Simulation parameters
    double dt = 60; // time step in seconds
    double t = 0;   // initial time
    double tf = 365*24*60*60;  // final time (one year)
    
    // Simulation loop
    while (t < tf) {
        // Calculate the forces on each body
        double f_sun_earth = force(sun, earth);
        double f_earth_sun = f_sun_earth;
        double f_sun_moon = force(sun, moon);
        double f_moon_sun = f_sun_moon;
        double f_earth_moon = force(earth, moon);
        double f_moon_earth = f_earth_moon;
        
        // Calculate the accelerations on each body
        sun.ax = (-f_earth_sun*cos(0)-f_moon_sun*cos(0)) / sun.mass;
        sun.ay = (-f_earth_sun*sin(0)-f_moon_sun*sin(0)) / sun.mass;
        sun.az = 0;
        
        earth.ax = (f_sun_earth*cos(0)-f_moon_earth*cos(0)) / earth.mass;
        earth.ay = (f_sun_earth*sin(0)-f_moon_earth*sin(0)) / earth.mass;
        earth.az = 0;
        
        moon.ax = (f_sun_moon*cos(0)-f_earth_moon*cos(0)) / moon.mass;
        moon.ay = (f_sun_moon*sin(0)-f_earth_moon*sin(0)) / moon.mass;
        moon.az = 0;
        
        // Update the velocities and positions of each body
        sun.vx += sun.ax * dt;
        sun.vy += sun.ay * dt;
        sun.vz += sun.az * dt;
        sun.x += sun.vx * dt;
        sun.y += sun.vy * dt;
        sun.z += sun.vz * dt;
        
        earth.vx += earth.ax * dt;
        earth.vy += earth.ay * dt;
        earth.vz += earth.az * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        earth.z += earth.vz * dt;
        
        moon.vx += moon.ax * dt;
        moon.vy += moon.ay * dt;
        moon.vz += moon.az * dt;
        moon.x += moon.vx * dt;
        moon.y += moon.vy * dt;
        moon.z += moon.vz * dt;
        
        // Output the position of the moon
        printf("%.2f\t%.2f\t%.2f\n", moon.x, moon.y, moon.z);
        
        // Advance the time
        t += dt;
    }
    
    return 0;
}