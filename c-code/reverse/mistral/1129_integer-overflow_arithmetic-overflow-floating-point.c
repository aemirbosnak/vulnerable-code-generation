#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TIME 100.0
#define GRAVITY 9.81

typedef struct {
    double x, y, vx, vy;
} Drone;

void update_drone(Drone *drone, double dt) {
    drone->vx += drone->vy * dt;
    drone->vy -= GRAVITY * dt;
    drone->x += drone->vx * dt;
    drone->y += drone->vy * dt;
}

int main(int argc, char *argv[]) {
    int simulations;
    if (argc != 2) {
        printf("Usage: %s <number_of_simulations>\n", argv[0]);
        return 1;
    }
    simulations = atoi(argv[1]);

    for (int i = 0; i < simulations; ++i) {
        Drone drone = {0, 10, 1, 0};
        double time = 0;
        while (drone.y > 0 && time < MAX_TIME) {
            update_drone(&drone, 0.01);
            time += 0.01;
        }
        printf("Simulation %d: Time=%.2f, Position=(%.2f, %.2f)\n", i + 1, time, drone.x, drone.y);
    }

    return 0;
}
