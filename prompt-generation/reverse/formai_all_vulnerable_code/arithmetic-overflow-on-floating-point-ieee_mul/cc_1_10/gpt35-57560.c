//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: puzzling
#include <stdio.h>
#include <math.h>

#define G 6.6743*pow(10,-11) // gravitational constant
#define dt 0.1 // time step

// planet structure
typedef struct planet_t {
    double mass;
    double pos[2]; // x, y position
    double vel[2]; // x, y velocity
} planet;
 
// function to calculate the gravitational force between two planets
void gravity_force(planet p1, planet p2, double* fx, double* fy) {
    double r = sqrt(pow(p2.pos[0]-p1.pos[0], 2) + pow(p2.pos[1]-p1.pos[1], 2)); // distance between planets
    double f = G*p1.mass*p2.mass/pow(r, 2); // magnitude of the force
    *fx += f*(p2.pos[0]-p1.pos[0])/r; // x component of the force
    *fy += f*(p2.pos[1]-p1.pos[1])/r; // y component of the force
}

int main() {
    // initialize planets
    planet planets[3] = {
        {5.97*pow(10,24), {0, 0}, {0, 0}}, // earth
        {7.35*pow(10,22), {384400000, 0}, {0, 1023}}, // moon
        {19890000000000000000000000000.0, {149.6*pow(10,9), 0}, {0, 29800}} // sun
    };
    int num_planets = sizeof(planets)/sizeof(planet);
 
    // simulation loop
    int i, j, k, n = 0;
    double fx, fy, ax, ay;
    while (n < 1000) { // simulate for 1000 time steps
        // calculate gravitational forces and update velocities
        for (i = 0; i < num_planets; i++) {
            fx = 0; fy = 0;
            for (j = 0; j < num_planets; j++) {
                if (i != j) {
                    gravity_force(planets[i], planets[j], &fx, &fy);
                }
            }
            ax = fx/planets[i].mass;
            ay = fy/planets[i].mass;
            planets[i].vel[0] += ax*dt;
            planets[i].vel[1] += ay*dt;
        }
        // update positions
        for (k = 0; k < num_planets; k++) {
            planets[k].pos[0] += planets[k].vel[0]*dt;
            planets[k].pos[1] += planets[k].vel[1]*dt;
        }
        // print positions
        printf("---------------------------\n");
        for (k = 0; k < num_planets; k++) {
            printf("Planet %d position: (%e, %e)\n", k+1, planets[k].pos[0], planets[k].pos[1]);
        }
        n++;
    }
    return 0;
}