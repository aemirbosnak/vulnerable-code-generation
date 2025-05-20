//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

Vector forward(Vector v, double d) {
    Vector u = {v.x + cos(v.theta) * d, v.y + sin(v.theta) * d};
    return u;
}

Vector turn_left(Vector v, double d) {
    Vector u = {v.x - sin(v.theta) * d, v.y + cos(v.theta) * d};
    return u;
}

Vector turn_right(Vector v, double d) {
    Vector u = {v.x + sin(v.theta) * d, v.y - cos(v.theta) * d};
    return u;
}

int main() {
    Vector robot = {0, 0, 0};
    double distance = 0;

    while (distance < 1000) {
        printf("Enter command (f/l/r): ");
        char command = getchar();

        switch (command) {
            case 'f':
                printf("Enter distance: ");
                scanf("%lf", &distance);
                robot = forward(robot, distance);
                break;
            case 'l':
                printf("Enter angle: ");
                scanf("%lf", &distance);
                robot = turn_left(robot, distance);
                break;
            case 'r':
                printf("Enter angle: ");
                scanf("%lf", &distance);
                robot = turn_right(robot, distance);
                break;
            default:
                printf("Invalid command\n");
        }

        printf("Current position: (%lf, %lf, %lf)\n", robot.x, robot.y, robot.theta);
    }

    return 0;
}