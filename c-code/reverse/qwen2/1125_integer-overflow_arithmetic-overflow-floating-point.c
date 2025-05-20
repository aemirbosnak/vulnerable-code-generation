#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIMULATION_COUNT 100000

typedef struct {
    double x;
    double y;
    double z;
} Position;

void simulateDroneFlight(int count, double timeStep) {
    if (count <= 0 || count > MAX_SIMULATION_COUNT) {
        fprintf(stderr, "Error: Simulation count must be between 1 and %d.\n", MAX_SIMULATION_COUNT);
        return;
    }

    if (timeStep <= 0) {
        fprintf(stderr, "Error: Time step must be greater than 0.\n");
        return;
    }

    Position currentPosition = {0.0, 0.0, 0.0};
    for (int i = 0; i < count; ++i) {
        // Simulate drone movement here
        // Example: currentPosition.x += someValue * timeStep;
        // Ensure to check for integer overflow in position updates
        printf("Simulation %d: Position at time %.2f is (%.2f, %.2f, %.2f)\n", i + 1, i * timeStep, currentPosition.x, currentPosition.y, currentPosition.z);
    }
}

int main() {
    int count;
    double timeStep;

    printf("Enter the number of simulations: ");
    if (scanf("%d", &count) != 1) {
        fprintf(stderr, "Error: Invalid input for simulation count.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the time step: ");
    if (scanf("%lf", &timeStep) != 1) {
        fprintf(stderr, "Error: Invalid input for time step.\n");
        return EXIT_FAILURE;
    }

    simulateDroneFlight(count, timeStep);

    return EXIT_SUCCESS;
}
