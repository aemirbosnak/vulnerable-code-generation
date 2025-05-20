//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define MAX_STEERING_ANGLE 30

typedef struct {
    int speed;
    int steering_angle;
} RemoteVehicle;

void setSpeed(RemoteVehicle *vehicle, int speed) {
    if (speed > MAX_SPEED) {
        printf("Error: Speed cannot be greater than %d\n", MAX_SPEED);
    } else {
        vehicle->speed = speed;
        printf("Speed set to %d\n", speed);
    }
}

void setSteeringAngle(RemoteVehicle *vehicle, int angle) {
    if (angle > MAX_STEERING_ANGLE) {
        printf("Error: Steering angle cannot be greater than %d\n", MAX_STEERING_ANGLE);
    } else {
        vehicle->steering_angle = angle;
        printf("Steering angle set to %d\n", angle);
    }
}

void printStatus(RemoteVehicle *vehicle) {
    printf("Speed: %d\n", vehicle->speed);
    printf("Steering angle: %d\n", vehicle->steering_angle);
}

int main() {
    RemoteVehicle vehicle = {0, 0};

    printf("Welcome to Remote Control Vehicle Simulation!\n\n");

    while (1) {
        printf("Enter a command (speed, steering, status, quit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "speed") == 0) {
            int speed;
            printf("Enter speed (0-%d): ", MAX_SPEED);
            scanf("%d", &speed);
            setSpeed(&vehicle, speed);
        } else if (strcmp(command, "steering") == 0) {
            int angle;
            printf("Enter steering angle (-%d to %d): ", MAX_STEERING_ANGLE, MAX_STEERING_ANGLE);
            scanf("%d", &angle);
            setSteeringAngle(&vehicle, angle);
        } else if (strcmp(command, "status") == 0) {
            printStatus(&vehicle);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}