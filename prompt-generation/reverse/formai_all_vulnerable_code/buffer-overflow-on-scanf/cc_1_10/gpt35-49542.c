//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 50
#define MAX_ANGLE 90

typedef struct {
    int x;
    int y;
} coordinates;

typedef struct {
    int speed;
    int angle;
} rc_data;

coordinates move_forward(coordinates current_location, rc_data control_data) {
    coordinates new_location;
    int distance = control_data.speed; // distance is the same as speed in this simulation
    
    new_location.x = current_location.x + (distance * cos(control_data.angle));
    new_location.y = current_location.y + (distance * sin(control_data.angle));

    return new_location;
}

int main() {
    coordinates location = {0, 0};
    rc_data control = {0, 0};
    char input;

    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("You are currently at %d,%d\n", location.x, location.y);

    while (1) {
        printf("\nChoose an action:\n");
        printf("f = increase speed\n");
        printf("s = decrease speed\n");
        printf("r = turn right\n");
        printf("l = turn left\n");
        printf("m = move forward\n");
        printf("q = quit\n");
        scanf(" %c", &input);

        if (input == 'f') {
            if (control.speed < MAX_SPEED) {
                control.speed++;
                printf("Speed increased to %d\n", control.speed);
            } else {
                printf("Already at maximum speed of %d\n", MAX_SPEED);
            }
        } else if (input == 's') {
            if (control.speed > 0) {
                control.speed--;
                printf("Speed decreased to %d\n", control.speed);
            } else {
                printf("Already stopped\n");
            }
        } else if (input == 'r') {
            if (control.angle < MAX_ANGLE) {
                control.angle++;
                printf("Turned right to %d degrees\n", control.angle);
            } else {
                printf("Already at maximum angle of %d degrees\n", MAX_ANGLE);
            }
        } else if (input == 'l') {
            if (control.angle > -MAX_ANGLE) {
                control.angle--;
                printf("Turned left to %d degrees\n", control.angle);
            } else {
                printf("Already at minimum angle of -%d degrees\n", MAX_ANGLE);
            }
        } else if (input == 'm') {
            location = move_forward(location, control);
            printf("Moved forward to %d,%d\n", location.x, location.y);
        } else if (input == 'q') {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid input\n");
        }
    }
    return 0;
}