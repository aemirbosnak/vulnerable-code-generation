//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
#define WHEEL_BASE 0.25
#define WHEEL_RADIUS 0.05

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point front_left, front_right, back_left, back_right;
} Robot;

void move(Robot *robot, double distance, double direction) {
    double wheel_distance = distance / (2 * PI * WHEEL_RADIUS);
    double left_speed = cos(direction) * wheel_distance;
    double right_speed = sin(direction) * wheel_distance;

    robot->front_left.x += left_speed;
    robot->front_right.x += right_speed;
    robot->back_left.x += left_speed;
    robot->back_right.x += right_speed;
}

void turn(Robot *robot, double angle) {
    double wheel_angle = angle / (2 * PI * WHEEL_RADIUS);

    robot->front_left.y += sin(wheel_angle);
    robot->front_right.y += cos(wheel_angle);
    robot->back_left.y += sin(wheel_angle);
    robot->back_right.y += cos(wheel_angle);
}

int main() {
    Robot robot = {
        {0, 0},
        {WHEEL_BASE, 0},
        {-WHEEL_BASE, 0},
        {0, 0}
    };

    printf("Sherlock Holmes' Robot Control Program\n");
    printf("Enter commands in the format: move distance direction\n");
    printf("or turn angle\n");

    while (1) {
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            double distance, direction;
            scanf("%lf %lf", &distance, &direction);
            move(&robot, distance, direction);
        } else if (strcmp(command, "turn") == 0) {
            double angle;
            scanf("%lf", &angle);
            turn(&robot, angle);
        }
    }

    return 0;
}