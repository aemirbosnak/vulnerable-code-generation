#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define GRAVITY 9.81

int main() {
    double initialHeight, velocity, timeStep, maxTime;
    int steps;

    printf("Enter initial height (m): ");
    scanf("%lf", &initialHeight);
    printf("Enter time step (s): ");
    scanf("%lf", &timeStep);
    printf("Enter maximum simulation time (s): ");
    scanf("%lf", &maxTime);

    for (steps = 0; initialHeight > 0 && steps * timeStep <= maxTime; steps++) {
        velocity = -GRAVITY * steps * timeStep;
        initialHeight += velocity * timeStep;
        printf("Time: %.2f s, Height: %.2f m\n", steps * timeStep, initialHeight);
    }

    if (initialHeight <= 0) {
        printf("Drone has hit the ground.\n");
    } else {
        printf("Simulation time limit reached.\n");
    }

    return 0;
}
