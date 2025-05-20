//MISTRAL-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: imaginative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SUN_RADIUS 1.5
#define MIN_DISTANCE 1.0
#define MAX_DISTANCE 10.0
#define PI M_PI

typedef struct {
    double x, y, mass, radius;
} Planet;

Planet planets[8] = {
    {2.0, 0.0, 5.972e24, 0.064},
    {4.5, 1.2, 7.348e22, 0.1},
    {6.0, 0.0, 7.348e22, 0.13},
    {7.5, -1.2, 7.348e22, 0.16},
    {9.0, -2.5, 7.348e22, 0.19},
    {10.5, -3.8, 7.348e22, 0.23},
    {12.0, -5.1, 7.348e22, 0.27},
    {14.0, -6.4, 7.348e22, 0.32}
};

void draw_planet(double x, double y, double radius) {
    int i, j;
    for (i = -(int)radius; i <= (int)radius; i++) {
        for (j = -(int)radius; j <= (int)radius; j++) {
            if (sqrt(pow(i, 2) + pow(j, 2)) <= radius)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("x: %.2f y: %.2f\n", x, y);
}

void calc_position(Planet *planet) {
    double total_mass = 0;
    double x, y;
    double dx = 0, dy = 0;

    for (int i = 0; i < 8; i++) {
        if (i != (int)planet - (int)planets) {
            total_mass += planets[i].mass;
            double distance = sqrt(pow(planet->x - planets[i].x, 2) + pow(planet->y - planets[i].y, 2));
            dx += (planets[i].mass * (planet->x - planets[i].x) / distance) / (total_mass + planet->mass);
            dy += (planets[i].mass * (planet->y - planets[i].y) / distance) / (total_mass + planet->mass);
        }
    }

    planet->x += dx;
    planet->y += dy;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 8; j++) {
            calc_position(&planets[j]);
            double distance = sqrt(pow(planets[j].x, 2) + pow(planets[j].y, 2));
            if (distance < MIN_DISTANCE) {
                planets[j].x += (rand() % 10 + 1) * 0.01;
                planets[j].y += (rand() % 10 + 1) * 0.01;
            }
            if (distance > MAX_DISTANCE) {
                planets[j].x -= (rand() % 10 + 1) * 0.01;
                planets[j].y -= (rand() % 10 + 1) * 0.01;
            }
            draw_planet(planets[j].x, planets[j].y, planets[j].radius);
        }
        printf("\n");
    }

    return 0;
}