//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_STEER_ANGLE 45
#define MIN_STEER_ANGLE -45

typedef struct remote_control_vehicle_t {
    int speed;
    int steer_angle;
    int is_on;
} RemoteControlVehicle;

void print_vehicle_status(RemoteControlVehicle* vehicle) {
    printf("Vehicle is ");
    if(vehicle->is_on) {
        printf("on, ");
    } else {
        printf("off, ");
    }
    printf("speed: %d, ", vehicle->speed);
    printf("steer angle: %d\n", vehicle->steer_angle);
}

int main() {
    RemoteControlVehicle vehicle = {
        .speed = 0,
        .steer_angle = 0,
        .is_on = 0
    };

    printf("Welcome to the remote control vehicle simulator!\n");
    printf("Press 'w' to increase speed, 's' to decrease speed\n");
    printf("Press 'a' to steer left, 'd' to steer right\n");
    printf("Press 'p' to turn the vehicle on or off\n");

    char input[2];

    while(1) {
        printf("Enter command: ");
        scanf("%s", input);

        if(strcmp(input, "w") == 0) {
            if(vehicle.speed < MAX_SPEED) {
                vehicle.speed++;
            }
        } else if(strcmp(input, "s") == 0) {
            if(vehicle.speed > MIN_SPEED) {
                vehicle.speed--;
            }
        } else if(strcmp(input, "a") == 0) {
            if(vehicle.steer_angle > MIN_STEER_ANGLE) {
                vehicle.steer_angle--;
            }
        } else if(strcmp(input, "d") == 0) {
            if(vehicle.steer_angle < MAX_STEER_ANGLE) {
                vehicle.steer_angle++;
            }
        } else if(strcmp(input, "p") == 0) {
            vehicle.is_on = !vehicle.is_on;
        } else {
            printf("Invalid command\n");
            continue;
        }

        print_vehicle_status(&vehicle);
    }

    return 0;
}