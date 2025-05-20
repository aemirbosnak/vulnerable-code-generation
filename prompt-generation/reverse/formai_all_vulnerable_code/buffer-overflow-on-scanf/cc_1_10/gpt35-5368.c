//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    float power;
    float angle;
} RCVehicle;

void print_vehicle_position(RCVehicle *vehicle) {
    printf("Vehicle position: (%d, %d)\n", vehicle->position.x, vehicle->position.y);
}

void move_vehicle_forward(RCVehicle *vehicle, float distance) {
    float radians = vehicle->angle * (3.14 / 180);
    int x_change = (int) (cos(radians) * distance);
    int y_change = (int) (sin(radians) * distance);
    vehicle->position.x += x_change;
    vehicle->position.y += y_change;
}

void turn_vehicle_left(RCVehicle *vehicle, float angle) {
    vehicle->angle += angle;
}

void turn_vehicle_right(RCVehicle *vehicle, float angle) {
    vehicle->angle -= angle;
}

int main() {
    RCVehicle vehicle;
    vehicle.power = 0.0;
    vehicle.angle = 0.0;
    vehicle.position.x = 0;
    vehicle.position.y = 0;

    char command[MAX_COMMAND_LENGTH];

    printf("Welcome to the RC vehicle simulation!\n");

    while (1) {
        printf("Enter a command:\n");
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            float distance;
            printf("Enter distance to move forward:\n");
            scanf("%f", &distance);
            move_vehicle_forward(&vehicle, distance);
            print_vehicle_position(&vehicle);
        } else if (strcmp(command, "left") == 0) {
            float angle;
            printf("Enter angle to turn left:\n");
            scanf("%f", &angle);
            turn_vehicle_left(&vehicle, angle);
            printf("Vehicle angle: %f\n", vehicle.angle);
        } else if (strcmp(command, "right") == 0) {
            float angle;
            printf("Enter angle to turn right:\n");
            scanf("%f", &angle);
            turn_vehicle_right(&vehicle, angle);
            printf("Vehicle angle: %f\n", vehicle.angle);
        } else if (strcmp(command, "stop") == 0) {
            printf("Stopping vehicle!\n");
            vehicle.power = 0.0;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}