//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: protected
#include <stdio.h>
#include <math.h>

#define G 6.674e-11

typedef struct planet {
    char name[20];
    double mass;
    double radius;
    double x;
    double y;
    double vx;
    double vy;
} planet_t;

typedef struct force {
    double x;
    double y;
} force_t;

void calculate_forces(planet_t *planets, int num_planets, force_t *forces);
void update_positions(planet_t *planets, int num_planets, force_t *forces, double timestep);

int main() {
    int num_planets;
    double timestep;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);
    planet_t planets[num_planets];
    force_t forces[num_planets];

    printf("Enter the timestep: ");
    scanf("%lf", &timestep);

    for (int i = 0; i < num_planets; i++) {
        printf("Enter the name, mass, radius, x position, y position, vx velocity and vy velocity of planet %d: ", i+1);
        scanf("%s %lf %lf %lf %lf %lf %lf", planets[i].name, &planets[i].mass, &planets[i].radius,
                &planets[i].x, &planets[i].y, &planets[i].vx, &planets[i].vy);
    }

    while (1) {
        calculate_forces(planets, num_planets, forces);
        update_positions(planets, num_planets, forces, timestep);
        printf("Positions:\n");
        for (int i = 0; i < num_planets; i++) {
            printf("%s: x=%lf y=%lf\n", planets[i].name, planets[i].x, planets[i].y);
        }
    }
    return 0;
}

void calculate_forces(planet_t *planets, int num_planets, force_t *forces) {
    for (int i = 0; i < num_planets; i++) {
        forces[i].x = 0;
        forces[i].y = 0;
        for (int j = 0; j < num_planets; j++) {
            if (i == j) continue;
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double r = sqrt(dx*dx + dy*dy);
            double f = G*planets[i].mass*planets[j].mass/(r*r);
            forces[i].x += f*dx/r;
            forces[i].y += f*dy/r;
        }
    }
}

void update_positions(planet_t *planets, int num_planets, force_t *forces, double timestep) {
    for (int i = 0; i < num_planets; i++) {
        double ax = forces[i].x/planets[i].mass;
        double ay = forces[i].y/planets[i].mass;
        planets[i].vx += ax*timestep;
        planets[i].vy += ay*timestep;
        planets[i].x += planets[i].vx*timestep;
        planets[i].y += planets[i].vy*timestep;
    }
}