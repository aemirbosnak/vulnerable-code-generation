#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.81 // m/s^2
#define MAX_TIME 10.0 // s

typedef struct {
    double x, y, vx, vy;
} Drone;

void update_drone(Drone *drone) {
    drone->vx += 0; // wind speed (you can add this if needed)
    drone->vy -= GRAVITY;
    drone->x += drone->vx;
    drone->y += drone->vy;
}

int main() {
    int simulations;
    printf("Enter the number of simulations: ");
    scanf("%d", &simulations);

    for (int i = 0; i < simulations; ++i) {
        Drone drone = {0, 10.0, 1.0, 0.0}; // initial position (x, y), initial velocity (vx, vy)
        double time = 0.0;
        double crash_time = -1.0;

        while (time < MAX_TIME && crash_time < 0) {
            update_drone(&drone);
            time += 0.1; // time step

            if (drone.y <= 0) {
                crash_time = time;
            }
        }

        printf("Simulation %d: Drone crashed at time %.2f seconds\n", i + 1, crash_time);
    }

    return 0;
}
