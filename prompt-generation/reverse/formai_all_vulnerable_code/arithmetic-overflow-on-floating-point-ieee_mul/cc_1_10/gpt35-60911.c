//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <math.h>
#include <stdio.h>

const double G = 6.6743e-11; // gravitational constant (N*m^2/kg^2)

typedef struct {
    double x, y; // position (m)
    double vx, vy; // velocity (m/s)
    double m; // mass (kg)
} Body;

void compute_forces(Body *bodies, int n)
{
    for (int i = 0; i < n; i++) {
        double fx = 0, fy = 0; // total force on body i
        
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // skip self
            
            // compute force from j on i using gravitation
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double r = hypot(dx, dy);
            double f = G * bodies[i].m * bodies[j].m / (r*r);
            fx += f * dx / r;
            fy += f * dy / r;
        }
        
        // update acceleration using total force
        double ax = fx / bodies[i].m;
        double ay = fy / bodies[i].m;
        
        // update velocity using acceleration
        bodies[i].vx += ax;
        bodies[i].vy += ay;
    }
}

void compute_positions(Body *bodies, int n, double dt)
{
    for (int i = 0; i < n; i++) {
        // update position using velocity
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

int main()
{
    Body bodies[] = {
        {.x = 0, .y = 0, .vx = 0, .vy = 0, .m = 5.97e24}, // Earth
        {.x = 3.84e8, .y = 0, .vx = 0, .vy = 1022, .m = 7.34e22}, // Moon
    };
    int n = sizeof(bodies) / sizeof(Body);
    double dt = 60; // time step (s)
    
    for (double t = 0; t < 24*60*60; t += dt) { // simulate 1 day
        compute_forces(bodies, n);
        compute_positions(bodies, n, dt);
    }
    
    printf("Earth: (%.0f, %.0f), Moon: (%.0f, %.0f)\n",
           bodies[0].x, bodies[0].y, bodies[1].x, bodies[1].y);
    
    return 0;
}