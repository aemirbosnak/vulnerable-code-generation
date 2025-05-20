//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    STOP,
    FORWARD,
    BACKWARD,
    TURN_LEFT,
    TURN_RIGHT
} Direction;

typedef struct {
    int x;
    int y;
} Point;

void move_robot(Point *robot, Direction direction, int speed) {
    if (direction == STOP) {
        robot->x = robot->y = 0;
    } else if (direction == FORWARD) {
        robot->x += speed;
        robot->y += speed;
    } else if (direction == BACKWARD) {
        robot->x -= speed;
        robot->y -= speed;
    } else if (direction == TURN_LEFT) {
        robot->x -= speed;
        robot->y += speed;
    } else if (direction == TURN_RIGHT) {
        robot->x += speed;
        robot->y -= speed;
    }
}

int main() {
    Point robot = {0, 0};
    Direction direction = STOP;
    int speed = 1;

    while (true) {
        printf("Enter direction (F/B/L/R/S): ");
        scanf("%s", &direction);

        if (direction == 'S') {
            break;
        }

        move_robot(&robot, direction, speed);

        printf("Robot is at (%d, %d)\n", robot.x, robot.y);
    }

    return 0;
}