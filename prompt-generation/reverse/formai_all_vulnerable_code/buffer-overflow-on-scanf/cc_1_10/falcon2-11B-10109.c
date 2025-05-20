//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define MAX_ANGLE 45

typedef struct {
    int speed;
    int angle;
} Vehicle;

Vehicle vehicle = {0, 0};

void set_speed(int speed) {
    vehicle.speed = speed;
}

void set_angle(int angle) {
    vehicle.angle = angle;
}

void control_vehicle() {
    int current_speed = vehicle.speed;
    int current_angle = vehicle.angle;

    printf("Current speed: %d\n", current_speed);
    printf("Current angle: %d\n", current_angle);

    int user_input = scanf("%d %d", &current_speed, &current_angle);

    if (user_input == EOF) {
        printf("Invalid input. Exiting...\n");
        exit(0);
    }

    if (current_speed > MAX_SPEED || current_speed < -MAX_SPEED) {
        printf("Speed out of range. Setting speed to %d.\n", MAX_SPEED);
        set_speed(MAX_SPEED);
    }

    if (current_angle > MAX_ANGLE || current_angle < -MAX_ANGLE) {
        printf("Angle out of range. Setting angle to %d.\n", MAX_ANGLE);
        set_angle(MAX_ANGLE);
    }

    printf("Vehicle speed: %d\n", vehicle.speed);
    printf("Vehicle angle: %d\n", vehicle.angle);
}

int main() {
    while (1) {
        control_vehicle();
    }

    return 0;
}