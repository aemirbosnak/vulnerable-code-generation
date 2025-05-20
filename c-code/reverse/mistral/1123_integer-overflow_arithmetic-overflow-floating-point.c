#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.81 // m/s^2
#define WIND_SPEED 2.0 // m/s

typedef struct {
    double x, y, vx, vy;
} Drone;

void update_drone(Drone *drone, double dt) {
    drone->vx += (WIND_SPEED - drone->vy) * dt;
    drone->vy -= GRAVITY * dt;
    drone->x += drone->vx * dt;
    drone->y += drone->vy * dt;
}

int main() {
    int simulation_count, i;
    double initial_x, initial_y, initial_vx, initial_vy, dt, max_time;
    scanf("%lf %lf %lf %lf %lf %lf %d %lf", &initial_x, &initial_y, &initial_vx, &initial_vy, &dt, &max_time, &simulation_count);

    Drone drone = {initial_x, initial_y, initial_vx, initial_vy};
    double current_time = 0;

    for (i = 0; i < simulation_count || current_time < max_time; ++i) {
        update_drone(&drone, dt);
        current_time += dt;

        if (drone.y <= 0) {
            printf("Drone crashed at time %lf\n", current_time);
            break;
        }
    }

    printf("Drone final position: (%.2f, %.2f)\n", drone.x, drone.y);

    return 0;
}
