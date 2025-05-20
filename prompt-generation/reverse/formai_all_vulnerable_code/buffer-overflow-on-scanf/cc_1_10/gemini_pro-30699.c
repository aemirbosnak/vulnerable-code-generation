//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} planet;

void calculate_acceleration(planet *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        double ax = 0;
        double ay = 0;
        for (int j = 0; j < num_planets; j++) {
            if (i == j) {
                continue;
            }
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double r = sqrt(dx * dx + dy * dy);
            double f = planets[j].mass / (r * r * r);
            ax += f * dx;
            ay += f * dy;
        }
        planets[i].vx += ax * 0.01;
        planets[i].vy += ay * 0.01;
    }
}

void update_positions(planet *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        planets[i].x += planets[i].vx * 0.01;
        planets[i].y += planets[i].vy * 0.01;
    }
}

int main() {
    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    planet *planets = malloc(sizeof(planet) * num_planets);

    for (int i = 0; i < num_planets; i++) {
        printf("Enter the mass of planet %d: ", i + 1);
        scanf("%lf", &planets[i].mass);
        printf("Enter the x coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].x);
        printf("Enter the y coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].y);
        printf("Enter the x velocity of planet %d: ", i + 1);
        scanf("%lf", &planets[i].vx);
        printf("Enter the y velocity of planet %d: ", i + 1);
        scanf("%lf", &planets[i].vy);
    }

    int num_steps;
    printf("Enter the number of steps: ");
    scanf("%d", &num_steps);

    for (int i = 0; i < num_steps; i++) {
        calculate_acceleration(planets, num_planets);
        update_positions(planets, num_planets);
    }

    for (int i = 0; i < num_planets; i++) {
        printf("The final position of planet %d is (%.2lf, %.2lf)\n", i + 1, planets[i].x, planets[i].y);
    }

    free(planets);

    return 0;
}