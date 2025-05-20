//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MAX_STEERING_ANGLE 45

typedef struct {
    int speed;
    int steering_angle;
    bool engine_on;
} RC_vehicle;

void print_instructions() {
    printf("RC Vehicle Simulation\n");
    printf("Commands:\n");
    printf("  engine on\n");
    printf("  engine off\n");
    printf("  turn left X (X is between 0-45)\n");
    printf("  turn right X (X is between 0-45)\n");
    printf("  accelerate X (X is between 0-100)\n");
    printf("  brake\n");
    printf("  status\n");
    printf("  q or quit\n");
}

void print_status(RC_vehicle vehicle) {
    printf("RC Vehicle Status: \n");
    printf("  Engine: %s \n", (vehicle.engine_on) ? "On" : "Off");
    printf("  Speed: %d%%\n", vehicle.speed);
    printf("  Steering Angle: %d degrees\n", vehicle.steering_angle);
}

int main() {
    RC_vehicle vehicle = {0, 0, false};
    print_instructions();
    char command[20];
    bool quit = false;
    while (!quit) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "q") == 0 || strcmp(command, "quit") == 0) {
            quit = true;
        } else if (strcmp(command, "engine") == 0) {
            scanf("%s", command);
            if (strcmp(command, "on") == 0) {
                vehicle.engine_on = true;
            } else if (strcmp(command, "off") == 0) {
                vehicle.engine_on = false;
            } else {
                printf("Unknown command: %s %s\n", "engine", command);
                print_instructions();
            }
        } else if (strcmp(command, "turn") == 0) {
            int angle;
            scanf("%s %d", command, &angle);
            if (angle < 0 || angle > MAX_STEERING_ANGLE) {
                printf("Invalid steering angle: %d\n", angle);
            } else {
                if (strcmp(command, "left") == 0) {
                    vehicle.steering_angle = -angle;
                } else if (strcmp(command, "right") == 0) {
                    vehicle.steering_angle = angle;
                } else {
                    printf("Unknown command: %s %d\n", "turn", angle);
                    print_instructions();
                }
            }
        } else if (strcmp(command, "accelerate") == 0) {
            int speed;
            scanf("%d", &speed);
            if (speed < 0 || speed > MAX_SPEED) {
                printf("Invalid speed: %d\n", speed);
            } else {
                vehicle.speed = speed;
            }
        } else if (strcmp(command, "brake") == 0) {
            vehicle.speed = 0;
        } else if (strcmp(command, "status") == 0) {
            print_status(vehicle);
        } else {
            printf("Unknown command: %s\n", command);
            print_instructions();
        }
    }
    return 0;
}