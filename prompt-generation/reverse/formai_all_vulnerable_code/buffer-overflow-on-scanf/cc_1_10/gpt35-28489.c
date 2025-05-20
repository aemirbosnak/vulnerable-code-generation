//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SPEED 100
#define MAX_STEERING_ANGLE 80

enum Direction {
    FORWARD,
    BACKWARD
};

typedef struct {
    int speed;
    int steering_angle;
    enum Direction direction;
} RCVehicle;

void print_rc_vehicle_status(RCVehicle *vehicle) {
    if(vehicle->direction == FORWARD) {
        printf("Vehicle is moving forward.\n");
    } else {
        printf("Vehicle is moving backward.\n");
    }
    printf("Current speed: %d\n", vehicle->speed);
    printf("Current steering angle: %d degrees\n", vehicle->steering_angle);
}

void change_speed(RCVehicle *vehicle, int new_speed) {
    if(new_speed < 0) {
        printf("Error: Speed must be non-negative\n");
        return;
    }
    if(new_speed > MAX_SPEED) {
        printf("Warning: Speed exceeds maximum limit of %d. Setting to maximum speed.\n", MAX_SPEED);
        vehicle->speed = MAX_SPEED;
    } else {
        vehicle->speed = new_speed;
    }
}

void change_steering_angle(RCVehicle *vehicle, int new_angle) {
    if(new_angle < -MAX_STEERING_ANGLE || new_angle > MAX_STEERING_ANGLE) {
        printf("Error: Invalid steering angle. Must be between %d and %d degrees.\n", -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE);
        return;
    }
    vehicle->steering_angle = new_angle;
}

void change_direction(RCVehicle *vehicle, enum Direction new_direction) {
    vehicle->direction = new_direction;
}

int parse_number(char *input) {
    int i = 0;
    int num = 0;
    while(input[i] != '\0') {
        if(isdigit(input[i])) {
            num = num * 10 + (input[i] - '0');
        } else {
            printf("Invalid input: %s\n", input);
            return -1;
        }
        i++;
    }
    return num;
}

int main() {
    RCVehicle vehicle = {0, 0, FORWARD};
    char input[10];
    while(1) {
        printf("Enter command: ");
        scanf("%s", input);

        if(strcmp(input, "status") == 0) {
            print_rc_vehicle_status(&vehicle);
        } else if(strcmp(input, "speed") == 0) {
            scanf("%s", input);
            int new_speed = parse_number(input);
            if(new_speed != -1) {
                change_speed(&vehicle, new_speed);
            }
        } else if(strcmp(input, "angle") == 0) {
            scanf("%s", input);
            int new_angle = parse_number(input);
            if(new_angle != -1) {
                change_steering_angle(&vehicle, new_angle);
            }
        } else if(strcmp(input, "direction") == 0) {
            scanf("%s", input);
            if(strcmp(input, "forward") == 0) {
                change_direction(&vehicle, FORWARD);
            } else if(strcmp(input, "backward") == 0) {
                change_direction(&vehicle, BACKWARD);
            } else {
                printf("Invalid input: %s\n", input);
            }
        } else if(strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command: %s\n", input);
        }
    }
    return 0;
}