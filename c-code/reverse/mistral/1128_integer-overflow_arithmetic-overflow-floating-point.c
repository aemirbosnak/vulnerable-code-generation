#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIMULATIONS 2147483647

typedef struct {
    double x, y, z, vx, vy, vz;
} Drone;

void update_drone(Drone *drone, double dt) {
    drone->vx += 1.0;
    drone->vy += 1.0;
    drone->vz += 1.0;
    drone->x += drone->vx * dt;
    drone->y += drone->vy * dt;
    drone->z += drone->vz * dt;
}

int main() {
    srand(time(NULL));
    Drone drone = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double dt = 0.01;

    int simulations;
    printf("Enter the number of simulations: ");
    scanf("%d", &simulations);

    for (int i = 0; i < simulations; ++i) {
        update_drone(&drone, dt);
    }

    printf("Drone position after %d simulations:\n", simulations);
    printf("x: %.2f, y: %.2f, z: %.2f\n", drone.x, drone.y, drone.z);

    return 0;
}
