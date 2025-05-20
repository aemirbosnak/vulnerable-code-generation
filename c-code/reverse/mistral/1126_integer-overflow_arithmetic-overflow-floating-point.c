#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COUNT 2147483647

typedef struct {
    double x, y, vx, vy;
} Drone;

void update(Drone *drone, double dt, double g) {
    drone->vx += drone->vy * dt;
    drone->vy += g * dt;
    drone->x += drone->vx * dt;
    drone->y += drone->vy * dt;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <drone_x> <drone_y> <simulation_count>\n", argv[0]);
        return 1;
    }

    Drone drone = { atof(argv[1]), atof(argv[2]), 0, 0 };
    double g = 9.81;
    double dt = atof(argv[3]);

    for (int i = 0; i <= atoi(argv[3]); i++) {
        update(&drone, dt, g);
    }

    printf("Final position: (%.2f, %.2f)\n", drone.x, drone.y);
    return 0;
}
