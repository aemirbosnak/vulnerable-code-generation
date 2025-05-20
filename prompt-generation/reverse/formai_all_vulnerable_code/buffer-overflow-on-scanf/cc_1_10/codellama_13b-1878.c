//Code Llama-13B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
// remote_control_vehicle.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

struct vehicle {
    int direction;
    int speed;
};

void move_vehicle(struct vehicle* v, int direction) {
    switch (direction) {
        case LEFT:
            v->direction = LEFT;
            break;
        case RIGHT:
            v->direction = RIGHT;
            break;
        case FORWARD:
            v->direction = FORWARD;
            break;
        case BACKWARD:
            v->direction = BACKWARD;
            break;
        default:
            break;
    }
}

void change_speed(struct vehicle* v, int speed) {
    v->speed = speed;
}

void display_vehicle_info(struct vehicle* v) {
    printf("Vehicle Information:\n");
    printf("Direction: %s\n", (v->direction == LEFT) ? "Left" : (v->direction == RIGHT) ? "Right" : (v->direction == FORWARD) ? "Forward" : "Backward");
    printf("Speed: %d\n", v->speed);
}

int main() {
    struct vehicle v = {.direction = FORWARD, .speed = 0};

    while (1) {
        printf("Enter command (L/R/F/B): ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'L':
                move_vehicle(&v, LEFT);
                break;
            case 'R':
                move_vehicle(&v, RIGHT);
                break;
            case 'F':
                change_speed(&v, v.speed + 1);
                break;
            case 'B':
                change_speed(&v, v.speed - 1);
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        display_vehicle_info(&v);
        sleep(1);
    }

    return 0;
}