//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Drone constants
#define MAX_ALTITUDE 1000
#define MAX_SPEED 50
#define MAX_TILT_ANGLE 45

// Drone state
typedef struct {
    double altitude;
    double speed;
    double tilt_angle;
} DroneState;

// Remote control functions
void ascend(DroneState *drone, double amount) {
    drone->altitude += amount;
    if (drone->altitude > MAX_ALTITUDE) {
        drone->altitude = MAX_ALTITUDE;
    }
}

void descend(DroneState *drone, double amount) {
    drone->altitude -= amount;
    if (drone->altitude < 0) {
        drone->altitude = 0;
    }
}

void accelerate(DroneState *drone, double amount) {
    drone->speed += amount;
    if (drone->speed > MAX_SPEED) {
        drone->speed = MAX_SPEED;
    }
}

void decelerate(DroneState *drone, double amount) {
    drone->speed -= amount;
    if (drone->speed < 0) {
        drone->speed = 0;
    }
}

void tilt_up(DroneState *drone, double amount) {
    drone->tilt_angle += amount;
    if (drone->tilt_angle > MAX_TILT_ANGLE) {
        drone->tilt_angle = MAX_TILT_ANGLE;
    }
}

void tilt_down(DroneState *drone, double amount) {
    drone->tilt_angle -= amount;
    if (drone->tilt_angle < -MAX_TILT_ANGLE) {
        drone->tilt_angle = -MAX_TILT_ANGLE;
    }
}

// Main function
int main(void) {
    // Initialize drone state
    DroneState drone = {0, 0, 0};

    // Get remote control input
    while (true) {
        printf("Enter command: ");
        char command;
        double amount;
        scanf(" %c %lf", &command, &amount);

        // Execute command
        switch (command) {
            case 'a':
                accelerate(&drone, amount);
                break;
            case 'd':
                decelerate(&drone, amount);
                break;
            case 'w':
                ascend(&drone, amount);
                break;
            case 's':
                descend(&drone, amount);
                break;
            case 'e':
                tilt_up(&drone, amount);
                break;
            case 'q':
                tilt_down(&drone, amount);
                break;
            case 'x':
                return 0;
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        // Print drone state
        printf("Altitude: %.2f\n", drone.altitude);
        printf("Speed: %.2f\n", drone.speed);
        printf("Tilt angle: %.2f\n", drone.tilt_angle);
    }

    return 0;
}