//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define GRAVITY 9.81

typedef struct {
    double x, y, z;
} Vector3D;

typedef struct {
    double roll, pitch, yaw;
} EulerAngles;

typedef struct {
    double forward, backward, left, right;
} Throttle;

void init_drone() {
    printf("Initializing drone...\n");
    printf("Drone initialized successfully!\n");
}

int main() {
    init_drone();

    while (1) {
        printf("Enter command (up, down, left, right, forward, backward, left_turn, right_turn, hover, land, exit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "up") == 0) {
            printf("Drone is flying up!\n");
        } else if (strcmp(command, "down") == 0) {
            printf("Drone is flying down!\n");
        } else if (strcmp(command, "left") == 0) {
            printf("Drone is flying left!\n");
        } else if (strcmp(command, "right") == 0) {
            printf("Drone is flying right!\n");
        } else if (strcmp(command, "forward") == 0) {
            printf("Drone is flying forward!\n");
        } else if (strcmp(command, "backward") == 0) {
            printf("Drone is flying backward!\n");
        } else if (strcmp(command, "left_turn") == 0) {
            printf("Drone is turning left!\n");
        } else if (strcmp(command, "right_turn") == 0) {
            printf("Drone is turning right!\n");
        } else if (strcmp(command, "hover") == 0) {
            printf("Drone is hovering!\n");
        } else if (strcmp(command, "land") == 0) {
            printf("Drone is landing!\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}