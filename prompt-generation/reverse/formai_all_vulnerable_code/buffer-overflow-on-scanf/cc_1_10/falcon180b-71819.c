//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

Vector robot;

void move(double distance, double angle) {
    double new_x = robot.x + distance * cos(robot.theta + angle * PI / 180);
    double new_y = robot.y + distance * sin(robot.theta + angle * PI / 180);

    robot.x = new_x;
    robot.y = new_y;

    printf("Robot moved to (%lf, %lf)\n", new_x, new_y);
}

void turn(double angle) {
    robot.theta += angle * PI / 180;

    printf("Robot turned by %lf degrees\n", angle);
}

int main() {
    printf("Welcome to the Robot Movement Control Program!\n\n");

    robot.x = 0;
    robot.y = 0;
    robot.theta = 0;

    while (1) {
        printf("Enter your command (move or turn): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            printf("Enter distance and angle (in degrees): ");
            double distance, angle;
            scanf("%lf %lf", &distance, &angle);

            move(distance, angle);
        } else if (strcmp(command, "turn") == 0) {
            printf("Enter angle (in degrees): ");
            double angle;
            scanf("%lf", &angle);

            turn(angle);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}