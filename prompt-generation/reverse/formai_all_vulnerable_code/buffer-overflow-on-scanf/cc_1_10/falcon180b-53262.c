//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Point;

Point robot;

void move(double distance, double direction) {
    double dx = distance * cos(direction * PI / 180);
    double dy = distance * sin(direction * PI / 180);
    robot.x += dx;
    robot.y += dy;
}

void turn(double angle) {
    robot.theta += angle;
}

void draw() {
    printf("Robot is at (%lf, %lf) facing %lf degrees\n", robot.x, robot.y, robot.theta * 180 / PI);
}

int main() {
    printf("Welcome to the Robot Control Program!\n");
    printf("Commands: move(distance, direction), turn(angle)\n");

    while (1) {
        char command[50];
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            double distance, direction;
            scanf("%lf %lf", &distance, &direction);
            move(distance, direction);
        } else if (strcmp(command, "turn") == 0) {
            double angle;
            scanf("%lf", &angle);
            turn(angle);
        } else if (strcmp(command, "draw") == 0) {
            draw();
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}