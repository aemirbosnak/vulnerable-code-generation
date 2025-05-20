#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.81 // m/s^2
#define MAX_ITERATIONS 1000000
#define MAX_HEIGHT 100.0 // meters
#define MIN_HEIGHT 0.0

typedef struct {
    double height;
    double velocity;
} Drone;

void update_drone(Drone *drone) {
    drone->velocity -= GRAVITY;
    drone->height += drone->velocity;
}

int main() {
    int iterations;
    Drone drone = {0.0, 0.0};
    srand(time(NULL));

    printf("Enter the number of simulations (up to %d): ", MAX_ITERATIONS);
    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        update_drone(&drone);
        if (drone.height > MAX_HEIGHT || drone.height < MIN_HEIGHT) {
            printf("Crash at iteration %d\n", i);
            break;
        }
        if (i % 100 == 0)
            printf("Simulation time: %.2fs\n", i * 1.0 / 1000.0);
    }

    return 0;
}
