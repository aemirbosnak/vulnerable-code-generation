//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define G 6.67430e-11

// Structs
typedef struct {
    double x, y;
} Vector2;

typedef struct {
    Vector2 position, velocity, force;
    double mass;
} Body;

// Functions
void calculateForces(Body *bodies, int numBodies) {
    for (int i = 0; i < numBodies; i++) {
        bodies[i].force.x = 0;
        bodies[i].force.y = 0;

        for (int j = 0; j < numBodies; j++) {
            if (i == j) continue;

            Vector2 direction;
            direction.x = bodies[j].position.x - bodies[i].position.x;
            direction.y = bodies[j].position.y - bodies[i].position.y;

            double distance = sqrt(direction.x * direction.x + direction.y * direction.y);

            double magnitude = G * bodies[j].mass / (distance * distance);

            bodies[i].force.x += magnitude * direction.x / distance;
            bodies[i].force.y += magnitude * direction.y / distance;
        }
    }
}

void updatePositions(Body *bodies, int numBodies, double deltaTime) {
    for (int i = 0; i < numBodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * deltaTime + 0.5 * bodies[i].force.x * deltaTime * deltaTime / bodies[i].mass;
        bodies[i].position.y += bodies[i].velocity.y * deltaTime + 0.5 * bodies[i].force.y * deltaTime * deltaTime / bodies[i].mass;
    }
}

void updateVelocities(Body *bodies, int numBodies, double deltaTime) {
    for (int i = 0; i < numBodies; i++) {
        bodies[i].velocity.x += 0.5 * (bodies[i].force.x + bodies[i].force.x) * deltaTime / bodies[i].mass;
        bodies[i].velocity.y += 0.5 * (bodies[i].force.y + bodies[i].force.y) * deltaTime / bodies[i].mass;
    }
}

int main() {
    // Handle input
    int numBodies;
    printf("How many bodies? ");
    scanf("%d", &numBodies);

    // Initialize bodies
    Body *bodies = malloc(numBodies * sizeof(Body));
    for (int i = 0; i < numBodies; i++) {
        printf("Body %d:\n", i + 1);

        printf("\tPosition: ");
        scanf("%lf %lf", &bodies[i].position.x, &bodies[i].position.y);

        printf("\tVelocity: ");
        scanf("%lf %lf", &bodies[i].velocity.x, &bodies[i].velocity.y);

        printf("\tMass: ");
        scanf("%lf", &bodies[i].mass);
    }

    // Simulation loop
    double deltaTime = 0.01; // 10ms
    int numSteps = 1000; // 10s
    for (int step = 0; step < numSteps; step++) {
        calculateForces(bodies, numBodies);
        updatePositions(bodies, numBodies, deltaTime);
        updateVelocities(bodies, numBodies, deltaTime);

        // Print step information
        printf("Step %d:\n", step + 1);
        for (int i = 0; i < numBodies; i++) {
            printf("\tBody %d: (%lf, %lf)\n", i + 1, bodies[i].position.x, bodies[i].position.y);
        }
    }

    free(bodies);
    return 0;
}