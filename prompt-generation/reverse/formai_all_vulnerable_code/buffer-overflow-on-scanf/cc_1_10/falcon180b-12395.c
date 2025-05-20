//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

Vector robot_position;
double robot_speed;

void move_robot(double distance) {
    double delta_x = cos(robot_position.theta) * distance;
    double delta_y = sin(robot_position.theta) * distance;

    robot_position.x += delta_x;
    robot_position.y += delta_y;
}

void turn_robot(double angle) {
    robot_position.theta += angle;
}

int main() {
    robot_position.x = 0.0;
    robot_position.y = 0.0;
    robot_position.theta = 0.0;
    robot_speed = 0.1;

    while (1) {
        printf("Enter command (move, turn, stop): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            printf("Enter distance: ");
            double distance;
            scanf("%lf", &distance);
            move_robot(distance);
        } else if (strcmp(command, "turn") == 0) {
            printf("Enter angle: ");
            double angle;
            scanf("%lf", &angle);
            turn_robot(angle);
        } else if (strcmp(command, "stop") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }

        printf("Robot position: (%lf, %lf)\n", robot_position.x, robot_position.y);
        printf("Robot speed: %lf\n", robot_speed);
    }

    return 0;
}