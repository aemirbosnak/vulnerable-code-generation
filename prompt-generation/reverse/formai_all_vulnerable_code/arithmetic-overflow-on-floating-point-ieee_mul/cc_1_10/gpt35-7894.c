//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: accurate
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Defining Constants
#define PI 3.14159265358979323846
#define G 6.67408e-11

//Defining celestial bodies and their properties
typedef struct {
    double x, y; //Position 
    double vx, vy; //Velocity
    double fx, fy; //Force
    double mass; //Mass
} Body;

//Defining simulation parameters
#define N 6 //Number of bodies
#define TIMESTEP 86400 //Simulation time-step (seconds)
#define DURATION 31536000 //Simulation duration (seconds)

int main() {

    //Defining celestial bodies and their properties
    Body bodies[N] = {
        {0, 0, 0, 0, 0, 1.989e30}, //Sun
        {57.9e9, 0, 0, 47.87e3, 0, 3.3022e23}, //Mercury
        {108.16e9, 0, 0, 35.02e3, 0, 4.8685e24}, //Venus
        {149.6e9, 0, 0, 29.78e3, 0, 5.972e24}, //Earth
        {227.94e9, 0, 0, 24.08e3, 0, 6.4185e23}, //Mars
        {778.57e9, 0, 0, 13.07e3, 0, 1.8986e27} //Jupiter
    };

    //Defining variables
    double fx, fy, r, F;
    int i, j, k;
    double dt = TIMESTEP;
    double t = 0.0;

    //Defining random seed
    srand(time(NULL));

    //Defining simulation loop
    while (t <= DURATION) {

        //Calculating forces on each body
        for (i = 0; i < N; i++) {
            bodies[i].fx = 0.0;
            bodies[i].fy = 0.0;
            for (j = 0; j < N; j++) {
                if (i != j) {
                    r = sqrt(pow(bodies[i].x - bodies[j].x, 2) + pow(bodies[i].y - bodies[j].y, 2));
                    F = G * bodies[i].mass * bodies[j].mass / pow(r, 2);
                    fx = F * (bodies[j].x - bodies[i].x) / r;
                    fy = F * (bodies[j].y - bodies[i].y) / r;
                    bodies[i].fx += fx;
                    bodies[i].fy += fy;
                }
            }
        }

        //Updating positions and velocities of each body
        for (k = 0; k < N; k++) {
            bodies[k].vx += (bodies[k].fx / bodies[k].mass) * dt;
            bodies[k].vy += (bodies[k].fy / bodies[k].mass) * dt;
            bodies[k].x += bodies[k].vx * dt;
            bodies[k].y += bodies[k].vy * dt;
        }

        //Outputting positions of each body
        printf("t = %f seconds\n", t);
        for (i = 0; i < N; i++) {
            printf("Body %d: x = %f m, y = %f m\n", i+1, bodies[i].x, bodies[i].y);
        }
        printf("\n");

        t += dt; //Updating simulation time
    }

    return 0;
}