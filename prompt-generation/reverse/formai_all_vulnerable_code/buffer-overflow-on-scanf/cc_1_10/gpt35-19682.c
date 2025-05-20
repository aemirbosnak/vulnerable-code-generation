//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11     // Gravitational constant

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

// Structure for a planet
struct planet {
    char name[20];
    double mass;
    double x;
    double y;
    double vx;
    double vy;
};

// Function to update the velocity and position of a planet
void update(struct planet *p, double ax, double ay, double dt) {
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

// Main function
int main() {
    int n;      // Number of planets
    printf("Enter the number of planets: ");
    scanf("%d", &n);
    
    struct planet* planets = (struct planet*) malloc(n * sizeof(struct planet));    // Creating an array of n planets
    
    // Reading the data of the planets
    printf("Enter the details of the planets:\n");
    for(int i = 0; i < n; i++) {
        printf("Planet %d:\n", i+1);
        printf("Name: ");
        scanf("%s", planets[i].name);
        printf("Mass (in kg): ");
        scanf("%lf", &planets[i].mass);
        printf("x-coordinate (in m): ");
        scanf("%lf", &planets[i].x);
        printf("y-coordinate (in m): ");
        scanf("%lf", &planets[i].y);
        printf("Velocity in x-direction (in m/s): ");
        scanf("%lf", &planets[i].vx);
        printf("Velocity in y-direction (in m/s): ");
        scanf("%lf", &planets[i].vy);
    }
    
    double dt;      // Time step for simulation
    printf("Enter the time step for simulation (in seconds): ");
    scanf("%lf", &dt);
    int t;      // Number of time steps for simulation
    printf("Enter the number of time steps for simulation: ");
    scanf("%d", &t);
    
    // Running the simulation for t time steps
    for(int i = 0; i < t; i++) {
        // Calculating the acceleration for each planet
        for(int j = 0; j < n; j++) {
            double ax = 0, ay = 0;
            for(int k = 0; k < n; k++) {
                if(j != k) {
                    double d = distance(planets[j].x, planets[j].y, planets[k].x, planets[k].y);
                    double f = G * planets[j].mass * planets[k].mass / pow(d, 2);
                    ax += f * (planets[k].x - planets[j].x) / d / planets[j].mass;
                    ay += f * (planets[k].y - planets[j].y) / d / planets[j].mass;
                }
            }
            update(&planets[j], ax, ay, dt);   // Updating the velocity and position of the planet
        }
    }
    
    // Printing the final positions of the planets
    printf("The final positions of the planets are:\n");
    for(int i = 0; i < n; i++) {
        printf("%s: (%.2lf, %.2lf)\n", planets[i].name, planets[i].x, planets[i].y);
    }
    
    free(planets);      // Freeing the memory
    
    return 0;
}