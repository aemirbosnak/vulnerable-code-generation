//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.673E-11 // gravitational constant
#define DT 0.1 // time step
#define MAX_ITERATIONS 100 // maximum number of iterations

typedef struct {
    double x, y; // position (meters)
    double vx, vy; // velocity (meters/second)
    double mass; // mass (kg)
} Body;

Body planet1 = {0, 0, 0, 0, 5.97E24}; // Earth
Body planet2 = {384400000, 0, 0, 1022, 7.34E22}; // Moon
Body player = {0, 6371000 + 500000, 7800, 0, 75}; // player spacecraft

Body *bodies[] = {&planet1, &planet2, &player}; // array of all bodies

int num_bodies = 3;

void update_positions() {
    int i, j;

    for (i = 0; i < num_bodies; i++) {
        double fx = 0.0, fy = 0.0; // net force on body i

        for (j = 0; j < num_bodies; j++) {
            if (i == j) continue;

            double dx = bodies[j]->x - bodies[i]->x;
            double dy = bodies[j]->y - bodies[i]->y;
            double distance = sqrt(dx*dx + dy*dy);
            double force = G * bodies[i]->mass * bodies[j]->mass / (distance*distance);
            fx += force * dx / distance;
            fy += force * dy / distance;
        }

        double ax = fx / bodies[i]->mass;
        double ay = fy / bodies[i]->mass;

        bodies[i]->vx += ax * DT;
        bodies[i]->vy += ay * DT;

        bodies[i]->x += bodies[i]->vx * DT;
        bodies[i]->y += bodies[i]->vy * DT;
    }
}

int main() {
    int i, iteration;
    srand(time(NULL));

    // randomly place player spacecraft
    player.x = rand() % 5000000;
    player.y = rand() % 5000000;

    // simulate gravity for a given number of iterations
    for (iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        update_positions();

        // check for player spacecraft collisions
        for (i = 0; i < num_bodies; i++) {
            if (bodies[i] == &player) continue;

            double dx = player.x - bodies[i]->x;
            double dy = player.y - bodies[i]->y;
            double distance = sqrt(dx*dx + dy*dy);

            if (distance < 100000) {
                printf("Player spacecraft crashed into a planet or moon!");
                return 0;
            }
        }

        // print player spacecraft position
        printf("Player spacecraft position: (%.2f, %.2f)\n", player.x, player.y);
    }

    printf("Simulation complete.\n");

    return 0;
}