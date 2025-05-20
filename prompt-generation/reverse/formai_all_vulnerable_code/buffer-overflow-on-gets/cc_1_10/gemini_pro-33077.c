//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

typedef struct {
    int x;
    int y;
    int direction;
} Robot;

void turn_left(Robot *robot) {
    robot->direction = (robot->direction + 3) % 4;
}

void turn_right(Robot *robot) {
    robot->direction = (robot->direction + 1) % 4;
}

void move_forward(Robot *robot) {
    switch (robot->direction) {
        case NORTH:
            robot->y--;
            break;
        case EAST:
            robot->x++;
            break;
        case SOUTH:
            robot->y++;
            break;
        case WEST:
            robot->x--;
            break;
    }
}

void move_backward(Robot *robot) {
    switch (robot->direction) {
        case NORTH:
            robot->y++;
            break;
        case EAST:
            robot->x--;
            break;
        case SOUTH:
            robot->y--;
            break;
        case WEST:
            robot->x++;
            break;
    }
}

bool is_outside_boundary(Robot *robot) {
    return robot->x < 0 || robot->x >= MAX_WIDTH || robot->y < 0 || robot->y >= MAX_HEIGHT;
}

int main() {
    Robot robot = {0, 0, NORTH};

    char commands[100];
    gets(commands);

    for (int i = 0; i < strlen(commands); i++) {
        switch (commands[i]) {
            case 'L':
                turn_left(&robot);
                break;
            case 'R':
                turn_right(&robot);
                break;
            case 'F':
                move_forward(&robot);
                break;
            case 'B':
                move_backward(&robot);
                break;
        }

        if (is_outside_boundary(&robot)) {
            printf("Robot is outside the boundary!\n");
            break;
        }
    }

    printf("Robot is at (%d, %d), facing %s.\n", robot.x, robot.y, robot.direction == NORTH ? "North" : robot.direction == EAST ? "East" : robot.direction == SOUTH ? "South" : "West");

    return 0;
}