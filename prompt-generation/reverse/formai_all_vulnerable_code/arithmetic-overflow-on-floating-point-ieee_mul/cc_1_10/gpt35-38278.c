//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant
#define DT 0.1       // time step
#define STEPS 1000   // number of time steps
#define N 3          // number of planets

typedef struct {
    double x, y;
    double vx, vy;
    double mass;
} planet;

// compute the force exerted on p1 by p2
void calculate_force(planet *p1, planet *p2, double *fx, double *fy) {
    double r = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    double f = G * p1->mass * p2->mass / pow(r, 2);
    *fx = f * (p2->x - p1->x) / r;
    *fy = f * (p2->y - p1->y) / r;
}

int main(void) {
    planet planets[N] = {
        { 0, 0, 0, 0, 5.9736e24 }, // earth
        { 0, 384400000, 1022, 0, 7.342e22 }, // moon
        { 0, -6371000, -8000, 0, 1000 } // satellite
    };
    double fx[N], fy[N];
    
    for (int i = 0; i < STEPS; i++) {
        // compute forces between all pairs of planets
        for (int j = 0; j < N; j++) {
            fx[j] = 0;
            fy[j] = 0;
            for (int k = 0; k < N; k++) {
                if (j != k) {
                    double fx_k, fy_k;
                    calculate_force(&planets[j], &planets[k], &fx_k, &fy_k);
                    fx[j] += fx_k;
                    fy[j] += fy_k;
                }
            }
        }
        
        // update positions and velocities based on forces
        for (int j = 0; j < N; j++) {
            planets[j].vx += fx[j] / planets[j].mass * DT;
            planets[j].vy += fy[j] / planets[j].mass * DT;
            planets[j].x += planets[j].vx * DT;
            planets[j].y += planets[j].vy * DT;
        }
        
        // output positions
        printf("%d: ", i);
        for (int j = 0; j < N; j++) {
            printf("(%g, %g) ", planets[j].x, planets[j].y);
        }
        printf("\n");
    }
    
    return 0;
}