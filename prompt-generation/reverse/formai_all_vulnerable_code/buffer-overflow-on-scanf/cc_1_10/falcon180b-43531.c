//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double angle;
    double speed;
} Movement;

void move(Point* robot, Movement* movement) {
    double distance = movement->speed * movement->angle;
    robot->x += cos(movement->angle) * distance;
    robot->y += sin(movement->angle) * distance;
}

int main() {
    Point robot;
    robot.x = 0;
    robot.y = 0;

    Movement movement;
    movement.angle = 0;
    movement.speed = 1;

    while (1) {
        printf("Current position: (%lf, %lf)\n", robot.x, robot.y);
        printf("Enter command (f for forward, b for backward, l for left, r for right, q to quit): ");
        char command;
        scanf("%c", &command);

        if (command == 'f') {
            movement.angle = 0;
        } else if (command == 'b') {
            movement.angle = PI;
        } else if (command == 'l') {
            movement.angle = -PI / 2;
        } else if (command == 'r') {
            movement.angle = PI / 2;
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command\n");
        }

        move(&robot, &movement);
        printf("Current position: (%lf, %lf)\n", robot.x, robot.y);
    }

    return 0;
}