//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct planet{
    char name[20];
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} Planet;

void simulate(Planet **planets, int n, double dt, int steps){
    // Simulates the movement of n planets for steps iterations with a step size of dt
    for(int i = 0; i < steps; i++){
        // Calculate the force acting on each planet
        for(int j = 0; j < n; j++){
            double fx = 0;
            double fy = 0;
            for(int k = 0; k < n; k++){
                if(j != k){
                    double dx = planets[k]->x - planets[j]->x;
                    double dy = planets[k]->y - planets[j]->y;
                    double r = sqrt(dx*dx + dy*dy);
                    double f = (planets[j]->mass * planets[k]->mass) / (r*r);
                    fx += f * dx / r;
                    fy += f * dy / r;
                }
            }
            // Update the velocity of the planet based on the force acting on it
            planets[j]->vx += fx * dt / planets[j]->mass;
            planets[j]->vy += fy * dt / planets[j]->mass;
        }
        // Update the position of each planet based on its velocity
        for(int j = 0; j < n; j++){
            planets[j]->x += planets[j]->vx * dt;
            planets[j]->y += planets[j]->vy * dt;
        }
    }
}

int main() {
    // Create some planets
    Planet* planets[3];
    for(int i = 0; i < 3; i++){
        planets[i] = malloc(sizeof(Planet));
        printf("Enter name, mass, x, y, vx, vy for planet %d: ", i+1);
        scanf("%s %lf %lf %lf %lf %lf", 
            planets[i]->name, &planets[i]->mass,
            &planets[i]->x, &planets[i]->y,
            &planets[i]->vx, &planets[i]->vy);
    }

    // Simulate the planets for 1000 steps with a step size of 0.1
    simulate(planets, 3, 0.1, 1000);

    // Print the final position of each planet
    for(int i = 0; i < 3; i++){
        printf("%s: (%lf, %lf)\n", planets[i]->name, planets[i]->x, planets[i]->y);
    }

    // Free memory
    for(int i = 0; i < 3; i++){
        free(planets[i]);
    }

    return 0;
}