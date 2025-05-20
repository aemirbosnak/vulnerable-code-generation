#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define GRAVITY 9.81

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
} Drone;

void update_drone(Drone *drone) {
    drone->vx += drone->ax * GRAVITY;
    drone->vy += drone->ay * GRAVITY;
    drone->vz += drone->az * GRAVITY;

    drone->x += drone->vx;
    drone->y += drone->vy;
    drone->z += drone->vz;
}

int main(int argc, char *argv[]) {
    int simulations;
    if (argc != 2) {
        printf("Usage: %s <number_of_simulations>\n", argv[0]);
        return 1;
    }
    simulations = atoi(argv[1]);

    Drone drone = {0, 0, 0, 0, GRAVITY, GRAVITY, GRAVITY};

    for (int i = 0; i < simulations; ++i) {
        update_drone(&drone);
        printf("Simulation %d:\nPosition: (%lf, %lf, %lf)\n", i, drone.x, drone.y, drone.z);
    }

    return 0;
}
