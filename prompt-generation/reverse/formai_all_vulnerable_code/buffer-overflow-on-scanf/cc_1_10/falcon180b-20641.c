//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define PI 3.14159265358979323846
#define G 9.81

// Define struct for drone position and velocity
typedef struct {
    double x, y, z;
    double vx, vy, vz;
} Drone;

// Function to initialize the drone position and velocity
void initDrone(Drone* drone) {
    drone->x = 0.0;
    drone->y = 0.0;
    drone->z = 0.0;
    drone->vx = 0.0;
    drone->vy = 0.0;
    drone->vz = 0.0;
}

// Function to update the drone position and velocity based on user input
void updateDrone(Drone* drone, double dt) {
    // Get user input for desired velocity
    double desiredVx, desiredVy, desiredVz;
    printf("Enter desired velocity (m/s):\n");
    scanf("%lf %lf %lf", &desiredVx, &desiredVy, &desiredVz);

    // Calculate acceleration based on desired velocity
    double ax, ay, az;
    ax = desiredVx - drone->vx;
    ay = desiredVy - drone->vy;
    az = desiredVz - drone->vz;

    // Apply gravity acceleration
    ax += G * sin(drone->z) * cos(drone->z);
    ay += G * sin(drone->z) * sin(drone->z);
    az += -G * cos(drone->z);

    // Update velocity and position
    drone->vx += ax * dt;
    drone->vy += ay * dt;
    drone->vz += az * dt;
    drone->x += drone->vx * dt;
    drone->y += drone->vy * dt;
    drone->z += drone->vz * dt;
}

// Function to print the current drone position and velocity
void printDrone(Drone* drone) {
    printf("Current position: (%lf, %lf, %lf)\n", drone->x, drone->y, drone->z);
    printf("Current velocity: (%lf, %lf, %lf)\n", drone->vx, drone->vy, drone->vz);
}

int main() {
    Drone drone;
    initDrone(&drone);

    double dt = 0.01; // Time step in seconds

    while (1) {
        updateDrone(&drone, dt);
        printDrone(&drone);
        printf("Enter 'q' to quit:\n");
        char input;
        scanf(" %c", &input);
        if (input == 'q') {
            break;
        }
    }

    return 0;
}