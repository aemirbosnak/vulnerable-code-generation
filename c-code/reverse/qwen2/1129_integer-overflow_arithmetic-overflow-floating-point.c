#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_TIME 1000
#define DT 0.1

typedef struct {
    double x, y, z;
} Vector3D;

void updatePosition(Vector3D *pos, Vector3D *vel, double dt) {
    pos->x += vel->x * dt;
    pos->y += vel->y * dt;
    pos->z += vel->z * dt;
}

void updateVelocity(Vector3D *vel, double ax, double ay, double az, double dt) {
    vel->x += ax * dt;
    vel->y += ay * dt;
    vel->z += az * dt;
}

int main() {
    int num_simulations = 5;
    for (int sim = 0; sim < num_simulations; sim++) {
        Vector3D pos = {0, 0, 100};
        Vector3D vel = {0, 0, -10};
        Vector3D acc = {0, 0, -9.8};

        for (int t = 0; t < MAX_TIME; t++) {
            if (pos.z <= 0) {
                printf("Simulation %d: Crash at time %f\n", sim, t * DT);
                break;
            }
            updatePosition(&pos, &vel, DT);
            updateVelocity(&vel, acc.x, acc.y, acc.z, DT);
        }
    }
    return 0;
}
