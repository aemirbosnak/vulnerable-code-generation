//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_CELLS 100
#define G 0.00000000006674  // Gravitational constant

typedef struct {
    double mass;     // Mass of the planet
    double x;        // X position
    double y;        // Y position
    double vx;       // Velocity in X direction
    double vy;       // Velocity in Y direction
} Planet;

typedef struct {
    Planet planets[MAX_CELLS];
    int count;
} Universe;

// Function declarations
void initialize_universe(Universe *universe);
void add_planet(Universe *universe, double mass, double x, double y, double vx, double vy);
void simulate(Universe *universe, double time_step, int steps);
void update_planet(Planet *p, double fx, double fy, double dt);
void calculate_gravitational_forces(Universe *universe);

int main() {
    Universe universe;
    double time_step;
    int steps;

    initialize_universe(&universe);

    printf("Welcome to the Planet Gravity Simulation!\n");
    printf("Enter the time step (in seconds): ");
    scanf("%lf", &time_step);
    printf("Enter the number of steps to simulate: ");
    scanf("%d", &steps);
    
    // Sample planets (configurable)
    add_planet(&universe, 5.972e24, 0, 0, 0, 0);  // Earth
    add_planet(&universe, 7.348e22, 384400000, 0, 0, 1022);  // Moon
    add_planet(&universe, 1.898e27, 778500000000, 0, 0, 13720);  // Jupiter

    // Start simulation
    simulate(&universe, time_step, steps);

    return 0;
}

void initialize_universe(Universe *universe) {
    universe->count = 0;
}

void add_planet(Universe *universe, double mass, double x, double y, double vx, double vy) {
    if (universe->count < MAX_CELLS) {
        universe->planets[universe->count].mass = mass;
        universe->planets[universe->count].x = x;
        universe->planets[universe->count].y = y;
        universe->planets[universe->count].vx = vx;
        universe->planets[universe->count].vy = vy;
        universe->count++;
    } else {
        printf("Unable to add planet: Universe is full.\n");
    }
}

void simulate(Universe *universe, double time_step, int steps) {
    for (int step = 0; step < steps; step++) {
        calculate_gravitational_forces(universe);
        // Update planets' positions
        for (int i = 0; i < universe->count; i++) {
            Planet *p = &universe->planets[i];
            p->x += p->vx * time_step;
            p->y += p->vy * time_step;
            printf("Step %d: Planet %d -> Position: (%f, %f)\n", step, i, p->x, p->y);
        }
    }
}

void update_planet(Planet *p, double fx, double fy, double dt) {
    p->vx += (fx / p->mass) * dt;
    p->vy += (fy / p->mass) * dt;
}

void calculate_gravitational_forces(Universe *universe) {
    for (int i = 0; i < universe->count; i++) {
        double fx = 0, fy = 0;
        Planet *p1 = &universe->planets[i];
        for (int j = 0; j < universe->count; j++) {
            if (i != j) {
                Planet *p2 = &universe->planets[j];
                double dx = p2->x - p1->x;
                double dy = p2->y - p1->y;
                double distance = sqrt(dx * dx + dy * dy);
                if (distance > 0) {
                    double force = (G * p1->mass * p2->mass) / (distance * distance);
                    fx += force * (dx / distance);
                    fy += force * (dy / distance);
                }
            }
        }
        update_planet(p1, fx, fy, 1.0);  // We update the planet immediately after calculating the forces
    }
}