//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11

typedef struct {
    double mass;
    double x, y;
    double vx, vy;
} planet_t;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    planet_t planets[] = {
        {5.97e24, 0, 0, 0, 0},
        {7.34e22, 0, 3.84e8, 1022, 0}
    };
    int num_planets = sizeof(planets) / sizeof(planet_t);
    double dt = 1;
    int i, j;

    while (1) {
        for (i = 0; i < num_planets; i++) {
            planet_t *p1 = &planets[i];
            double fx = 0, fy = 0;

            for (j = 0; j < num_planets; j++) {
                if (i == j) {
                    continue;
                }

                planet_t *p2 = &planets[j];
                double r = distance(p1->x, p1->y, p2->x, p2->y);
                double f = G * p1->mass * p2->mass / pow(r, 2);
                double theta = atan2(p2->y - p1->y, p2->x - p1->x);
                fx += f * cos(theta);
                fy += f * sin(theta);
            }

            p1->vx += fx / p1->mass * dt;
            p1->vy += fy / p1->mass * dt;
            p1->x += p1->vx * dt;
            p1->y += p1->vy * dt;
        }

        printf("Earth: (%f, %f)\n", planets[0].x, planets[0].y);
        printf("Moon: (%f, %f)\n", planets[1].x, planets[1].y);
        printf("==============================\n");

        system("sleep 0.1");
        system("clear");
    }

    return 0;
}