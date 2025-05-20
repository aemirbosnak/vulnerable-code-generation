//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 0.0000000000667    // Gravitational constant
#define MAX_TIME 365.24*24*60*60    // One year in seconds
#define TIME_STEP 60*60    // One hour in seconds
#define NUM_PLANETS 8    // Number of planets in the simulation

struct planet {
    double x;    // x position
    double y;    // y position
    double vx;   // x velocity
    double vy;   // y velocity
    double m;    // mass
};

void simulate(struct planet planets[], int num_planets) {
    double fx[num_planets][num_planets];    // Force in x direction
    double fy[num_planets][num_planets];    // Force in y direction
    
    // Calculate forces between planets
    for (int i = 0; i < num_planets; i++) {
        for (int j = i+1; j < num_planets; j++) {
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double r = sqrt(dx*dx + dy*dy);
            double f = G * planets[i].m * planets[j].m / (r*r);
            double fxij = f * dx / r;
            double fyij = f * dy / r;
            fx[i][j] = fxij;
            fy[i][j] = fyij;
            fx[j][i] = -fxij;
            fy[j][i] = -fyij;
        }
    }
    
    // Update velocities and positions of planets
    for (int i = 0; i < num_planets; i++) {
        double ax = 0;
        double ay = 0;
        for (int j = 0; j < num_planets; j++) {
            if (j != i) {
                ax += fx[i][j] / planets[i].m;
                ay += fy[i][j] / planets[i].m;
            }
        }
        planets[i].vx += ax * TIME_STEP;
        planets[i].vy += ay * TIME_STEP;
        planets[i].x += planets[i].vx * TIME_STEP;
        planets[i].y += planets[i].vy * TIME_STEP;
    }
}

int main() {
    struct planet planets[NUM_PLANETS];
    
    // Initialize planets
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].m = 1.9891e+30;    // Sun
    planets[1].x = -1.471e+11;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = -3.0287e+4;
    planets[1].m = 5.9722e+24;    // Earth
    planets[2].x = -1.0748e+11;
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = -3.5021e+4;
    planets[2].m = 6.39e+23;    // Mars
    planets[3].x = 0;
    planets[3].y = -778.6e+9;
    planets[3].vx = 1.371e+4;
    planets[3].vy = 0;
    planets[3].m = 1.8982e+27;    // Jupiter
    planets[4].x = 0;
    planets[4].y = -1.4294e+12;
    planets[4].vx = 1.0189e+4;
    planets[4].vy = 0;
    planets[4].m = 5.6834e+26;    // Saturn
    planets[5].x = 0;
    planets[5].y = 0;
    planets[5].vx = 4.7855e+4;
    planets[5].vy = 0;
    planets[5].m = 1.9891e+30;    // Sun
    planets[6].x = 0;
    planets[6].y = 13.72e+11;
    planets[6].vx = -2.9299e+4;
    planets[6].vy = 0;
    planets[6].m = 8.681e+25;    // Uranus
    planets[7].x = 0;
    planets[7].y = 27.24e+11;
    planets[7].vx = -2.1461e+4;
    planets[7].vy = 0;
    planets[7].m = 1.024e+26;    // Neptune
    
    // Simulate planetary motion
    for (double t = 0; t < MAX_TIME; t += TIME_STEP) {
        simulate(planets, NUM_PLANETS);
    }
    
    // Print final positions of planets
    printf("Final positions (in meters):\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: (%.2f, %.2f)\n", i+1, planets[i].x, planets[i].y);
    }
    
    return 0;
}