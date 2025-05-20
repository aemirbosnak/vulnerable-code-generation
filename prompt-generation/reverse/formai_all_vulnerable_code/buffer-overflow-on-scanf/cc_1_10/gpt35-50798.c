//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: dynamic
#include <stdio.h>
#include <math.h>

#define G 6.67408E-11

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point position;
    Point velocity;
    double mass;
} Body;

void updatePosition(Body *body, double timestep) {
    body->position.x += body->velocity.x * timestep;
    body->position.y += body->velocity.y * timestep;
}

void updateVelocity(Body *body, Body *otherBody, double timestep) {
    double distanceX = otherBody->position.x - body->position.x;
    double distanceY = otherBody->position.y - body->position.y;
    double distance = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
    double force = (G * body->mass * otherBody->mass) / pow(distance, 2);
    double angle = atan2(distanceY, distanceX);
    double acceleration = force / body->mass;
    body->velocity.x += acceleration * cos(angle) * timestep;
    body->velocity.y += acceleration * sin(angle) * timestep;
}

int main() {
    int numberOfBodies;
    printf("Enter number of bodies: ");
    scanf("%d", &numberOfBodies);

    Body bodies[numberOfBodies];

    for (int i = 0; i < numberOfBodies; i++) {
        printf("Enter mass and initial position (x, y) of body %d: ", i + 1);
        scanf("%lf%lf%lf", &bodies[i].mass, &bodies[i].position.x, &bodies[i].position.y);
        printf("Enter initial velocity (x, y) of body %d: ", i + 1);
        scanf("%lf%lf", &bodies[i].velocity.x, &bodies[i].velocity.y);
    }

    int numberOfTimeSteps;
    double timeStep;
    printf("Enter number of time steps and time step size (in seconds): ");
    scanf("%d%lf", &numberOfTimeSteps, &timeStep);

    for (int i = 0; i < numberOfTimeSteps; i++) {
        printf("\n--- Time step %d ---\n", i + 1);
        for (int j = 0; j < numberOfBodies; j++) {
            printf("Body %d:\n", j + 1);
            printf("Position = (%lf, %lf)\n", bodies[j].position.x, bodies[j].position.y);
            printf("Velocity = (%lf, %lf)\n", bodies[j].velocity.x, bodies[j].velocity.y);

            for (int k = 0; k < numberOfBodies; k++) {
                if (j == k) continue;
                updateVelocity(&bodies[j], &bodies[k], timeStep);
            }
            updatePosition(&bodies[j], timeStep);

            printf("New position = (%lf, %lf)\n", bodies[j].position.x, bodies[j].position.y);
            printf("New velocity = (%lf, %lf)\n", bodies[j].velocity.x, bodies[j].velocity.y);
        }
    }

    return 0;
}