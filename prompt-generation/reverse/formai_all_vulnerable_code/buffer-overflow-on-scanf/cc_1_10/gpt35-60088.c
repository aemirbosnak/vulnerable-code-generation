//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

typedef struct Body {
    double mass;
    double position[3];
    double velocity[3];
} Body;

int main() {
    int numBodies;
    
    printf("Enter number of bodies to simulate: ");
    scanf("%d", &numBodies);

    Body* bodies = (Body*) malloc(numBodies * sizeof(Body));

    // initialize body properties
    for (int i = 0; i < numBodies; i++) {
        printf("\nEnter the mass, position and velocity of body #%d\n", i+1);
        printf("\nMass (in kg): ");
        scanf("%lf", &bodies[i].mass);
        
        printf("\nPosition (in meters): ");
        scanf("%lf %lf %lf", &bodies[i].position[0], &bodies[i].position[1], &bodies[i].position[2]);
        
        printf("\nVelocity (in m/s): ");
        scanf("%lf %lf %lf", &bodies[i].velocity[0], &bodies[i].velocity[1], &bodies[i].velocity[2]);
    }
    
    double timeStep;
    printf("\nEnter time step for simulation (in seconds): ");
    scanf("%lf", &timeStep);

    double endTime;
    printf("\nEnter end time for simulation (in seconds): ");
    scanf("%lf", &endTime);
    
    int numSteps = (int) (endTime / timeStep);
    printf("\nSimulation will run for %d steps.\n", numSteps);

    // run simulation
    for (int step = 1; step <= numSteps; step++) {
        for (int i = 0; i < numBodies; i++) {
            double netForce[3] = { 0.0, 0.0, 0.0 };
            
            for (int j = 0; j < numBodies; j++) {
                if (i != j) {
                    double distance = sqrt(pow(bodies[j].position[0] - bodies[i].position[0], 2.0)
                                           + pow(bodies[j].position[1] - bodies[i].position[1], 2.0)
                                           + pow(bodies[j].position[2] - bodies[i].position[2], 2.0));
                    double forceMagnitude = G * bodies[i].mass * bodies[j].mass / pow(distance, 2.0);
                    double forceDirection[3] = { (bodies[j].position[0] - bodies[i].position[0]) / distance,
                                                 (bodies[j].position[1] - bodies[i].position[1]) / distance,
                                                 (bodies[j].position[2] - bodies[i].position[2]) / distance };
                    
                    netForce[0] += forceMagnitude * forceDirection[0];
                    netForce[1] += forceMagnitude * forceDirection[1];
                    netForce[2] += forceMagnitude * forceDirection[2];
                }
            }
            
            double acceleration[3] = { netForce[0] / bodies[i].mass,
                                        netForce[1] / bodies[i].mass,
                                        netForce[2] / bodies[i].mass };
            
            // update position and velocity using forward Euler integration
            for (int k = 0; k < 3; k++) {
                bodies[i].position[k] += bodies[i].velocity[k] * timeStep;
                bodies[i].velocity[k] += acceleration[k] * timeStep;
            }
        }
    }
    
    // print final state of all bodies
    printf("\nFinal state of all bodies:\n\n");
    for (int i = 0; i < numBodies; i++) {
        printf("Body #%d:\n", i+1);
        printf("Mass: %lf kg\n", bodies[i].mass);
        printf("Position: (%lf, %lf, %lf) m\n", bodies[i].position[0], bodies[i].position[1], bodies[i].position[2]);
        printf("Velocity: (%lf, %lf, %lf) m/s\n", bodies[i].velocity[0], bodies[i].velocity[1], bodies[i].velocity[2]);
    }
    
    free(bodies);
    return 0;
}