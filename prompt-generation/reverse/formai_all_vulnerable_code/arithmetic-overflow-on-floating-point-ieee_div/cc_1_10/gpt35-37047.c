//FormAI DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <math.h>

// a function to calculate the distance between two points in 3D space
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    // initialize variables
    double time = 0;
    double dt = 0.01; // time step
    double mass = 1; // mass of the object
    double G = 6.67430e-11; // gravitational constant
    double x = 0, y = 0, z = 0; // initial position of the object
    double vx = 100, vy = 0, vz = 0; // initial velocity of the object
    double ax = 0, ay = 0, az = 0; // initial acceleration of the object
    double fx = 0, fy = 0, fz = 0; // total force acting on the object

    // loop through time steps
    while (time < 10) {
        // calculate the force acting on the object due to gravity
        double r = distance(x, y, z, 0, 0, 0);
        double F = -G * mass / (r*r);
        fx = F * x / r;
        fy = F * y / r;
        fz = F * z / r;
        
        // calculate the acceleration of the object
        ax = fx / mass;
        ay = fy / mass;
        az = fz / mass;
        
        // update the velocity of the object using the calculated acceleration
        vx = vx + ax * dt;
        vy = vy + ay * dt;
        vz = vz + az * dt;
        
        // update the position of the object using the calculated velocity
        x = x + vx * dt;
        y = y + vy * dt;
        z = z + vz * dt;
        
        // print the current position of the object
        printf("time: %.2f, position: (%.2f, %.2f, %.2f)\n", time, x, y, z);
        
        // increment the time
        time += dt;
    }

    return 0;
}