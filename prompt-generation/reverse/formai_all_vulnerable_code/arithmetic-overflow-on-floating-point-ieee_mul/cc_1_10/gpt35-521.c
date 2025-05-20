//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
/*
 * This program simulates the gravitational interaction between planets in a 2D space.
 * It uses the Runge-Kutta method to numerically solve the differential equations that describe 
 * the motion of the planets. 
 */

#include <stdio.h>
#include <math.h>

#define G 6.67408e-11    // gravitational constant
#define N 3              // number of planets
#define dT 1             // timestep

// Data structure for a planet
typedef struct {
    double x;           // x-position
    double y;           // y-position
    double vx;          // x-velocity
    double vy;          // y-velocity
    double m;           // mass
} planet;

// Function that calculates the acceleration of a planet due to the gravitational pull from other planets
void acceleration(planet p[], int i, double a[][2]) {
    double r, r2, F, Fx, Fy;
    
    for (int j = 0; j < N; j++) {
        if (i != j) {
            r2 = pow(p[j].x - p[i].x, 2) + pow(p[j].y - p[i].y, 2);
            r = sqrt(r2);
            F = (G * p[i].m * p[j].m) / r2;
            Fx = F * (p[j].x - p[i].x) / r;
            Fy = F * (p[j].y - p[i].y) / r;
            a[i][0] += Fx / p[i].m;     // x-component of acceleration
            a[i][1] += Fy / p[i].m;     // y-component of acceleration
        }
    }
}

// Function that performs one timestep of the simulation
void timestep(planet p[], double a[][2]) {
    double k1[4], k2[4], k3[4], k4[4];
    
    for (int i = 0; i < N; i++) {
        // Calculate k1
        k1[0] = dT * p[i].vx;
        k1[1] = dT * p[i].vy;
        k1[2] = dT * a[i][0];
        k1[3] = dT * a[i][1];
        
        // Calculate k2
        k2[0] = dT * (p[i].vx + 0.5 * k1[2]);
        k2[1] = dT * (p[i].vy + 0.5 * k1[3]);
        acceleration(p, i, a);
        k2[2] = dT * a[i][0];
        k2[3] = dT * a[i][1];
        
        // Calculate k3
        k3[0] = dT * (p[i].vx + 0.5 * k2[2]);
        k3[1] = dT * (p[i].vy + 0.5 * k2[3]);
        acceleration(p, i, a);
        k3[2] = dT * a[i][0];
        k3[3] = dT * a[i][1];
        
        // Calculate k4
        k4[0] = dT * (p[i].vx + k3[2]);
        k4[1] = dT * (p[i].vy + k3[3]);
        acceleration(p, i, a);
        k4[2] = dT * a[i][0];
        k4[3] = dT * a[i][1];
        
        // Update planet position and velocity
        p[i].x += (k1[0] + 2*k2[0] + 2*k3[0] + k4[0]) / 6;
        p[i].y += (k1[1] + 2*k2[1] + 2*k3[1] + k4[1]) / 6;
        p[i].vx += (k1[2] + 2*k2[2] + 2*k3[2] + k4[2]) / 6;
        p[i].vy += (k1[3] + 2*k2[3] + 2*k3[3] + k4[3]) / 6;
        
        // Reset acceleration for next timestep
        a[i][0] = 0;
        a[i][1] = 0;
    }
}

int main() {
    planet p[N] = { {0, 0, 0, 0, 1e11},     // planet 1
                    {1e11, 0, 0, 2e4, 5.97e24},  // planet 2
                    {0, 2e11, -2e4, 0, 6.4e23} };   // planet 3
                    
    double a[N][2] = { {0, 0},
                       {0, 0},
                       {0, 0} };
                       
    for (int t = 0; t < 365*24*60*60; t += dT) {
        timestep(p, a);
        printf("%e,%e,%e,%e,%e,%e\n", p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y);
    }
    
    return 0;
}