#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIMULATIONS 2147483647

void flyDrone(int simulation) {
    float altitude = 0.0;
    float speed = 10.0;
    float climbRate = 1.0;

    for (int i = 0; i < simulation; i++) {
        altitude += climbRate * speed;
        printf("Simulation %d: Altitude %.2f\n", i, altitude);
    }
}

int main() {
    flyDrone(MAX_SIMULATIONS * MAX_SIMULATIONS);
    return 0;
}
