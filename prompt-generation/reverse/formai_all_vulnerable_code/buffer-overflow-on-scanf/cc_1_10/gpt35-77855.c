//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define MAX_OBJ 50 // Maximum number of objects
#define MAX_STEP 10000 // Maximum number of simulation steps

struct object {
    double mass; // Mass of the object
    double x; // x-position
    double y; // y-position
    double vx; // x-velocity
    double vy; // y-velocity
};

int main() {
    int num_obj; // Number of objects
    struct object objs[MAX_OBJ]; // Objects array
    double delta_t; // Time step
    int num_step; // Number of simulation steps
    double forces[MAX_OBJ][MAX_OBJ][2]; // Array to hold gravitational forces between objects
    
    // Read in simulation parameters
    printf("Enter number of objects: ");
    scanf("%d", &num_obj);
    printf("Enter time step (seconds): ");
    scanf("%lf", &delta_t);
    printf("Enter number of simulation steps: ");
    scanf("%d", &num_step);

    // Read in object parameters
    for (int i = 0; i < num_obj; i++) {
        printf("Enter mass of object %d (kg): ", i+1);
        scanf("%lf", &objs[i].mass);
        printf("Enter x-position of object %d (m): ", i+1);
        scanf("%lf", &objs[i].x);
        printf("Enter y-position of object %d (m): ", i+1);
        scanf("%lf", &objs[i].y);
        printf("Enter x-velocity of object %d (m/s): ", i+1);
        scanf("%lf", &objs[i].vx);
        printf("Enter y-velocity of object %d (m/s): ", i+1);
        scanf("%lf", &objs[i].vy);
    }

    // Simulation loop
    for (int step = 0; step < num_step; step++) {
        // Calculate gravitational forces between all objects
        for (int i = 0; i < num_obj; i++) {
            for (int j = i+1; j < num_obj; j++) {
                double dx = objs[i].x - objs[j].x;
                double dy = objs[i].y - objs[j].y;
                double dist = sqrt(dx*dx + dy*dy);
                double force = G * objs[i].mass * objs[j].mass / (dist * dist);
                forces[i][j][0] = force * dx / dist;
                forces[i][j][1] = force * dy / dist;
                forces[j][i][0] = -forces[i][j][0];
                forces[j][i][1] = -forces[i][j][1];
            }
        }
        
        // Update object positions and velocities based on forces
        for (int i = 0; i < num_obj; i++) {
            double fx = 0.0;
            double fy = 0.0;
            for (int j = 0; j < num_obj; j++) {
                fx += forces[i][j][0];
                fy += forces[i][j][1];
            }
            objs[i].vx += fx / objs[i].mass * delta_t;
            objs[i].vy += fy / objs[i].mass * delta_t;
            objs[i].x += objs[i].vx * delta_t;
            objs[i].y += objs[i].vy * delta_t;
        }
    }
    
    // Print final object positions and velocities
    for (int i = 0; i < num_obj; i++) {
        printf("Object %d: x = %.2f m, y = %.2f m, vx = %.2f m/s, vy = %.2f m/s\n",
            i+1, objs[i].x, objs[i].y, objs[i].vx, objs[i].vy);
    }
    
    return 0;
}