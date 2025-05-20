//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 10
#define G 6.67430e-11 // Gravitational constant

typedef struct {
    char name[20];
    double mass; // in kg
    double x;    // position x
    double y;    // position y
    double vx;   // velocity x
    double vy;   // velocity y
} Planet;

void print_planet_info(Planet *p) {
    printf("Planet: %s\n", p->name);
    printf("Mass: %e kg\n", p->mass);
    printf("Position: (%.2f, %.2f)\n", p->x, p->y);
    printf("Velocity: (%.2f, %.2f)\n", p->vx, p->vy);
}

void update_velocity(Planet *p1, Planet *p2, double dt) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx * dx + dy * dy);
    if (distance == 0) return; // Prevent division by zero

    double force = G * p1->mass * p2->mass / (distance * distance);
    double fx = force * (dx / distance);
    double fy = force * (dy / distance);

    p1->vx += fx / p1->mass * dt;
    p1->vy += fy / p1->mass * dt;
}

void update_position(Planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void simulate(Planet planets[], int num_planets, double dt, double total_time) {
    for (double t = 0; t < total_time; t += dt) {
        // Update velocities based on other planets
        for (int i = 0; i < num_planets; i++) {
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    update_velocity(&planets[i], &planets[j], dt);
                }
            }
        }
        
        // Update positions
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i], dt);
        }

        // Print the state of the planets
        printf("Time: %.2f\n", t);
        for (int i = 0; i < num_planets; i++) {
            print_planet_info(&planets[i]);
        }
        printf("\n");
    }
}

int main() {
    Planet planets[MAX_PLANETS];
    int num_planets = 0;
    double dt, total_time;

    printf("Enter the time step (dt in seconds): ");
    scanf("%lf", &dt);
    printf("Enter the total simulation time (in seconds): ");
    scanf("%lf", &total_time);

    printf("Enter number of planets (max %d): ", MAX_PLANETS);
    scanf("%d", &num_planets);
    if (num_planets > MAX_PLANETS) {
        printf("Exceeded maximum number of planets.\n");
        return 1;
    }

    for (int i = 0; i < num_planets; i++) {
        printf("Enter name for planet %d: ", i + 1);
        scanf("%s", planets[i].name);
        printf("Enter mass for planet %d (in kg): ", i + 1);
        scanf("%lf", &planets[i].mass);
        printf("Enter initial position (x y) for planet %d: ", i + 1);
        scanf("%lf %lf", &planets[i].x, &planets[i].y);
        printf("Enter initial velocity (vx vy) for planet %d: ", i + 1);
        scanf("%lf %lf", &planets[i].vx, &planets[i].vy);
    }

    printf("Starting simulation...\n");
    simulate(planets, num_planets, dt, total_time);
    
    return 0;
}