//Gemma-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

typedef struct Planet {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

void update_planets(Planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        double ax = planets[i].vx * planets[i].mass;
        double ay = planets[i].vy * planets[i].mass;
        double az = planets[i].vz * planets[i].mass;

        planets[i].x += ax * 0.01;
        planets[i].y += ay * 0.01;
        planets[i].z += az * 0.01;
    }
}

int main() {
    Planet planets[NUM_PLANETS] = {
        {"Mercury", 0.055, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Venus", 0.81, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Earth", 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Mars", 0.105, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Jupiter", 5.9e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Saturn", 5.8e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Uranus", 1.0e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Neptune", 1.0e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    };

    int num_players = 2;

    for (int i = 0; i < num_players; i++) {
        printf("Enter the initial position (x, y, z) of player %d in the Solar System:\n", i + 1);
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
    }

    for (int i = 0; i < 1000; i++) {
        update_planets(planets);
        for (int j = 0; j < num_players; j++) {
            printf("Player %d's position: (%.2f, %.2f, %.2f)\n", j + 1, planets[j].x, planets[j].y, planets[j].z);
        }
        printf("\n");
    }

    return 0;
}