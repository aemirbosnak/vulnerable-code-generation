//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 50
#define TURN_RADIUS 100
#define FORWARD_DISTANCE 200
#define BACKWARD_DISTANCE 50
#define LEFT_DISTANCE 200
#define RIGHT_DISTANCE 50

#define UP 'w'
#define DOWN's'
#define LEFT 'a'
#define RIGHT 'd'

int main() {
    char command;
    int speed = MIN_SPEED, turn_radius = TURN_RADIUS;
    int forward_distance = FORWARD_DISTANCE, backward_distance = BACKWARD_DISTANCE;
    int left_distance = LEFT_DISTANCE, right_distance = RIGHT_DISTANCE;

    srand(time(NULL));

    printf("Enter command (w/s/a/d): ");
    scanf("%c", &command);

    while (command!= 'q') {
        switch (command) {
            case UP:
                speed = (speed < MAX_SPEED)? speed + 1 : MAX_SPEED;
                printf("Speed increased to %d\n", speed);
                break;
            case DOWN:
                speed = (speed > MIN_SPEED)? speed - 1 : MIN_SPEED;
                printf("Speed decreased to %d\n", speed);
                break;
            case LEFT:
                turn_radius = (turn_radius < TURN_RADIUS)? turn_radius + 1 : TURN_RADIUS;
                printf("Turn radius increased to %d\n", turn_radius);
                break;
            case RIGHT:
                turn_radius = (turn_radius > MIN_SPEED)? turn_radius - 1 : MIN_SPEED;
                printf("Turn radius decreased to %d\n", turn_radius);
                break;
            default:
                printf("Invalid command\n");
        }

        printf("Enter command (w/s/a/d): ");
        scanf("%c", &command);
    }

    return 0;
}