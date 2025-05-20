//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.674e-11

struct planet {
    double mass;
    double x, y;
    double vx, vy;
};

typedef struct planet Planet;

int main() {
    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    Planet *planets = (Planet *) malloc(sizeof(Planet) * num_planets);

    for (int i = 0; i < num_planets; i++) {
        printf("\nEnter mass and initial position (x,y) and velocity (vx,vy) of planet %d: ", i+1);
        scanf("%lf %lf %lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].vx, &planets[i].vy);
    }

    double time_step;
    printf("\nEnter the time step size in seconds: ");
    scanf("%lf", &time_step);

    double end_time;
    printf("\nEnter the total time to simulate in seconds: ");
    scanf("%lf", &end_time);

    int iterations = end_time / time_step;

    for (int i = 1; i <= iterations; i++) {
        for (int j = 0; j < num_planets; j++) {
            double a_x = 0, a_y = 0;
            for (int k = 0; k < num_planets; k++) {
                if (j == k) continue;
                double dx = planets[k].x - planets[j].x;
                double dy = planets[k].y - planets[j].y;
                double distance = sqrt(dx*dx + dy*dy);
                double force = GRAVITY_CONSTANT * planets[j].mass * planets[k].mass / (distance * distance);
                double acceleration = force / planets[j].mass;
                a_x += acceleration * dx / distance;
                a_y += acceleration * dy / distance;
            }
            planets[j].vx += a_x * time_step;
            planets[j].vy += a_y * time_step;
            planets[j].x += planets[j].vx * time_step;
            planets[j].y += planets[j].vy * time_step;
        }
        printf("\nAfter %d seconds:\n", i);
        for (int j = 0; j < num_planets; j++) {
            printf("Planet %d at position (%lf, %lf) with velocity (%lf, %lf)\n", j+1, planets[j].x, planets[j].y, planets[j].vx, planets[j].vy);
        }
    }

    free(planets);

    return 0;
}